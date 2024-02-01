#include "main.h"

/**
 * specifierArray - holds the specifier_array
 * @ch: arguement
 * @ind: the counts
 * @arglist: the micro
 * Return: return nothing
*/
int specifierArray(const char *ch, int ind, va_list arglist)
{
	int count, lenght = 0, p_chars = -1;
	specifier Spec_arr[] = {
		{"c", check_c},
		{"s", check_s},
		{"%", check_per},
		{NULL, NULL}
	};


	for (count = 0; Spec_arr[count].values; count++)
	{
		if (Spec_arr[count].values == ch)
			return (Spec_arr[count].func(arglist));
	}
	if (Spec_arr[count].values == NULL)
	{
		if (ch[ind] == '\0')
			return (-1);
		lenght += write(1, "%%", 1);
		if (ch[ind - 1] == ' ')
			lenght += write(1, " ", 1);
		lenght += write(1, &ch[ind], 1);

		return (lenght);
	}
	return (p_chars);
}
