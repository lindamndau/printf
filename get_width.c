#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @ag: list of arguments.
 * @w - width
 * Return: width.
 */
int get_width(const char *format, int *i, va_list ag)
{
	int index;
	int w = 0;

	for (index = *i + 1; format[index] != '\0'; index++)
	{
		if (is_digit(format[index]))
		{
			w *= 10;
			w += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			w = va_arg(ag, int);
			break;
		}
		else
			break;
	}

	*i = index - 1;

	return (w);
}
