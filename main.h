#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define BUFF_SIZE 1024
/**
 * struct - fmt
 * @fmt - Format
 * fn() - assosiated function
 */
struct fmt;
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


int _printf(const char *format, ...);

#endif
