#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_hex - prints a number in hexadecimal form
 *
 * @ap: the list pointer
 * @params: the flag values
 * Return: number of characters written to stdout
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long x;
	char *s;

	if (params->l_modifier)
		x = va_arg(ap, unsigned long);
	else if (params->h_modifier)
		x = va_arg(ap, unsigned short int);
	else
		x = va_arg(ap, unsigned int);

	s = convert(x, 16, CONVERT_LOWERCASE | CONVERT_UNSIGNED, params);
	if (params->hashtag_flag)
	{
		*--s = 'x';
		*--s = '0';
	}

	params->unsign = 1;
	return (print_number(s, params));
}

/**
 * print_HEX - prints a number in hexadecimal form (capital letters)
 *
 * @ap: the list pointer
 * @params: the flag values
 * Return: number of characters written to stdout
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long x;
	char *s;

	if (params->l_modifier)
		x = va_arg(ap, unsigned long);
	else if (params->h_modifier)
		x = va_arg(ap, unsigned short int);
	else
		x = va_arg(ap, unsigned int);

	s = convert(x, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && x)
	{
		*--s = 'X';
		*--s = '0';
	}

	params->unsign = 1;
	return (print_number(s, params));
}

/**
 * print_binary - prints a number in binary form
 *
 * @ap: the argument list pointer
 * @params: the flag values
 * Return: number of chatacters written to stdout
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int x;
	char *s;

	x = va_arg(ap, unsigned int);
	s = convert(x, 2, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && x)
		*--s = '0';

	params->unsign = 1;
	return (print_number(s, params));
}

/**
 * print_octal - prints a number in octal form
 *
 * @ap: the argument list pointer
 * @params: the flag values
 * Return: number of chatacters written to stdout
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned int x;
	char *s;

	x = va_arg(ap, unsigned int);
	s = convert(x, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && x)
		*--s = '0';

	params->unsign = 1;
	return (print_number(s, params));
}
