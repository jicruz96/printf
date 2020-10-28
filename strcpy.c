#include "holberton.h"

/**
 * _strncpy - custom strncpy. see man strncpy
 * @destination: buffer where first n chars of source will be copied
 * @source: string to be copied
 * @n: number of chars to copy
 * Return: pointer to destination
 **/
char *_strncpy(char *destination, const char *source, int n)
{
	int i;

	if (source == NULL || destination == NULL)
		return (NULL);

	for (i = 0; source[i] && i < n; i++)
		destination[i] = source[i];

	for (; i < n; i++)
		destination[i] = '\0';

	return (destination);
}
