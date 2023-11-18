#include "main.h"
/*
 * print_char - Prints a character.
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
 
print_char(va_list types, char buffer[],
              int flags, int width, int precision, int size)

{
    char character = va_arg(types, int);

    return handle_write_char(character, buffer, flags, width, precision, size);
}

/*
 * print_string - Prints a string.
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
 
print_string(va_list types, char buffer[],
              int flags, int width, int precision, int size)

{
    int length = 0, index;
    char *string = va_arg(types, char *);

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (string == NULL) {
        string = "(null)";
        if (precision >= 6) {
            string = "   ";
        }
    }

    while (string[length] != '\0') {
        length++;
    }

    if (precision >= 0 && precision < length) {
        length = precision;
    }

    if (width > length) {
        if (flags & F_MINUS) {
            write(1, &string[0], length);
            for (index = width - length; index > 0; index--) {
                write(1, " ", 1);
            }
            return (width);
        } else {
            for (index = width - length; index > 0; index--) {
                write(1, " ", 1);
            }
            write(1, &string[0], length);
            return (width);
        }
    }

    return (write(1, string, length));
}

/*
 * print_percent - Prints a percent sign.
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

int print_percent(va_list types, char buffer[],
              int flags, int width, int precision, int size)

{
    UNUSED(types);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return (write(1, "%%", 1));
}

/*
 * print_int - Prints an integer.
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
int print_int(va_list types, char buffer[],
              int flags, int width, int precision, int size)
{
    int index = BUFF_SIZE - 2;
    int isNegative = 0;
    long int number = va_arg(types, long int);
    unsigned long int value;

    number = convert_size_number(number, size);

    if (number == 0) {
        buffer[index--] = '0';
    }

    buffer[BUFF_SIZE - 1] = '\0';
    value = (unsigned long int)number;

    if (number < 0) {
        value = (unsigned long int)((-1) * number);
        isNegative = 1;
    }
