#include "main.h"
/*
 * print_unsigned - Prints an unsigned integer.
 *
 * @types: The list of arguments.
 * @buffer: The buffer array to handle the printing.
 * @flags: The calculated active flags.
 * @width: The width of the field.
 * @precision: The precision specification.
 * @size: The size specifier.
 *
 * @return: The number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
                  int flags, int width, int precision, int size)
{
    int index = BUFF_SIZE - 2;
    unsigned long int value = va_arg(types, unsigned long int);

    value = convert_size_unsigned(value, size);

    if (value == 0) {
        buffer[index--] = '0';
    }

    buffer[BUFF_SIZE - 1] = '\0';

    while (value > 0) {
        buffer[index--] = (value % 10) + '0';
        value /= 10;
    }

    index++;

    return write_unsigned(0, index, buffer, flags, width, precision, size);
}

/*
 * print_octal - Prints an unsigned integer in octal notation.
 *
 * @types: The list of arguments.
 * @buffer: The buffer array to handle the printing.
 * @flags: The calculated active flags.
 * @width: The width of the field.
 * @precision: The precision specification.
 * @size: The size specifier.
 *
 * @return: The number of characters printed.
 */
int print_octal(va_list types, char buffer[],
               int flags, int width, int precision, int size)
{
    int index = BUFF_SIZE - 2;
    unsigned long int value = va_arg(types, unsigned long int);
    unsigned long int initialValue = value;

    UNUSED(width);

    value = convert_size_unsigned(value, size);

    if (value == 0) {
        buffer[index--] = '0';
    }

    buffer[BUFF_SIZE - 1] = '\0';

    while (value > 0) {
        buffer[index--] = (value % 8) + '0';
        value /= 8;
    }

    if (flags & F_HASH && initialValue != 0) {
        buffer[index--] = '0';
    }

    index++;

    return write_unsigned(0, index, buffer, flags, width, precision, size);
}

/*
 * print_hexadecimal - Prints an unsigned integer in hexadecimal notation.
 *
 * @types: The list of arguments.
 * @buffer: The buffer array to handle the printing.
 * @flags: The calculated active flags.
 * @width: The width of the field.
 * @precision: The precision specification.
 * @size: The size specifier.
 *
 * @return: The number of characters printed.
 */

int
 
print_hexadecimal(va_list types, char buffer[],
                  int flags, int width, int precision, int
 
size)

{
    return print_hexa(types,
 
"0123456789abcdef", buffer,
        flags, 'x', width, precision, size);
}

/*
 * print_hexa_upper - Prints an unsigned integer in hexadecimal notation with uppercase letters.
 *
 * @types: The list of arguments.
 * @buffer: The buffer array to handle the printing.
 * @flags: The calculated active flags.
 * @width: The width of the field.
 * @precision: The precision specification.
 * @size: The size specifier.
 *
 * @return: The number of characters printed.
 */

int
 
print_hexa_upper(va_list types, char buffer[],
                    int flags, int width, int precision, int size)

{
    return print_hexa(types, "0123456789ABCDEF", buffer,
        flags, 'X', width, precision, size);
}
