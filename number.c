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
    char *s, *arr, buffer[50], sign;
    unsigned long i, x;
    (void)params;
    sign = 0;
    x = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        x = -num;
        sign = '-';
    }

    arr = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
    buffer[49] = '\0';
    i = 48;

    while (x)
    {
        buffer[i] = x % base;
        x /= base;
        i--;
    }

    if (sign)
    {
        buffer[i--] = sign;
    }

    return (&buffer[i + 1]);
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
        x = va_arg(ap, unsigned short int);
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

    x = va_arg(ap, unsigned long int);
    char *s;

    if (!x)
        return (_puts("(nil)"));

    s = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
    *--s = 'x';
    *--s = '0';

    return (print_number(s, params));
}
