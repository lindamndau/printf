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
typedef struct fmt fmt_t;
/* SIZES */
#define S_SHORT 1
#define S_LONG 2

/* FLAGS */
#define F_SPACE 16
#define F_HASH 8
#define F_ZERO 4
#define F_PLUS 2
#define F_MINUS 1
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list ag, char b[], int flags, int w, int precision, int size);
int _printf(const char *format, ...);
int print_char(va_list ag, char b[],
	int flags, int w, int precision, int size);
int print_string(va_list ag, char b[],
	int flags, int w, int precision, int size);
int print_percent(va_list ag, char b[],
	int flags, int w, int precision, int size);

/* Functions to print numbers */
int print_int(va_list ag, char b[],
	int flags, int w, int precision, int size);
int print_binary(va_list ag, char b[],
	int flags, int w, int precision, int size);
int print_unsigned(va_list ag, char b[],
	int flags, int w, int precision, int size);
int print_octal(va_list ag, char b[],
	int flags, int w, int precision, int size);
int print_hexadecimal(va_list ag, char b[],
	int flags, int w, int precision, int size);
int print_hexa_upper(va_list ag, char b[],
	int flags, int w, int precision, int size);

int print_hexa(va_list ag, char map_to[],
char b[], int flags, char flag_ch, int w, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list ag, char b[],
	int flags, int w, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list ag, char b[],
	int flags, int wh, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list ag);
int get_precision(const char *format, int *i, va_list ag);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list ag, char b[],
	int flags, int w, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list ag, char b[],
	int flags, int w, int precision, int size);

/* width handler */
int handle_write_char(char c, char b[],
	int flags, int w, int precision, int size);
int write_number(int is_positive, int index, char b[],
	int flags, int w, int precision, int size);
int write_num(int index, char b[], int flags, int w, int precision,
	int length, char padd, char extra_c);
int write_pointer(char b[], int index, int len,
	int w, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int index,
char b[],
	int flags, int w, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
