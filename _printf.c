#include "main.h"
#include <stdarg.h>
#include <stdio.h>
void print_buffer(char b[], int *buff_ind);
/**
 * @_printf - prints output according to format
 *
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list ag;
	char b[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			b[buff_index++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(b, &buff_index);
			}
			printed_chars++;
		}
		else
		{
			print_buffer(b, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, b,
				flags, width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}

	print_buffer(b, &buff_index);

	va_end(ag);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @b: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char b[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &b[0], *buff_ind);
	}

	*buff_ind = 0;
}
