#include "holberton.h"

/**
 * format_string - return formatted string of a string argument
 * @buf: buffer to write to
 * @size: size of buffer
 * @args: argument list
 * @settings: format settings
 * Return: string length
 **/
int format_string(char *buf, int *size, va_list args, settings_t settings)
{
	char *string = va_arg(args, char *);
	int string_length;

	(void)settings;

	if (string == NULL)
		string = "(null)";

	string_length = _strlen(string);
	buf = adjust_buffer(buf, size, string_length + 1);
	if (buf == NULL)
		return (-1);
	_strncpy(buf, string, string_length);
	buf[string_length] = '\0';
	return (string_length);
}
