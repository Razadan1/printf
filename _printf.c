#include "main.h"

/**
 * _printf - Prints the given arguments.
 * @format: The format specifier corresponding to the input argument.
 *
 * Return: The number of printed characters.
 */
int _printf(const char *format, ...)
{
	conver_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			int i;

			format++;
			for (i = 0; specifiers[i].sp != NULL; i++)
			{
				if (*format == *specifiers[i].sp)
				{
					count += specifiers[i].f(args);
					break;
				}
			}
		if (specifiers[i].sp == NULL)
			count += write(1, format - 1, 2);
		}
		else
			count += write(1, format, 1);
		format++;
	}

	va_end(args);
	return (count);
}
