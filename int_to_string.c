#include <stdio.h>

#include "main.h"

/**
 * unsigned_integer_to_string - changes the unsigned integer to string
 * @integer: integer number
 * @base: takes in the desired base to print with
 * @capitalflag: is a flag that checks if there is a capital charachter
 * @buffer: charachter array
 * Return: returns nothing
 */

void unsigned_integer_to_string(unsigned int  integer, int base,
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

void signed_integer_to_string(int integer, int base,
			       int capitalflag, char *buffer)
{
	if (integer < 0)
	{
		*buffer++ = '-';
		integer = -integer;
	}
	unsigned_integer_to_string(integer, base, capitalflag, buffer);
}
