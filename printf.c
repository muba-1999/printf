#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "holberton.h"

/**
 * _strrev - reverses a string
 * @str: string to be reversed
 *Return: pointer
 */
char _strrev(char *str)
{
	int i;
	int len = 0;
	char c;

	while (str[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (*str);
}
/**
 * _itoa - converts an integer to a string
 * @i: first element
 * @strout: string to output
 * @base: base element
 * Return: pointer
 */
char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	_strrev(strout);
	return (strout);
}
/**
 * _printf - prints strings and args to the standard output
 * @format: string 
 * Return: an integer
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char buff[100], tmp[20];
	char *str;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i])
			{
				case 'i':
					_itoa(va_arg(args, int), tmp, 10);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
				case 'd':
					_itoa(va_arg(args, int), tmp, 10);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
				case 's':
					str = va_arg(args, char *);
					strcpy(&buff[j], str);
					j += strlen(str);
					break;
				case 'c':
					buff[j] = (char)va_arg(args, int);
					j++;
					break;
				case 'o':
					_itoa(va_arg(args, unsigned int), tmp, 8);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
				case 'x':
					_itoa(va_arg(args, unsigned int), tmp, 16);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
				case 'u':
					_itoa(va_arg(args, unsigned int), tmp, 10);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
				case '%':
					buff[j] = '%';
					fwrite(buff, j, 1, stdout);
					break;

			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(args);
	return (j);

}
