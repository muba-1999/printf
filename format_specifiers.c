#include "holberton.h"

/**
 * print_char - prints characters
 * @list: arguments
 * Return: characters printed
 */
int print_char(va_list list)
{
	_write_char(va_arg(list, int));
	return (1);
}
/**
 * print_string - prints strings
 * @list: arguments
 * Return: characters printed)
 */
int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		_write_char(str[i]);
	}
	return (i);
}
/**
 * print_percent - prints percent symbol
 * @list: list of arguments
 * Return: number of characters printed
 */
int print_percent(__attribute__((unused))va_list list)
{
	_write_char('%');
	return (1);
}
/**
 * print_integer - prints integers
 * @list: list of arguments
 * Return: number of characters printed
 */
int print_integer(va_list list)
{
	int num_len;

	num_len = print_number(list);
	return (num_len);
}
/**
 * unsigned_integer - prints unsigned integers
 * @list: list of arguments
 * Return: number of characters printed
 */
int unsigned_int(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);
	if (num ==  0)
	{
		return (print_unsigned_number(num));
	}
	if (num < 1)
	{
		return (-1);
	}
	return (print_unsigned_number(num));
}
