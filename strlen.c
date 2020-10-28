#include "holberton.h"

/**
 * _strlen - custom strlen; returns 0 if string is NULL
 * @string: string
 * Return: length
 **/
int _strlen(const char *string)
{
	int len;

	if (string == NULL)
		return (0);

	for (len = 0; string[len]; len++)
		;

	return (len);
}
