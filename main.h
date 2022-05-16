#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
int _strlen(const char *s, int flag);
void unsigned_integer_to_string(uint64_t integer, int base,
	int capitalFlag, char *buffer);
void signed_integer_to_string(int64_t integer, int base,
	int capitalFlag, char *buffer);
void v_printf(const char *format, va_list args);
int _printf(const char *format, ...);
#endif /*#ifndef MAIN_H*/
