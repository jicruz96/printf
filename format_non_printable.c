#include "holberton.h"
#define IS_NON_PRINTABLE(x) ((x > 0 && x < 32) || x >= 127)
/**
 * format_non_print -   writes a string, replacing non printable characters
 *                          with their ASCII code, preceded by "\x"
 * @buf: buffer where string will be written
 * @size: size of buffer
 * @args: argument list
 * @settings: format settings struct
 * Return: size of string written to buf
 **/
int format_non_print(char *buf, int *size, va_list args, settings_t settings)
{
	char *string = va_arg(args, char *);
	int tmp, i, j;

	(void)settings;

	for (tmp = 1, i = 0; string[i]; i++)
		if (IS_NON_PRINTABLE(string[i]))
			tmp += 4;
		else
			tmp += 1;

	buf = adjust_buffer(buf, size, tmp);
	if (buf == NULL)
		return (-1);

	for (i = 0, j = 0; string[i]; i++)
	{
		if (IS_NON_PRINTABLE(string[i]))
		{
			buf[j++] = '\\';
			buf[j++] = 'x';
			tmp = string[i] / 16;
			if (tmp > 9)
				tmp += 7;
			buf[j++] = tmp + '0';
			tmp = string[i] % 16;
			if (tmp > 9)
				tmp += 7;
			buf[j++] = tmp + '0';
		}
		else
		{
			buf[j++] = string[i];
		}
	}
	buf[j] = '\0';
	return (j);
}
