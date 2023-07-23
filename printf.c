#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * _print - writes to stdout
 * @s: the string to be written
 * Return: number of characters written to stdout
 */
int _print(char *s)
{
	if (s == NULL)
		return (0);

	write(1, s, strlen(s));
	return (strlen(s));
}

/**
 * _printC - same as _print but writes a single character
 * @c: the character to be written
 * Return: Always 1 (character length)
 */
int _printC(int c)
{
	write(1, (char)c, 1);
	return (1);
}

/**
 * _printf - prints to stdout
 * @str: the string to be printed
 * Return: the number of characters printed to stdout
 */
int _printf(const char *format, ...)
{
	unsigned int len, i, ret;
	va_list ap;
	char *buff;

	if (format == NULL)
		return (0);

	len = strlen(format);
	ret = 0;
	va_start(ap, format);
	for (i = 0; i < len; i++)
	{
		if (format[i] != '%')
		{
			ret += _printC(format[i]);
			continue;
		}

		switch (format[i + 1])
		{
			case 'c':
				_printC(va_arg(ap, int));
		};
	}

	return (ret);
}
