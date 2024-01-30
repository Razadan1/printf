#include "main.h"
#include <stdio.h>

int main(void)
{
	printf("Hello, %s! This is a %c example. The value is %%.\n", "world", 'C');
	_printf("Hello, %s! This is a %c example. The value is %%.\n", "world", 'C');
	return 0;
}
