#include "main.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * print_from_to - prints pointer values from start to stop
 * @start: the pointer pointing to the start of the string
 * @stop: the pointer pointing to the end of the string
 * @except: ...
 * Return: the number of characters written to stdout
 */
int print_from_to(char *start, char *stop, char *except)
{
	int cnt;

	cnt = 0;
	while (start <= stop)
	{
		if (start != except)
			_putchar(*start);
		start++;
	}

	return (cnt);
}

/**
 * print_rev - prints string in reverse
 * @ap: the pointer to the argument list
 * @params: the pointer to the params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_rev(va_list ap, params_t *params)
{
	int len, i;
	char *s;

	s = va_arg(ap, char *);
	len = _strlen(s);
	(void)params;

	if (!s)
		return (0);

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}

	return (len);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: the pointer to the argument list
 * @params: the pointer to the params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_rot13(va_list ap, params_t *params)
{
int i, index;
int count = 0;
char arr[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
char *a = va_arg(ap, char *);
(void)params;

i = 0;
index = 0;
while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z')
|| (a[i] >= 'a' && a[i] <= 'z'))
{
index = a[i] - 65;
count += _putchar(arr[index]);
}
else
count += _putchar(a[i]);
i++;
}
return (count);
}
