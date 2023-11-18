#include "main.h"

/**
 * is_printable - Checks whether a character is printable
 * @param c: Character to evaluate
 * @return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c) {
    // Check if the character is within the printable ASCII range (32 to 126)
    if (c >= 32 && c < 127) {
        return 1;
    }

    return 0;
}

/**
 * append_hexa_code - Appends the hexadecimal representation of an ASCII code to a buffer
 * @param buffer: Character array to append the hexadecimal code to
 * @param index: Starting index in the buffer for appending
 * @param ascii_code: ASCII code to convert to hexadecimal
 * @return: Number of characters appended (always 3)
 */
int append_hexa_code(char ascii_code, char buffer[], int index) {
    // Mapping table for hexadecimal conversion
    const char map_to[] = "0123456789ABCDEF";

    // Handle negative ASCII codes
    if (ascii_code < 0) {
        ascii_code *= -1;
    }

    // Append the backslash and 'x' for hexadecimal formatting
    buffer[index++] = '\\';
    buffer[index++] = 'x';

    // Extract and append the hexadecimal digits
    buffer[index++] = map_to[ascii_code / 16];
    buffer[index] = map_to[ascii_code % 16];

    return 3; // Number of characters appended
}

/**
 * is_digit - Checks whether a character is a digit (0-9)
 * @param c: Character to evaluate
 * @return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }

    return 0;
}

/**
 * convert_size_number - Converts a number to the specified size (short, int, or long)
 * @param num: Number to be converted
 * @param size: Size specifier indicating the target data type
 * @return: Converted value of num according to the specified size
 */
long int convert_size_number(long int num, int size) {
    switch (size) {
        case S_LONG:
            return num;

        case S_SHORT:
            return (short)num;

        default:
            return (int)num;
    }
}

/**
 * convert_size_unsgnd - Converts an unsigned number to the specified size (short, int, or long)
 * @param num: Unsigned number to be converted
 * @param size: Size specifier indicating the target data type
 * @return: Converted value of num according to the specified size
 */
long int convert_size_unsgnd(unsigned long int num, int size) {
    switch (size) {
        case S_LONG:
            return num;

        case S_SHORT:
            return (unsigned short)num;

        default:
            return (unsigned int)num;
    }
}
