#include "main.h"
/*
 * print_pointer - Prints the value of a pointer variable.
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
 
print_pointer(va_list types, char buffer[],
              int flags, int width, int precision, int size)

{
    char extraCharacter = 0, padding = ' ';
    int index = BUFF_SIZE - 2, length = 2, paddingStart = 1;
    unsigned long pointerAddress;
    char *mapToString = "0123456789abcdef";
    void *addresses = va_arg(types, void *);

    UNUSED(width);
    UNUSED(size);

    if (addresses == NULL) {
        return write(1, "(nil)", 5);
    }

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    pointerAddress = (unsigned long)addresses;

    while (pointerAddress > 0) {
        buffer[index--] = mapToString[pointerAddress % 16];
        pointerAddress /= 16;
        length++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS)) {
        padding = '0';
    }

    if (flags & F_PLUS) {
        extraCharacter = '+';
        length++;
    } else if (flags & F_SPACE) {
        extraCharacter = ' ';
        length++;
    }

    index++;

    return write_pointer(buffer, index, length,
                         width, flags, padding, extraCharacter, paddingStart);
}

/*
 * print_non_printable - Prints ASCII codes in hexadecimal format for non-printable characters.
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
int print_non_printable(va_list types, char buffer[],
              int flags, int width, int precision, int size)
{
    int index = 0, offset = 0;
    char *string = va_arg(types, char *);

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (string == NULL) {
        return write(1, "(null)", 6);
    }

    while (string[index] != '\0') {
        if (is_printable(string[index])) {
            buffer[index + offset] = string[index];
        } else {
            offset += append_hexa_code(string[index], buffer, index + offset);
        }

        index++;
    }

    buffer[index + offset] = '\0';

    return write(1, buffer, index + offset);
}

/*
 * print_reverse - Prints a string in reverse.
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
int print_reverse(va_list types, char buffer[],
              int flags, int width, int precision, int size)
{
    char *string;
    int index, count = 0;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(size);

    string = va_arg(types, char *);

    if (string == NULL) {
        UNUSED(precision);
        string = ")Null(";
    }

    for (index = 0; string[index]; index++) ;

    for (index = index - 1; index >= 0; index--) {
        char character = string[index];

        write(1, &character, 1);
        count++;
    }

    return
}
