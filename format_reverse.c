#include "holberton.h"

/**
 * format_reverse - writes a string in reverse onto a buffer
 * @buf: buffer where string will be written
 * @size: size of buffer
 * @args: argument list
 * @settings: format settings struct
 * Return: length of string written to buffer
 **/
int format_reverse(char *buf, int *size, va_list args, settings_t settings)
{
	char *string = va_arg(args, char *);
	int i, string_length;

	(void)settings;

	if (string == NULL)
		string = "(llun)";

	string_length = _strlen(string);

	buf = adjust_buffer(buf, size, string_length + 1);
	if (buf == NULL)
		return (-1);

	for (i = 0; i < string_length; i++)
		buf[i] = string[string_length - 1 - i];

	buf[i] = '\0';
	return (string_length);
}
