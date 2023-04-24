#include "main.h"

/**
 * get_size - Gets the size modifier from a format string
 * @format: format string
 * @index: pointer to index in format string
 * Return: size
 */
int get_size(const char *format, int *index)
{
	int size;

	size = 0;
	if (format[*index] == 'h')
	{
		size = SHORT_SIZE;
		*index += 1;
		if (format[*index] == 'h')
		{
			size = CHAR_SIZE;
			*index += 1;
		}
	}
	else if (format[*index] == 'l')
	{
		size = LONG_SIZE;
		*index += 1;
		if (format[*index] == 'l')
		{
			size = LONG_LONG_SIZE;
			*index += 1;
		}
	}
	else if (format[*index] == 'j')
	{
		size = INTMAX_SIZE;
		*index += 1;
	}
	else if (format[*index] == 'z')
	{
		size = SIZE_T_SIZE;
		*index += 1;
	}
	else if (format[*index] == 't')
	{
		size = PTRDIFF_T_SIZE;
		*index += 1;
	}
	else if (format[*index] == 'L')
	{
		size = LONG_DOUBLE_SIZE;
		*index += 1;
	}
	return (size);
}
