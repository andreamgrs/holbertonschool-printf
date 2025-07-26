#include "main.h"

/**
  * print_string - function prints a string
  * @arg: argument
  * Return: character count
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

