#include "main.h"

/**
 * print_number:the recursive fun to convert integer in print_int
 * @n: inteher to evaluate
 *
 * Return: length on int
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
 * print_int - prints an integer
 * @arg: arguments
 *
 * Return: lenght of the integer
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
        else if (i == 0)
        {
                write(1, "0", 1);
                len_int = 1;
        }
        else
        {
                write(1, &i, 1);
                len_int++;
        }

        return (len_int);
}
