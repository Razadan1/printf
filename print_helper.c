#include "main.h"

/**
 * print_char - Prints a character.
 * @args: The arguments passed to the _printf function.
 *
 * Return: The number of characters.
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @args: The arguments passed to the _printf function.
 *
 * Return: The number of characters.
 */
int print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (*str)
		count += write(1, str++, 1);
	
	return (count);
}

/**
 * print_int - Prints an integer.
 * @args: The arguments passed to the _printf function.
 *
 * Return: The number of characters.
 */
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
		count += write(1, &num[len], 1);
	
	return (count);
}
