#include "holberton.h"

/**
 * print_number - prints numbers sent to this function
 * @arg: arguments passed
 * Return: number of arguments printed
 */
int print_number(va_list arg)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n = va_arg(arg, int);
	div = 1;
	len = 0;
	if (n < 0)
	{
		len += _write_char('-');
		num = n * -1;
	}
	else
	{
		num = n;
	}
	for (; num / div > 9; )
	{
		div *= 10;
	}
	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num = num % div;
		div = div / 10;
	}
	return (len);
}
/**
 * print_unsigned_number - prints an unsigned number
 * @n: unsigned number to be printed
 * Return: The amount of numbers printed
 */
int print_unsigned_number(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;
	num = n;

	for (; num / div > 9; )
	{
		div *= 10;
	}
	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num = num % div;
		div = div / 10;
	}
	return (len);
}
