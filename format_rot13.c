#include "holberton.h"
/**
 * format_rot13 - writes a string in ROT-13 encoded format onto a buffer
 * @buf: buffer where string will be written
 * @size: size of buffer
 * @args: argument list
 * @settings: format settings struct
 * Return: length of string written to buf
 **/
int format_rot13(char *buf, int *size, va_list args, settings_t settings)
{
	char *string = va_arg(args, char *);
	int i, string_length;
	char *lower_cases = "nopqrstuvwxyzabcdefghijklm";
	char *upper_cases = "NOPQRSTUVWXYZABCDEFGHIJKLM";

	(void)settings;

	if (string == NULL)
		string = "(null)";

	string_length = _strlen(string);

	adjust_buffer(buf, size, string_length + 1);

	for (i = 0; i < string_length; i++)
	{
		if (string[i] >= 65 && string[i] <= 90)
			buf[i] = upper_cases[string[i] - 'A'];
		else if (string[i] >= 97 && string[i] <= 122)
			buf[i] = lower_cases[string[i] - 'a'];
		else
			buf[i] = string[i];
	}
	buf[i] = '\0';
	return (i);
}
