#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "holberton.h"

/**
 * _printf - prints strings and args to the standard output
 * @format: string
 * Return: an integer
 */
int _printf(const char *format, ...)
{
	int print_chars;
	va_list args;

	conver_t f_list[] = {
		{"c", print_char},
		{"%", print_percent},
		{"i", print_integer},
		{"d", print_integer},
		{"s", print_string},
		{"b", print_binary},
		{"u", unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	print_chars = parser(format, f_list, args);
	va_end(args);
	return (print_chars);
}
