#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/*Struct*/
/**
 * struct specifier - structure for the project
 *
 * @func: the pointer function
 * @values: the values
 * Return: return nothing
*/

typedef struct specifier
{
	char *values;
	int (*func)(va_list);
} specifier;

int _printf(const char *format, ...);
int specifierArray(const char *ch, int ind, va_list arglist);

/*****FUNCTIONS****/
int _putchar(char c);
int check_per(va_list type);
int check_c(va_list type);
int check_s(va_list type);



#endif /*MAIN_H*/
