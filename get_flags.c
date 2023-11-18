#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @n: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *n)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, index;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (index = *n + 1; format[index] != '\0'; index++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[index] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
		{
			break;
		}
	}

	*n = curr_i - 1;

	return (flags);
}
