#include "main.h"
#include <stdarg.h>

/**
 * printBuffer - prints the buffer
 * @base: takes in an integer base
 * @args: takes in list of arguments
 * Return: returns nothing
 */

void printBuffer(int base, const char format, int capitalFlag, va_list args)
{
	int i,  num;
	unsigned int num1;
	const char *s;
	char buffer[65];

	if (format == 's')
	{
		s = va_arg(args, const char *);
		while(*s)
			_putchar(*s++);
	}
	else if (format == 'd' || format == 'i')
	{
		num = va_arg(args, int);
		signed_integer_to_string(num, base, capitalFlag, buffer);
	}
	else if (format == 'u' || format == 'o' || format == 'x'
		 || format == 'X')
	{
		num1 = va_arg(args, unsigned int);
		signed_integer_to_string(num1, base, capitalFlag, buffer);
	}
	else if (format == 'b')
	{
		num = va_arg(args, int);
		signed_integer_to_string(num, base, capitalFlag, buffer);
	}
	if (format != 's')
	{
		for (i = 0; buffer[i]; i++)
		{
			_putchar(buffer[i]);
		}

	}
}
