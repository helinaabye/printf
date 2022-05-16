#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "main.h"

/**
 * _strlen - prints numbers, followed by a new line
 * @s: is the string to be printed between numbers
 * @flag: is a flag that checks if there is a percentage
 *        entry after the specifier
 * Return: returns length of the string
 */

int _strlen(const char *s, int flag)
{
	int length;

	for (length = 0; *s != '\0'; s++)
		length++;

	if (flag)
	{
		return (length - 1);
	}
	else
	{
		return (length);
	}
}

/**
 * unsigned_integer_to_string - changes the unsigned integer to string
 * @integer: integer number
 * @base: takes in the desired base to print with
 * @capitalflag: is a flag that checks if there is a capital charachter
 * @buffer: charachter array
 * Return: returns nothing
 */

void unsigned_integer_to_string(uint64_t integer, int base,
				 int capitalflag, char *buffer)
{
	int i, digit, cur = 0;
	char _buffer[65];

	if (integer == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}
	for (i = 0; i < 65; i++)
		_buffer[i] = 0;
	while (integer)
	{
		digit = integer % base;
		if (digit >= 10 && capitalflag == 0)
		{
			_buffer[cur++] = 'a' + (digit - 10);
		}
		else if (digit >= 10 && capitalflag == 1)
		{
			_buffer[cur++] = 'A' + (digit - 10);
		}
		else
		{
			_buffer[cur++] = '0' + digit;
		}

		integer /= base;
	}
	for (i = cur - 1; i != 0; i--)
		*buffer++ = _buffer[i];
	*buffer++ = _buffer[0];
	*buffer = 0;
}

/**
 * signed_integer_to_string - changes the signed integer to string
 * @integer: integer number
 * @base: takes in the desired base to print with
 * @capitalflag: is a flag that checks if there is a capital charachter
 * @buffer: charachter array
 * Return: returns nothing
 */

void signed_integer_to_string(int64_t integer, int base,
			       int capitalflag, char *buffer)
{
	if (integer < 0)
	{
		*buffer++ = '-';
		integer = -integer;
	}

	unsigned_integer_to_string(integer, base, capitalflag, buffer);
}

/**
 * v_printf - prints input charachter
 * @format: is a character string
 * @args: takes in list of arguments
 * Return: returns nothing
 */

/*State: 0: regular 1: escape*/

void v_printf(const char *format, va_list args)
{
	int state = 0;
	char ch;
	const char *s;

	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
				state = 1;
			else
				putchar(*format);
		}
		else if (state == 1)
		{
			switch (*format)
			{
			case 'c':
				ch = va_arg(args, int);
				putchar(ch);
				break;
			case 's':
			{
				s = va_arg(args, const char *);
				while (*s)
				{
					putchar(*s++);
				}
				break;
			}
			case '%':
			{
				putchar('%');
				break;
			}
		    state = 0;
		}
		format++;
	}
}

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 *         (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int noSpecifier = 1, isPercentage = 0;
	const char *s = format, *s1 = format;
	va_list args;

	while (*s1)
	{
		if (*s1 == '%')
		{
			noSpecifier = 0;
			break;
		}
		s1++;
	}
	while (*s1)
	{
		if (*s1 == '%' && *(s1 + 1) == '%')
			isPercentage = 1;
		s1++;
	}
	va_start(args, format);
	if (!noSpecifier)
	{
		v_printf(format, args);
	}
	else
	{
		while (*s)
		{
			putchar(*s);
			s++;
		}
		_strlen(format, isPercentage);
	}
	if (isPercentage == 1)
		_strlen(format, isPercentage);

	va_end(args);

	return (_strlen(format, isPercentage));
}
