#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>

typedef struct op
{
	char *op;
	void (*print)(va_list arg);
} op_list;

int _printf(const char *format, ...);

#endif
