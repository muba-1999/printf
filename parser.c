#include "holberton.h"

/**
 * parser - recieves the main string and the parameters to print a formatted string
 * @format: A string contain all characters
 * @f_list: A list of all functions
 * @arg: List containing arguments passed to the program
 * Return: Total number of characters printed
 */
int parser(const char *format, conver_t f_list[], va_list args)
{
	int i, j, r_val, print_chars;

	print_chars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].symbol != NULL; j++)
			{
				if (format[i + 1] == f_list.symbol[0])
				{
					r_val = f_list[j].func(args);
					if (r_val == -1)
					{
						return (-1);
					}
					print_chars += r_val;
					break;
				}
			}
			if (f_list[j].symbol == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write_char(format[i]);
					_write_char(format[i + 1]);
					print_chars = print_chars + 2;
				}
				else
				{
					return (-1);
				}
			}
			i = i + 1;
		}
		else
		{
			_write_char(format[i]);
			print_chars++;
		}
	}
	return (print_chars);
}
