#include "main.h"

/**
 * check_c - handler for c
 * @type: the arguement
 * Return: void
*/
int check_c(va_list type)
{
	char c = va_arg(type, int);

	write(1, &c, 1);

	return (1);
}

/**
 * check_s - handler for s
 * @type: the arguement
 * Return: void
*/
int check_s(va_list type)
{
	char  *str = va_arg(type, char *);
	int a = 0;

	if (str == NULL)
		str = "(null)";
	while (str[a] != '\0')
	{
		write(1, &str[a], 1);
		a++;
	}
	return (a);
}
/**
 * check_per - handler for percent %
 * @type: the arguement
 * Return: void
*/
int check_per(va_list type)
{
	(void)type;
	write(1, "%", 1);

	return (1);
}
