#include <unistd.h> 
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h> 


typedef struct op
{
	char *op;
	int (*print)(va_list arg);
} op_list;

int print_char(va_list arg)
{
	char c;
	
	c = va_arg(arg, int);
	write(1, &c, 1);
	return 1; 
}

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
		len_string++;
	}
	
	write(1, s, len_string);
	return (len_string);
}

int _printf(const char *format, ...)
{
	int countformat = 0;
	int counting_list = 0;
	int printed_count = 0;
	
	va_list args;
	op_list ops[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	
	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	
	while (format[countformat] != '\0')
	{
		if (format[countformat] == '%')
		{
			counting_list = 0;
			int matched = 0; 
			while (ops[counting_list].op != NULL)
			{
				if (format[countformat + 1] == ops[counting_list].op[0])
				{
					printed_count += ops[counting_list].print(args);
					countformat += 2;
					matched = 1;
					continue; 
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
	va_end(args);
	return (printed_count);
}
