#include "main.h"

/**
* _printf - produces output according to formats
*
* @format: the format
*
* Return: return the number of characters printed.
*/
int _printf(const char *format, ...)
{
	int prints = 0;
	va_list arglist;

	va_start(arglist, format);

	while (*format != '\0')
	{
		if (format[0] == '%' && !format[1])
			return (-1);
		if (format[0] == '%' && format[1] == ' ' && !format[2])
			return (-1);

		if (format[0] == '%')
		{
			if (format[1] == 's')
			{
				const char *str = va_arg(arglist, const char*);

				prints += write(1, str, strlen(str)), format += 2;
			}
			else if (format[1] == 'c')
				prints += write(1, va_arg(arglist, char*), 1), format += 2;
			else if (format[1] == '%')
				prints += write(1, "%", 1), format += 2;
			else
				break;
		}
		else
			prints += write(1, format++, 1);
	}
	va_end(arglist);

	return (prints);
}
