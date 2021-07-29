#include "holberton.h"

/**
 * _write_char - write characters to the standard output
 * @c: characters
 *
 * Return: 1 on success
 * on error -1
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}
