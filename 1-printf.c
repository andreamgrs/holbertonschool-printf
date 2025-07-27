#include "main.h"

/**
 * _printf - Function to print characters.
 * @format: Format
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int countformat = 0, counting_list, printed_count = 0, matched;
	va_list args;
	op_list ops[] = {{"c", print_char}, {"s", print_string}, {NULL, NULL}};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[countformat] != '\0')
	{
		if (format[countformat] == '%' && format[countformat + 1] == '%')
		{
			write(1, "%", 1);
			printed_count++;
			countformat += 2;
			continue;
		}
		if (format[countformat] == '%' && format[countformat + 1] == '\0')
			return (-1);
		if (format[countformat] == '%')
		{
			matched = 0;
			for (counting_list = 0; ops[counting_list].op != NULL; counting_list++)
			{
				if (format[countformat + 1] == ops[counting_list].op[0])
				{
					printed_count += ops[counting_list].print(args);
					countformat += 2;
					matched = 1;
					break;
				}
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
	va_end(args);
	return (printed_count);
}

