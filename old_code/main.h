#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>

typedef struct op
{
	char *op;
	int (*print)(va_list arg);
} op_list;

int print_char(va_list arg);
int print_string(va_list arg);
void counter(int printed_count, int countformat);
int _printf(const char *format, ...);

#endif
