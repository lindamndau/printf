#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @w: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char b[],
	int flags, int w, int precision, int size)
{ 
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	{
		padd = '0';
	}

	b[i++] = c;
	b[i] = '\0';

	if (w > 1)
	{
		b[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w - 1; i++)
		{
			b[BUFF_SIZE - i - 2] = padd;
		}
		if (flags & F_MINUS)
		{
			return (write(1, &b[0], 1) +
					write(1, &b[BUFF_SIZE - i - 1], w - 1));
		}
		else
		{
			return (write(1, &b[BUFF_SIZE - i - 1], w - 1) +
					write(1, &b[0], 1));
		}
	}

	return (write(1, &b[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @w: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char b[],
	int flags, int w, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		padd = '0';
	}
	if (is_negative)
	{
		extra_ch = '-';
	}
	else if (flags & F_PLUS)
	{
		extra_ch = '+';
	}
	else if (flags & F_SPACE)
	{
		extra_ch = ' ';
	}

	return (write_num(ind, b, flags, w, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @b: Buffer
 * @flags: Flags
 * @w: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char b[],
	int flags, int w, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && b[ind] == '0' && w == 0)
	{
		return (0);
	}
	if (prec == 0 && ind == BUFF_SIZE - 2 && b[ind] == '0')
	{
		b[ind] = padd = ' '; 
	}
	if (prec > 0 && prec < length)
	{
		padd = ' ';
	}
	while (prec > length)
	{
		b[--ind] = '0', length++;
	}
	if (extra_c != 0)
	{
		length++;
	}
	if (width > length)
	{
		for (i = 1; i < w - length + 1; i++)
		{
			b[i] = padd;
		}
		b[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
			{
				b[--ind] = extra_c;
			}
			return (write(1, &b[ind], length) + write(1, &b[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
			{
				b[--ind] = extra_c;
			}
			return (write(1, &b[1], i - 1) + write(1, &b[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
			{
				b[--padd_start] = extra_c;
			}
			return (write(1, &b[padd_start], i - padd_start) +
				write(1, &b[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
	{
		b[--ind] = extra_c;
	}
	return (write(1, &b[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @b: Array of chars
 * @flags: Flags specifiers
 * @w: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char b[],
	int flags, int w, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && b[ind] == '0')
	{
		return (0); 
	}
	if (precision > 0 && precision < length)
	{
		padd = ' ';
	}

	while (precision > length)
	{
		b[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		padd = '0';
	}

	if (w > length)
	{
		for (i = 0; i < w - length; i++)
		{
			b[i] = padd;
		}

		b[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &b[0], i));
		}
		else 
		{
			return (write(1, &buffer[0], i) + write(1, &b[ind], length));
		}
	}

	return (write(1, &b[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @b: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @w: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char b[], int ind, int length,
	int w, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (w > length)
	{
		for (i = 3; i < w - length + 3; i++)
		{
			b[i] = padd;
		}
		b[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			b[--ind] = 'x';
			b[--ind] = '0';
			if (extra_c)
			{
				b[--ind] = extra_c;
			}
			return (write(1, &b[ind], length) + write(1, &b[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			b[--ind] = 'x';
			b[--ind] = '0';
			if (extra_c)
			{
				b[--ind] = extra_c;
			}
			return (write(1, &b[3], i - 3) + write(1, &b[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
			{
				b[--padd_start] = extra_c;
			}
			b[1] = '0';
			b[2] = 'x';
			return (write(1, &b[padd_start], i - padd_start) +
				write(1, &b[ind], length - (1 - padd_start) - 2));
		}
	}
	b[--ind] = 'x';
	b[--ind] = '0';
	if (extra_c)
	{
		b[--ind] = extra_c;
	}
	return (write(1, &b[ind], BUFF_SIZE - ind - 1));
}
