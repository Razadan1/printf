#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct convert - Struct to match the corresponding function.
 * @sp: The specifier symbol.
 * @f: The corresponding function for the conversion specifier
 */
struct convert
{
	char *sp;
	int (*f)(va_list);
};
typedef struct convert conver_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_percent(__attribute__((unused)) va_list args);

#endif
