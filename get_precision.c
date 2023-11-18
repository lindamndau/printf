#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @param format: Formatted string in which to print the arguments
 * @param index: Index of the current character in the format string
 * @param arg_list: List of arguments to be printed
 * @return: Precision: Precision value
 */
int get_precision(const char *format, int *index, va_list arg_list)
{
    // Initialize precision variable
    int precision = -1;

    // Check if the next character is a dot
    if (format[*index + 1] != '.') {
        return precision;
    }

    // Set precision to 0
    precision = 0;

    // Iterate through the format string starting from the character after the '.'
    for (int curr_index = *index + 2; format[curr_index] != '\0'; curr_index++) {
        // Check if the current character is a digit
        if (isdigit(format[curr_index])) {
            precision *= 10;
            precision += format[curr_index] - '0';
        }
        // Check if the current character is an asterisk
        else if (format[curr_index] == '*') {
            // Move to the next character
            curr_index++;

            // Extract the precision value from the argument list
            precision = va_arg(arg_list, int);
            break;
        }
        // If the character is not a digit or an asterisk, break the loop
        else {
            break;
        }
    }

    // Update the index variable with the position of the last processed character
    *index = curr_index - 1;

    return precision;
}
