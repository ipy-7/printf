#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * _print - writes to stdout
 * @s: the string to be written
 */
void _print(char *s)
{
	write(1, s, strlen(s));
}

/**
 * _printC - same as _print but writes a single character
 * @c: the character to be written
 */
void _printC(char c)
{
	write(1, c, 1);
}

/**
 * _printf - prints to stdout
 * @str: the string to be printed
 * Return: the number of characters printed to stdout
 */
int _printf(const char *str, ...)
{
	int len, i;
	va_list ap;
	char *buff;
}
