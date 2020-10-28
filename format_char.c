#include "holberton.h"

/**
 * format_char - return formatted string of a character argument
 * @buf: buffer to write to
 * @size: size of buffer
 * @args: argument list
 * @settings: format settings struct
 * Return: always 1
 **/
int format_char(char *buf, int *size, va_list args, settings_t settings)
{
	(void)settings;
	buf = adjust_buffer(buf, size, 2);
	if (buf == NULL)
		return (-1);
	buf[0] = va_arg(args, int);
	buf[1] = '\0';
	return (1);
}
