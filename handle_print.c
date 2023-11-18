#include "main.h"

/**
 * handle_print - Handles printing an argument based on its type
 * @param format: Formatted string in which to print the arguments
 * @param index: Index of the current character in the format string
 * @param arg_list: List of arguments to be printed
 * @param buffer: Buffer array to store formatted output
 * @param flags: Bitmask of active flags (e.g., F_MINUS, F_ZERO)
 * @param width: Field width
 * @param precision: Precision value
 * @param size: Size modifier (e.g., S_SHORT, S_LONG)
 * @return: Number of characters printed or -1 if an error occurs
 */
int handle_print(const char *format, int *index, va_list arg_list, char buffer[],
                  int flags, int width, int precision, int size)
{
    int printed_chars = -1;
    int unknown_length = 0;

    fmt_t format_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent},
        {'i', print_int}, {'d', print_int}, {'b', print_binary},
        {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
        {'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
        {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
    };

    for (int i = 0; format_types[i].fmt != '\0'; i++) {
        if (format[*index] == format_types[i].fmt) {
            printed_chars = format_types[i].fn(arg_list, buffer, flags, width, precision, size);
            break;
        }
    }

 
    if (format_types[i].fmt == '\0') {
        if (format[*index] == '\0') {
            return -1;
        }

        unknown_length += write(1, "%%", 1);
        if (format[*index - 1] == ' ') {
            unknown_length += write(1, " ", 1);
        } else if (width) {
            --(*index); 

            while (format[*index] != ' ' && format[*index] != '%') {
                --(*index);
            }

            if (format[*index] == ' ') {
                --(*index); 
            }

            return 1; 
        }

        unknown_length += write(1, &format[*index], 1);
        return unknown_length;
    }

    return printed_chars;
}
