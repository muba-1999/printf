#include <stdio.h>
#include "holberton.h"

int hex_check(int, char);

/**
 * print_binary - converts numbers to binary
 * @list: list of arguments
 * Return: length of the printed numbers
 */
int print_binary(va_list list)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		return (_write_char('0'));
	}
	if (num < 1)
	{
		return (-1);
	}
	len = base_len(num, 2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (-1);
	}
	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
		{
			str[i] = '0';
		}
		else
		{
			str[i] = '1';
		}
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = strrev(str);
	if (rev_str == NULL)
	{
		return (-1);
	}
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * print_octal - prints a number in base 8
 * @list: arguments
 * Return: Number of symbols printed
 */
int print_octal(va_list list)
{
	unsigned int num;
	int len;
	char *octal_rep;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		return (_write_char('0'));
	}
	if (num < 1)
	{
		return (-1);
	}
	len = base_len(num, 8);
	octal_rep = malloc(sizeof(char) * len + 1);
	if (octal_rep == NULL)
	{
		return (-1);
	}
	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;
	}
	octal_rep = '\0';
	rev_str = strrev(octal_rep);
	if (rev_str == NULL)
	{
		return (-1);
	}
	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}
/**
 * print_hex - prints base 16 numbers in lowercase
 * @list: characters
 * Return: Number of printed characters
 */
int print_hex(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		return (_write_char('0'));
	}
	if (num < 1)
	{
		return (-1);
	}
	len = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * (len + 1));
	if (hex_rep == NULL)
	{
		return (-1);
	}
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rep[len] = rem_num;
		}
		else
		{
			hex_rep[len] = rem_num + 48;
		}
		num = num / 16;
	}
	hex_rep = '\0';
	rev_hex = strrev(hex_rep);
	if (rev_hex == NULL)
	{
		return (-1);
	}
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}
/**
 * print_heX - prints base 16 numbers in uppercase
 * @list: arguments passed
 * Return: number of characters printed
 */
int print_heX(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		return (_write_char('0'));
	}
	if (num < 1)
	{
		return (-1);
	}
	len = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * (len + 1));
	if (hex_rep == NULL)
	{
		return (-1);
	}
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[len] = rem_num;
		}
		else
		{
			hex_rep[len] = rem_num + 48;
		}
		num = num / 16;
	}
	hex_rep = '\0';
	rev_hex = strrev(hex_rep);
	if (hex_rep == NULL)
	{
		return (-1);
	}
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}
/**
 * hex_check - checks which hex function is called
 * @num: number to be converted to letters
 * @x: tells which hexfunction is calling
 * Return: Ascii value for letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";
	 num = num - 10;
	 if (x == 'x')
	 {
		 return (hex[num]);
	 }
	 else
	 {
		 return (Hex[num]);
	 }
	 return (0);
}
