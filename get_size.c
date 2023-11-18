#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @n: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *n)
{
	int index = *n + 1;
	int size = 0;

	if (format[index] == 'l')
	{
		size = S_LONG;
	}
	else if (format[index] == 'h')
	{
		size = S_SHORT;
	}

	if (size == 0)
	{
		*n = index - 1;
	}
	else
	{
		*n = index;
	}
	return (size);
}
