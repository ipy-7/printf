#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * convert - converts a number from base 10 to the specified base
 *
 * @num: the number to convert
 * @base: the new base to convert to
 * @flags: conversion flags
 * @params: pointer to flag values
 * Return: number of characters written to stdout
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	char sign, *ptr;
	static char buffer[50], *arr;
	unsigned long x;
	(void)params;
	sign = 0;
	x = num;
	ptr = &buffer[49];

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		sign = '-';
	}

	*ptr = '\0';
	arr = (flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "012345679ABCDEF");

	if (!x)
		*--ptr = '0';

	while (x)
	{
		*--ptr = arr[x % base];
		x /= base;
	}

	if (sign)
	{
		*--ptr = sign;
	}

	return (ptr);
}

/**
 * print_unsigned - prints an unsigned number
 * @ap: the number as a string
 * @params: pointer to params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long x;

	if (params->l_modifier)
		x = va_arg(ap, unsigned long);
	else if (params->h_modifier)
		x = va_arg(ap, int);
	else
		x = va_arg(ap, unsigned int);

	params->unsign = 1;
	return (print_number(convert(x, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints an address to stdout
 * @ap: the number as a string
 * @params: pointer to params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long x;
	char *s;

	x = va_arg(ap, unsigned long int);

	if (!x)
		return (_puts("(nil)"));

	s = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--s = 'x';
	*--s = '0';

	return (print_number(s, params));
}
