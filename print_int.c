#include "main.h"

/**
 * print_number - the recursive fun to convert integer in print_int
 * @n: integer to evaluate
 *
 * Return: length on int
 */
int print_number(unsigned int n)
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
 * Return: length of the int
 */

int print_int(va_list arg)
{
	int i = va_arg(arg, int);
	int len_int = 0;
	unsigned int num;

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
