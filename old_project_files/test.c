#include "holberton.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
/*int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX - (1947 << 6) + 131;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[% +d, %+ i]\n", 0, len);
	printf("Length:[% +d, %+ i]\n", 0, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[% d]\n", -762534);
	_printf("Unsigned:[%u]\n", 1000000);
	printf("Unsigned:[%+u]\n", 1000000);
	_printf("Unsigned octal:[% #o]\n", ui);
	printf("Unsigned octal:[% #o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %#X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %#X]\n", ui, ui);
	len = _printf("Character:[%c]\n", 'a');
	len2 = printf("Character:[%c]\n", 'a');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");
	printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%w]\n");
	printf("Unknown:[%w]\n");
	_printf("binary: %b\n", 255);
	return (0);
}*/

int main(void)
{
	int len, len2;
	long int l = INT_MIN;

	l -= 1024;
	len = _printf("%+d", l);
	len2 = printf("%+d", l);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}

/*int main(void)
{
	_printf("");
	return (0);
}*/
