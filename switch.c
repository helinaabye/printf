#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * switchFunction - switchs cases of format specifiers
 * @format: is a character string
 * @args: takes in list of arguments
 * Return: returns nothing
 */

void switchFunction(const char *format, va_list args)
{
	char ch;
	const char *s;

	switch (*format)
	{
	case 'c':
	{
		ch = va_arg(args, int);
		_putchar(ch);
		break;
	}
	case 's':
	{
		s = va_arg(args, const char *);
		while (*s)
			_putchar(*s++);
		break;
	}
	case '%':
	{
		_putchar('%');
		break;
	}
	}
}
