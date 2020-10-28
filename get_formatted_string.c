#include "holberton.h"

/**
 * get_formatted_string - create and return a formatted string
 * @buf: buffer where formatted string will be written
 * @size: size of buffer
 * @f: format string
 * @args: arguments list
 * Return: pointer to buffer
 **/
int get_formatted_string(char *buf, int *size, const char **f, va_list args)
{
	int i, j;
	settings_t settings;
	printer_dict_t printers[] = {
		{"c", format_char},
		{"s", format_string},
		{"di", format_int},
		{"u", format_uint},
		{"boxXp", format_base2},
		{"S", format_non_print},
		{"r", format_reverse},
		{"R", format_rot13},
		{NULL, NULL}};

	if (**f != '%')
	{
		buf = adjust_buffer(buf, size, 2);
		if (buf == NULL)
			return (-1);
		*buf = **f;
		*(buf + 1) = '\0';
		return (1);
	}

	settings = get_settings(f);

	for (i = 0; printers[i].formats; i++)
		for (j = 0; printers[i].formats[j]; j++)
			if (printers[i].formats[j] == **f)
				return (printers[i].printer(buf, size, args, settings));

	buf = adjust_buffer(buf, size, 3);
	if (buf == NULL || **f == '\0')
		return (-1);
	i = 0;
	buf[i++] = '%';
	if (**f != '%')
		buf[i++] = **f;
	buf[i] = '\0';
	return (i);
}
