#include "holberton.h"
#include <stdio.h>

/**
 * _printf - custom printf function. see man _printf for details
 * @format: string to format and then print
 * Return: number of characters printed
 **/
int _printf(const char *format, ...)
{
	int i, j, string_length, buffer_size = 0, string_size = 0;
	char *buffer, *string;
	va_list arguments;

	if (format == NULL)
		return (-1);

	va_start(arguments, format);
	buffer = adjust_buffer(NULL, &buffer_size, KB);
	string = adjust_buffer(NULL, &string_size, KB);

	for (i = 0, j = 0; *format; format++)
	{
		j += get_formatted_string(string, &string_size, &format, arguments);
		string_length = _strlen(string);
		adjust_buffer(buffer, &buffer_size, i + string_length);
		_strncpy(buffer + i, string, string_length);
		i = i + string_length;
	}

	write(1, buffer, i);

	va_end(arguments);
	free(buffer);
	free(string);

	return (j);
}