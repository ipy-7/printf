#include <stdio.h>
#include "main.h"

/**
 * _isdigit - checks whether a character is a digit or not
 * @c: the character to be checked
 * Return: 1 if the character is a digit, else 0
 */
int _isdigit(int c)
{
    return (48 <= c && c <= 57);
}

/**
 * _strlen - returns the string length
 * @s: the string
 * Return: length of the string
 */
int _strlen(char* s)
{
    int i;

    if (!s)
        return (0);

    for (i = 0; s[i] != '\0'; i++)
    {
    }

    return (i);
}

/**
 * print_number - prints number to stdout
 * @str: the number as a string
 * @params: pointer to params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_number(char* str, params_t* params)
{
    int i, neg;

    i = _strlen(str);
    neg = (!params->unsign && *str == '-');

    if (params->precision != UINT_MAX)
    {
        while (i < params->precision)
        {
            *--str = '0';
        }
    }

    if (neg)
        *--str = '-';

    if (params->minus_flag)
        return (print_number_right_shift(str, params));
    return (print_number_left_shift(str, params));
}

/**
 * print_number_shift_right - prints number with options
 * @str: the number as a string
 * @params: pointer to params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_number_right_shift(char* str, params_t* params)
{
    unsigned int x, neg, neg2, i;
    char padChar;

    padChar = ' ';
    i = _strlen(str);
    x = 0;
    if (params->zero_flag && !params->minus_flag)
    {
        padChar = '0';
    }
    neg = neg2 = (!params->unsign && *str == '-');
    if (neg && i < params->width && padChar == '0' && !params->minus_flag)
        str++;
    else
        neg = 0;
    if ((params->plus_flag && neg2) ||
    (!params->plus_flag && params->space_flag && !neg2))
        i++;
    if (neg && padChar == '0')
        x += _putchar('-');
    if (params->plus_flag && !neg2 && padChar == '0' && !params->unsign)
        x += _putchar('+');
    else if (!params->unsign && params->space_flag && neg2 &&
    !params->unsign && params->zero_flag)
        x += _putchar(' ');
    while (i++ < params->width)
        x += _putchar(padChar);
    if (neg && padChar == ' ')
        x += _putchar('-');
    if (params->plus_flag && neg2 && padChar == ' ' && !params->unsign)
        x += _putchar('+');
    else if (!params->plus_flag && params->space_flag && !neg2 &&
    !params->unsign && !params->zero_flag)
        x += _putchar(' ');
    x += _puts(str);
    return (x);
}

/**
 * print_number_shift_right - prints number with options
 * @str: the number as a string
 * @params: pointer to params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_number_left_shift(char* str, params_t* params)
{
    unsigned int x, neg, neg2, i;
    char padChar;

    padChar = ' ';
    i = _strlen(str);
    x = 0;
    if (params->zero_flag && !params->minus_flag)
    {
        padChar = '0';
    }
    neg = neg2 = (!params->unsign && *str == '-');
    if (neg && i < params->width && padChar == '0' && !params->minus_flag)
        str++;
    else
        neg = 0;

    if (params->plus_flag && !neg2 && !params->unsign)
    {
        x += _putchar('+');
        i++;
    }
    else if (params->space_flag && !neg2 && !params->unsign)
    {
        x += _putchar(' ');
        i++;
    }
    x += _puts(str);
    while (i < params->width)
    {
        x += _putchar(padChar);
    }
    return (x);
}
