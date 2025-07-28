#include "main.h"

/**
 * print_number:the recursive fun to convert integer in print_int
 * @n: inteher to evaluate
 *
 * Return: length on int
 */
int print_number(unsigned int n)
{
	int len_int = 0;
	int mod = n % 10;
	char j;

	if (n > 9)
	{
		len_int += print_number(n / 10);
        }
	j = '0' + (mod);
	write(1, &j, 1);
	len_int++;
	return (len_int);
} 

/**
 * print_int - prints an integer
 * @arg: arguments
 *
 * Return: length of the integer
 */

int print_int(va_list arg)
{
	int i = va_arg(arg, int);
	int len_int = 0;
	unsigned int num;

	/**if (i == INT_MIN)
        {
                write(1,"-2147483648", 11);
                len_int = 11;
                return (len_int);
        }
        else if (i == INT_MAX)
        {
                write(1, "2147483647", 10);
                len_int = 10;
                return (len_int);
        }if (i == 0)
	{
		write(1, "0", 1);
		num = i;
	}*/
	if (i < 0)
	{
		write(1, "-", 1);
		len_int++;
		num = -i;
	}
	else
	{
		num = i;
	}
	len_int += print_number(num);
	return (len_int);
}
