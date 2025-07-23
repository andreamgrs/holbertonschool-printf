#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/*_printf - SOmething something
 *
 * @format: something 
 *
 * return - 
 */

void print_char(va_list arg)
{
    char c;
    c = va_arg(arg, int);
    write(1, &c, 1);
}

void print_string(va_list arg)
{
    char *s;
    int len_string;
    s = va_arg(arg, char *);
    if (s == NULL)
    {
        return;
    }
    //while to get the len of the string for use the write function
    len_string = 0;
    while (s[len_string] != '\0')
    {
        len_string = len_string + 1;
    }
    write(1, s, len_string);
}

int _printf(const char *format, ...)
{
	int countformat = 0;
	int counting_list = 0;
	va_list args;
	op_list ops[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[countformat] != '\0')
	{	
		if (format[countformat] == '%')
		{
			counting_list = 0;

			while (ops[counting_list].op != NULL)
			{
				if (format[countformat + 1] == ops[counting_list].op[0])
				{
					ops[counting_list].print(args);
					break;
				}
				counting_list++;
			}			
		}
		if (format[countformat] != '%')
		{	
			count += 2
			write(1, &format[countformat], 1);
		}
		countformat++;
	}
}	
