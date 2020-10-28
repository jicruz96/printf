#ifndef FUNCTION_DECLARATIONS
#define FUNCTION_DECLARATIONS

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

#define KB 100
#define is_digit(a) (a >= '0' && a <= '9')
#define true 1
#define false 0

/**
 * struct settings_s - struct of format specifications for _printf argument
 * @str:		string
 * @type:		string type (e.g. s in '%s', c in '%c')
 * @len:		if 1, print long int. if -1, print short int.
 * @minus:		if 1, print right-aligned
 * @plus:		if 1, print the '+' sign before an integer
 * @space:		if 1, print placeholder chars with spaces
 * @zero:		if 1, print placeholder chars with zeroes
 * @hash:		if 1, print non-base 10 digits with prefixes
 * @has_min:	has a width value
 * @width:		minimum number of chars to print
 * @has_max:	has a precision value
 * @precision:	maximum number of chars to print
 **/
typedef struct settings_s
{
	int type;
	int len;
	int minus;
	int plus;
	int space;
	int zero;
	int hash;
	int has_min;
	int width;
	int has_max;
	int precision;
} settings_t;

/**
 * struct printer_dict_s - printer dictionary struct
 * @formats: format specifier type associated with the printer function
 * @printer: the printer function associated with formats
 **/
typedef struct printer_dict_s
{
	char *formats;
	int (*printer)(char *, int *, va_list, settings_t);
} printer_dict_t;

int _strlen(const char *string);
char *_memset(char *buffer, char value, int n);
char *_strncpy(char *destination, const char *source, int n);
int _printf(const char *format, ...);
char *adjust_buffer(char *buffer, int *buffer_size, int desired_size);
int get_formatted_string(char *buf, int *size, const char **f, va_list args);
int format_char(char *buf, int *size, va_list args, settings_t settings);
int format_string(char *buf, int *size, va_list args, settings_t settings);
int format_int(char *buf, int *size, va_list args, settings_t settings);
int format_uint(char *buf, int *size, va_list args, settings_t settings);
int format_binary(char *buf, int *size, va_list args, settings_t settings);
int format_base2(char *buf, int *size, va_list args, settings_t settings);
int format_non_print(char *buf, int *size, va_list args, settings_t settings);
int format_reverse(char *buf, int *size, va_list args, settings_t settings);
int format_rot13(char *buf, int *size, va_list args, settings_t settings);
settings_t get_settings(const char **format);

int get_mapper(settings_t settings);
int get_power(settings_t settings);
int get_hex_shift(settings_t settings);

#endif /* FUNCTION_DECLARATIONS */
