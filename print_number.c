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
int _strlen(char *s)
{
        int i;

        if (!s)
                return (0);

        for (i = 0; s[i] != '\0'; i++)
        {}

        return (i);
}

/**
 * print_number - prints number to stdout
 * @str: the number as a string
 * @params: pointer to params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_number(char *str, params_t *params)
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
int print_number_right_shift(char *str, params_t *params);

/**
 * print_number_shift_right - prints number with options
 * @str: the number as a string
 * @params: pointer to params_t (flag values)
 * Return: the number of characters written to stdout
 */
int print_number_left_shift(char *str, params_t *params);