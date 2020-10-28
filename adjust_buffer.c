#include "holberton.h"

/**
 * adjust_buffer - allocates more space to a buffer, initializes space to 0
 * @buffer: buffer to adjust
 * @buffer_size: pointer to buffer size. also adjusted.
 * @desired_size: minimum desired new size for buffer
 * Return: pointer to buffer
 **/
char *adjust_buffer(char *buffer, int *buffer_size, int desired_size)
{
	while (*buffer_size < desired_size)
	{
		*buffer_size += KB;
		buffer = realloc(buffer, *buffer_size);
		if (buffer == NULL)
			return (NULL);
		_memset(buffer + *buffer_size - KB, 0, KB);
	}
	return (buffer);
}
