#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
* struct parameters - prameters struct
*
* @unsign: flag if unsigned value
* @plus_flag: if plus_flag specified
* @space_flag: if hashtag_flag specified
* @hashtag_flag: if _flag specified
* @zero_flag: if _flag specified
* @minus_flag: if _flag specified
*
* @width: if field width specified
* @precision: if field precision specified
*
* @h_modifier: if h_modifier is specified
* @l_modifier: if l_modifier is specified
*/

typedef struct parameters
{
	unsigned int unsign;
	unsigned int plus_flag;
	unsigned int space_flag;
	unsigned int hashtag_flag;
	unsigned int zero_flag;
	unsigned int minus_flag;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier;
	unsigned int l_modifier;
} params_t;

/**
* struct specifier - struct token
* @specifier: format token
* @f: the function associated
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);

/*number.c*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/*converter*/
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/*simple printers*/
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/*print_number*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/*params*/
void init_params(params_t *params, va_list ap);

/*string field*/
char *get_precision(char *p, params_t *params, va_list ap);

/*_printf*/
int _printf(const char *format, ...);

#endif /* _PRINTF_H */

