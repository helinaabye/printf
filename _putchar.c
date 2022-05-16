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

	putchar(c);
/*
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
*/
	return (1);
}
