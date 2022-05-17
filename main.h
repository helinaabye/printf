#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int _putchar(char c);
int _strlen(const char *s, int flag);
void unsigned_integer_to_string(unsigned int  integer, int base,
	int capitalflag, char *buffer);
void signed_integer_to_string(int integer, int base,
	int capitalflag, char *buffer);
void v_printf(const char *format, va_list args);
void switchFunction (const char *format, va_list args);
int _printf(const char *format, ...);
#endif /*#ifndef MAIN_H*/
