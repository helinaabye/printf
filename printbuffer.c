#include "main.h"
#include <stdarg.h>

/**
 * printBuffer - prints the buffer
 * @base: takes in an integer base
 * @args: takes in list of arguments
 * Return: returns nothing
 */

void printBuffer(int base, va_list args)
{
	int i;
	char buffer[40];

	signed_integer_to_string((va_arg(args, int)), base, buffer);
	for (i = 0; buffer[i]; i++)
		_putchar(buffer[i]);
}
