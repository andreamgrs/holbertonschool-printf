#include "main.h"

/**
  * print_char - prints a char
  * @arg: arguments to passs
  * Return: On success 1
  */

int print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);

	write(1, &c, 1);
	return (1);
}

