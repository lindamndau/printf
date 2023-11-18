#include "main.h"
#include <stdarg.h>

void print_buffer(char buffer[], int *buffer_index);

/*
 * _printf - Print formatted output to the console.
 *
 * @format: The format string to print according to.
 *
 * @return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int index, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buffer_index = 0;
    va_list arguments;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(arguments, format);

    for (index = 0; format && format[index] != '\0'; index++)
    {
        if (format[index] != '%')
        {
            buffer[buffer_index++] = format[index];
            if (buffer_index == BUFF_SIZE)
                print_buffer(buffer, &buffer_index);
            /* write(1, &format[index], 1);*/
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buffer_index);
            flags = get_flags(format, &index);
            width = get_width(format, &index, arguments);
            precision = get_precision(format, &index, arguments);
            size = get_size(format, &index);
            ++index;
            printed = handle_print(format, &index, arguments, buffer,
                                    flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buffer_index);

    va_end(arguments);

    return (printed_chars);
}

/*
 * print_buffer - Prints the contents of the buffer if it is not empty.
 *
 * @buffer: The array of characters to print.
 * @buffer_index: The index at which to add the next character, representing the length.
 */

void
 
print_buffer(char buffer[], int *buffer_index)

{
    if (*buffer_index > 0)
        write(1, &buffer[0], *buffer_index);

    *buffer_index = 0;
}
