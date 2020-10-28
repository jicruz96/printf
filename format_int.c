#include "holberton.h"

/**
 * format_int - return formatted string of an integer argument
 * @buf: buffer to write to
 * @size: size of buffer
 * @args: argument list
 * @settings: format settings struct
 * Return: size of string written to buf
 **/
int format_int(char *buf, int *size, va_list args, settings_t settings)
{
	int n = va_arg(args, int);
	int i = 0;
	int tmp;
	int magnitude;

	buf = adjust_buffer(buf, size, 20);
	if (buf == NULL)
		return (-1);

	if (n == INT_MIN)
	{
		_strncpy(buf, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		buf[i++] = '-';
		n = -n;
	}
	else
	{
		if (settings.plus)
			buf[i++] = '+';
		else if (settings.space)
			buf[i++] = ' ';
		if (n == 0)
		{
			buf[i++] = '0';
			buf[i] = '\0';
			return (i);
		}
	}

	for (tmp = n, magnitude = 1; tmp > 9; tmp /= 10)
		magnitude *= 10;

	for (; magnitude; n = n % magnitude, magnitude /= 10, i++)
		buf[i] = n / magnitude + '0';

	buf[i] = '\0';
	return (i);
}
