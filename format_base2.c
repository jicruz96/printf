#include "holberton.h"

/**
 * format_base2 - writes string representation of number in octal format
 * @buf: buffer where string rep is written
 * @size: size of buffer
 * @args: arguments list
 * @settings: format settings struct
 * Return: size of string written to buf
 **/
int format_base2(char *buf, int *size, va_list args, settings_t settings)
{
	unsigned long int n = va_arg(args, unsigned long int);
	int hex_shift = get_hex_shift(settings), power = get_power(settings),
		digit, i = 0, shift = 63 - (63 % power), mapper = get_mapper(settings);

	buf = adjust_buffer(buf, size, 20);
	if (buf == NULL)
		return (-1);

	if (settings.hash || settings.type == 'p')
	{
		buf[i++] = '0';

		if (settings.type == 'p' || settings.type == 'x')
			buf[i++] = 'x';
		else if (settings.type == 'X')
			buf[i++] = 'X';
	}

	while (shift > 0 && !((n >> shift) & mapper))
		shift -= power;

	while (shift >= 0)
	{
		digit = ((n >> shift) & mapper);
		if (digit > 9)
			digit += hex_shift;
		buf[i++] = digit + '0';
		shift -= power;
	}

	buf[i] = '\0';
	return (i);
}

/**
 * get_mapper - gets mapper value for format_base2 function
 * @settings: settings struct
 * Return: mapper value
 **/
int get_mapper(settings_t settings)
{
	if (settings.type == 'b')
		return (1);
	if (settings.type == 'x' || settings.type == 'X' || settings.type == 'p')
		return (15);
	return (7);
}

/**
 * get_power - gets power value for format_base2 function
 * @settings: settings struct
 * Return: power value
 **/
int get_power(settings_t settings)
{
	if (settings.type == 'b')
		return (1);
	if (settings.type == 'x' || settings.type == 'X' || settings.type == 'p')
		return (4);
	return (3);
}

/**
 * get_hex_shift - gets jex_shift value for format_base2 function
 * @settings: settings struct
 * Return: hex_shift value
 **/
int get_hex_shift(settings_t settings)
{
	if (settings.type == 'b' || settings.type == 'o')
		return (0);
	if (settings.type == 'x' || settings.type == 'p')
		return (39);
	return (7);
}
