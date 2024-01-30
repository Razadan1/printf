#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
  * main - Entry and testing point
  *
  * Return: return  0
  */

int main(void)
{
	int lenght;
	int lenght2;
	unsigned int uint;
	void *address;

	lenght = _printf("Let's try to printf a simple sentence.\n");
	lenght2 = printf("Let's try to printf a simple sentence.\n");
	uint = (unsigned int)INT_MAX + 1024;
	address = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", lenght, lenght);
	printf("Length:[%d, %i]\n", lenght2, lenght2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", uint);
	printf("Unsigned:[%u]\n", uint);
	_printf("Unsigned octal:[%o]\n", uint);
	printf("Unsigned octal:[%o]\n", uint);
	_printf("Unsigned hexadecimal:[%x, %X]\n", uint, uint);
	printf("Unsigned hexadecimal:[%x, %X]\n", uint, uint);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", address);
	printf("Address:[%p]\n", address);
	lenght = _printf("Percent:[%%]\n");
	lenght2 = printf("Percent:[%%]\n");
	_printf("Lenght:[%d]\n", lenght);
	printf("Lenght:[%d]\n", lenght2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}
