#include "main.h"
/**
 * print_int - Print int
 * @ag: List of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list ag, char b[],
	int flags, int w, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(ag, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, b, flags, w, precision, size));
}
/**
 * print_percent - Prints a percent sign
 * @ag: List of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char b[],
	int flags, int w, int precision, int size)
{
	UNUSED(ag);
	UNUSED(b);
	UNUSED(flags);
	UNUSED(w);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_char - Prints a char
 * @ag: List a of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list ag, char b[],
	int flags, int w, int precision, int size)
{
	char c = va_arg(ag, int);

	return (handle_write_char(c, b, flags, w, precision, size));
}
/**
 * print_string - Prints a string
 * @ag: List a of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list ag, char b[],
	int flags, int w, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(ag, char *);

	UNUSED(b);
	UNUSED(flags);
	UNUSED(w);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
	{
		len++;
	}

	if (precision >= 0 && precision < len)
	{
		len = precision;
	}

	if (w > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = w - len; i > 0; i--)
			{
				write(1, " ", 1);
			}
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
			{
				write(1, " ", 1);
			}
			write(1, &str[0], len);
			return (w);
		}
	}

	return (write(1, str, len));
}
/**
 * print_percent - Prints a percent sign
 * @ag: List of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list ag, char b[],
	int flags, int w, int precision, int size)
{
	UNUSED(ag);
	UNUSED(b);
	UNUSED(flags);
	UNUSED(w);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
