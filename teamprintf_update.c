#include <stdio.h> // ignore in sandbox
#include <unistd.h> 
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h> 


typedef struct op
{
    char *op;
    int (*print)(va_list arg);
} op_list;


int print_char(va_list arg) // changed to int due to type conflict (ref struct)
{
        char c;

        c = va_arg(arg, int);
        write(1, &c, 1);
        return 1; // prints a single char
}

int print_string(va_list arg) // changed to int due to type conflict (ref struct)
{
        char *s;
        int len_string;

        s = va_arg(arg, char *);
        if (s == NULL)
        {
                s = "(null)"; // to print this instead when arg is NULL
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
        int printed_count = 0; // track number of chars printed
        
        va_list args;
        
        op_list ops[] = {
                {"c", print_char},
                {"s", print_string},
                {NULL, NULL}
        };

        if (format == NULL)
                return (-1);

        va_start(args, format);     

        while (format[countformat] != '\0')
        {
                if (format[countformat] == '%')
                {
                        counting_list = 0;
                        int matched = 0; // flag that sets to 1 (true) if a valid specifier is found

                        while (ops[counting_list].op != NULL)
                        {
                                if (format[countformat + 1] == ops[counting_list].op[0])
                                {
                                    printed_count += ops[counting_list].print(args); // add up printed return values for c and s (to track)
                                    countformat += 2;
                                    matched = 1;
                                    // Changed from break to continue 
                                    // This makes the loop start the next iteration
                                    // skipping write and countformat++ below
                                    // therefore avoiding double-printing the character after a valid specifier
                                    continue; 
                                }
                                counting_list++;
                        }
                        
                        if (matched == 0) // in the event of finding % and not a valid specifier
                        {
                            write(1, &format[countformat], 1);
                            printed_count++;
                            countformat++;
                        }

                        continue;
                }
                
                write(1, &format[countformat], 1); 
                printed_count++; // add for regular characters
                countformat++; // advance index for normal characters
        }    
        
        va_end(args);
        return (printed_count); // which is what the real printf returns
}