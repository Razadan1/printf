#include "main.h"

int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (write(1, &c, 1));
}

int print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += write(1, str++, 1);
	}
	return (count);
}

int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	char num[10];
	int tmp = n;
	int len = 0;

	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		count += write(1, "-", 1);
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		num[len++] = (tmp % 10) + '0';
		tmp /= 10;
	}
	while (len--)
	{
		count += write(1, &num[len], 1);
	}
	return (count);
}

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
