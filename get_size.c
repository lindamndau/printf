#include "main.h"

/**
 * get_size - Calculates the size modifier for formatting an argument
 * @param format: Formatted string in which to print the arguments
 * @param index: Index of the current character in the format string
 * @return: Size modifier: Size modifier code (S_SHORT or S_LONG)
 */
int get_size(const char *format, int *index)
{
    // Initialize size modifier
    int size = 0;

    // Check the next character after the '%'
    if (format[*index + 1] == 'l') {
        size = S_LONG;
    }
    else if (format[*index + 1] == 'h') {
        size = S_SHORT;
    }

    // Update the index variable accordingly
    if (size == 0) {
        *index = *index - 1;
    }
    else {
        *index = *index + 1;
    }

    return size;
}
