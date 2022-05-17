#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1 and -1 otherwise
 * Description: _putchar uses a local buffer of 1024 to call write
 *              as little as possible
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
