#include "main.h"

/**
 * get_width - Gets the width from a format string
 * @format: format string
 * @index: pointer to index in format string
 * @list: list of arguments
 * Return: width
 */
int get_width(const char *format, int *index, va_list list)
{
	int width;

	width = 0;
	if (format[*index] == '*')
	{
		width = va_arg(list, int);
		*index += 1;
	}
	else
	{
		while (format[*index] >= '0' && format[*index] <= '9')
		{
			width = width * 10 + (format[*index] - '0');
			*index += 1;
		}
	}
	return (width);
}
