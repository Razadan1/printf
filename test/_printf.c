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
	int count, prints = 0, printed_c = 0;

	va_list arglist;

	if (format == NULL)
		return (-1);

	va_start(arglist, format);

	for (count = 0; format[count] != '\0'; count++)
	{
		if (format[count] == '%')
		{
			count++;
			prints = specifierArray(format, count, arglist);
			if (prints == -1)
				return (-1);
			printed_c += prints;
		}
		else
		{
			write(1, &format[count], 1);
			printed_c++;
		}

	}
	va_end(arglist);

	return (printed_c);
}
