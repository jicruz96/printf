#include "holberton.h"

/**
 * format_uint - return formatted string of an unsigned integer argument
 * @buf: buffer to write to
 * @size: size of buffer
 * @args: argument list
 * @settings: format setting struct
 * Return: length of string written to buffer
 **/
int format_uint(char *buf, int *size, va_list args, settings_t settings)
{
	int i, n = va_arg(args, unsigned int);
	unsigned int magnitude;

	(void)settings;

	adjust_buffer(buf, size, 21);

	if (n < 10)
	{
		buf[0] = n + '0';
		buf[1] = '\0';
		return (1);
	}

	for (i = n, magnitude = 1; i > 9; i /= 10)
		magnitude *= 10;

	for (i = 0; magnitude; i++)
	{
		buf[i] = n / magnitude + '0';
		n = n % magnitude;
		magnitude /= 10;
	}
	buf[i] = '\0';
	return (i);
}
