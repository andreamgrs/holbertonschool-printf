README for printf. Collaborated by Toni M, Andrea M G, Chloe Y and Michelle N


This directory contains the group task for _printf. 


1-printf.c is the main code for the task

print_char.c, print_int.c and print_string.c are functions called upon from 1-printf.c

main.h is the header file for 1-printf.c

man_3_printf is the manual page for 1-printf.c

Printf - Complete.pdf is the flowchart for the code creation of 1-printf.c

## About The Project
_printf() is a function that utilises write to print characters, utilising several functions to accept variable arguments which are converted to an output for stdout.
int _printf(const char *format, ...);

Where format is a pointer that points to the string that needs to be printed. When a character "%" is encountered within the argument, the if loop identifies if the following character is a conversion specifier. 
If no conversion specifier is identified as the following character, it will not print the initial '%'. If the following character is also 
'%' i.e. '%%', it will print only one '%'.

**Conversion specifiers**

| Specifier | Output |
|-----------|--------|
| c | Character |
| s | String |
| i | Integer |
| d | Decimal integer |

## Return Value
Upon successful completion, _printf() returns the total number of bytes written to standard output (the sum of all characters printed, excluding
 any terminating null byte).

## Example
To print a character and a string:

	_printf("Character: [%c]\n", 'H');
	_printf("String: [%s]\n", "I am a string!");

To print a simple message and its length:

	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Length: [%i]\n", len);

To print a negative integer:

	_printf("Negative: [%d]\n", -762534);

To print INT_MIN:

	_printf("%d\n", INT_MIN);

## Authors
Toni M, Andrea M G, Chloe Y and Michelle N

## End
