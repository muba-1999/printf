#include "holberton.h"

/**
 * print_reversed - calls a function to reverse andprint a string
 * @arg: Argument passed
 * Return: number of characters printed
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		return (-1);
	}
	ptr = strrev(str);
	if (ptr == NULL)
	{
		return (-1);
	}
	for (len = 0; ptr[len] != '\0'; len++)
	{
		_write_char(ptr[len]);
	}
	free(ptr);
	return (len);
}
