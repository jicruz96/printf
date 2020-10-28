#include "holberton.h"

/**
 * _memset - custom memset (for char pointers only). see man memset
 * @buffer: buffer where it all happens
 * @value: value that positions will be set to
 * @n: number of positions to set
 * Return: pointer to buffer
 **/
char *_memset(char *buffer, char value, int n)
{
	int i;

	if (buffer == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		buffer[i] = value;

	return (buffer);
}
