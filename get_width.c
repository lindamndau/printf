#include "main.h"
#include <stdarg.h>

/**
 * get_width - Calculates the field width for printing
 * @param format: Formatted string in which to print the arguments
 * @param index: Index of the current character in the format string
 * @param arg_list: List of arguments to be printed
 * @return: Width: Field width value
 */
int get_width(const char *format, int *index, va_list arg_list)
{
    // Initialize field width variable
    int width = 0;

    // Iterate through the format string starting from the character after the '%'
    for (int curr_index = *index + 1; format[curr_index] != '\0'; curr_index++) {
        // Check if the current character is a digit
        if (isdigit(format[curr_index])) {
            width *= 10;
            width += format[curr_index] - '0';
        }
        // Check if the current character is an asterisk
        else if (format[curr_index] == '*') {
            // Move to the next character
            curr_index++;

            // Extract the width value from the argument list
            width = va_arg(arg_list, int);
            break;
        }
        // If the character is not a digit or an asterisk, break the loop
        else {
            break;
        }
    }

    // Update the index variable with the position of the last processed character
    *index = curr_index - 1;

    return width;
}
