#include "main.h"
/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @ag: List a of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list ag, char b[],
	int flags, int w, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ag, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		b[i--] = '0';
	}

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, b, flags, w, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @ag: List of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list ag, char b[],
	int flags, int w, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ag, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		b[i--] = '0';
	}

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
	{
		b[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, b, flags, w, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @ag: Lista of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list ag, char b[],
	int flags, int w, int precision, int size)
{
	return (print_hexa(ag, "0123456789abcdef", b,
		flags, 'x', w, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @ag: Lista of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list ag, char b[],
	int flags, int w, int precision, int size)
{
	return (print_hexa(ag, "0123456789ABCDEF", b,
		flags, 'X', w, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @ag: List of arguments
 * @map_to: Array of values to map the number to
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @w: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list ag, char map_to[], char b[],
	int flags, char flag_ch, int w, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ag, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		b[i--] = '0';
	}

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		b[i--] = flag_ch;
		b[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, b, flags, w, precision, size));
}
