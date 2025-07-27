#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct op
{
	char *op;
	int (*print)(va_list arg);
} op_list;

int print_char(va_list arg);
int print_string(va_list arg);
int print_int(va_list arg);
int _printf(const char *format, ...);

#endif
