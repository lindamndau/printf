#include "main.h"

/**
* get_flags - Calculates active flags
* @param format: Formatted string in which to print the arguments
* @param index: Index of the current character in the format string
* @return: Flags: Active flags
*/
int get_flags(const char *format, int *index)
{
    /* Character to flag mapping */
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    int flags = 0;
    int curr_index = *index + 1;

    // Iterate through the format string starting from the character after the '%'
    while (format[curr_index] != '\0')
    {
        // Check if the current character is a valid flag character
        for (int j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (format[curr_index] == FLAGS_CH[j])
            {
                // Set the corresponding flag bit
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        // Exit the loop if no valid flag character was found
        if (FLAGS_CH[j] == '\0')
        {
            break;
        }

        // Move to the next character in the format string
        curr_index++;
    }

    // Update the index variable with the position of the last processed character
    *index = curr_index - 1;

    return flags;
}
