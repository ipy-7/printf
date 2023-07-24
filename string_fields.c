#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * get_precision - gets the precision from the format string
 * 
 * @p: the string
 * @params: pointer to the params struct
 * @ap: the argument list pointer
 * Return: number of characters written to stdout
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
    int x;

    x = 0;
    if (*p != '.')
        return (p);

    p++;
    if (*p == '*')
    {
        x = va_arg(ap, int);
        p++;
    }
    else
    {
        while (_isdigit(*p))
        {
            x = (x * 10) + (*p - '0');
            p++;
        }
    }

    params->precision = x;
    return (p);
}
