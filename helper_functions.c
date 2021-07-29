#include "holberton.h"
#include <stdio.h>

/**
 * strrev - reverses a string
 * @s: string to reverse
 * Return: a pointer
 */
char *strrev(char *s)
{
	int len;
	int i;
	char tmp;
	char *str;
	while (s[len] != '\0')
	{
		len++;
	}
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	_memcpy(str, s, len);
	for (i = 0; i < len; i++, len--)
	{
		tmp = str[len - 1];
		str[len - 1] = str[i];
		str[i] = tmp;
	}
	return (str);
}
/**
 * write_base - sends character to be written on the stdout
 * @str: string to pass
 * Return: nothing
 */
void write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '0'; i++)
	{
		_write_char(str[i]);
	}
}
/**
 * base_len - calculate the length of an octal number
 * @num: length to be calculated
 * @base: base to be calculated by
 * Return: The length of a number
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}
/**
 * _memcpy - copies memory area
 * @dest: Destination for copying
 * @src: source to copy from
 * @n: number of bytes to copy
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
