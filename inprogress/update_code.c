#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_char - Printing char
 *
 * @arg: something
 *
 * Return -
 */

int print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Printing string
 *
 * @arg: something
 *
 * Return -
 */

int print_string(va_list arg)
{
	char *s;
	int len_string;

	s = va_arg(arg, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	len_string = 0;
	while (s[len_string] != '\0')
	{
		len_string = len_string + 1;
	}
	write(1, s, len_string);
	return (len_string);
}
/**
 * print_int - something
 * @arg: something
 *
 * Return - 
 */

int print_int(va_list arg)
{
	int *i;
	int len_int;

	i = va_arg(arg, int);
	len_int = 0;
	
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
		len_int++;
	}
	else if (i > 0)
	{
		write(1, &i, 1);
		len_int++;
	}
	else
	{
		write(1, "0", 1);
		len_int = 1;
	}

	return (len_int);
}
/**
 * print_number:the recursive fun to convert integer in print_int
 * @n
 * string
 */
int print_number(int n)
{
	int len_int = 0;
	char j;

	if (n / 10)
	{
		len_int += print_number(n / 10);
	}
	j = '0' + (n % 10);
	write(1, &j, 1);
	len_int++;
	return (len_int);
} 

/**
 * _printf - SOmething something
 *
 * @format: something
 *
 * Return - the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int countformat = 0;
	int counting_list = 0;
	int printed_count = 0;
	int matched;
	va_list args;
	op_list ops[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (format[countformat] != '\0')
	{
		if (format[countformat] == '%' && format[countformat + 1] == '%')
		{
			write(1, "%", 1);
			printed_count += 1;
			countformat += 2;
			continue;
		}
		if (format[countformat] == '%' && format[countformat + 1] == '\0')
		{
			exit(98);
			return (-1);
		}
		if (format[countformat] == '%')
		{
			counting_list = 0;
			matched = 0;

			while (ops[counting_list].op != NULL)
			{
				if (format[countformat + 1] == ops[counting_list].op[0])
				{
					printed_count += ops[counting_list].print(args);
					countformat += 2;
					matched = 1;
					break;
				}
				counting_list++;
			}
			if (matched == 0)
			{
				write(1, &format[countformat], 1);
				printed_count++;
				countformat++;
			}
			continue;
		}
		write(1, &format[countformat], 1);
		printed_count++;
		countformat++;
	}
	printf(printed_count);
	va_end(args);
	return (printed_count);
}
