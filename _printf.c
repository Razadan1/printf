#include "main.h"

/**
 * _printf -  this produces output according to the format
 *
 * @format: the formats
 * Return: return char
 */
int _printf(const char *format, ...)
{
	va_list arg_lists;
	va_start (arg_lists, format);

	int counts = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					counts += write(1, &va_arg(arg_lists, int), 1);
					break;
				case 's':
					{
						const char *str = va_args(arg_lists, const char *);
						counts += write(1, str, strlen(str));
					}
					break;
				case '%':
					counts += write(1, "%", 1);
					break;
				defaults:
					break;
			}
		}
		else
		{
			counts += write(1, format, 1);
		}
		format++;
	}
	va_end(arg_lists);
	return (counts);
}
