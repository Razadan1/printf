#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints the output according to a format
 *
 * @format: the format
 * Return: retunr nothing
 */
int _printf(const char *format, ...)
{
	va_list arglists;
	int counts = 0;

	va_start(arglists, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					counts += putchar(va_arg(arglists, int));
					break;
				case 's':
					counts += printf("%s", va_arg(arglists, char *));
					break;
				case '%':
					counts += putchar('%');
					break;
				default:
					counts += putchar('%');
					counts += putchar(*format);
			}
		}
		else
		{
			counts += putchar(*format);
		}
		format++;
	}
	va_end(arglists);
	return (counts);
}
