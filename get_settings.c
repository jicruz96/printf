#include "holberton.h"

/**
 * get_settings - gets settings
 * @format: format string
 * Return: settings struct
 **/
settings_t get_settings(const char **format)
{
	settings_t settings = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for ((*format)++; **format; (*format)++)
		if (**format == '-')
			settings.minus = true;
		else if (**format == '+')
			settings.plus = true;
		else if (**format == ' ')
			settings.space = true;
		else if (**format == '0')
			settings.zero = true;
		else if (**format == '#')
			settings.hash = true;
		else
			break;

	if (is_digit(**format))
		for (settings.has_min = true; is_digit(**format); (*format)++)
			settings.width = (settings.width * 10) + (**format - '0');
	if (**format == '.')
		for (settings.has_max = true, (*format)++; is_digit(**format); (*format)++)
			settings.precision = (settings.precision * 10) + (**format - '0');
	if (**format == 'l' || **format == 'h')
		settings.len = *(*format)++;
	settings.type = **format;

	return (settings);
}
