#include "main.h"

/**
 * get_precision - Gets the precision from a format string
 * @format: format string
 * @index: pointer to index in format string
 * @list: list of arguments
 * Return: precision
 */
int get_precision(const char *format, int *index, va_list list)
{
	int precision;

	precision = 0;
	if (format[*index] == '.')
	{
		*index += 1;
		if (format[*index] == '*')
		{
			precision = va_arg(list, int);
			*index += 1;
		}
		else
		{
			while (format[*index] >= '0' && format[*index] <= '9')
			{
				precision = precision * 10 + (format[*index] - '0');
				*index += 1;
			}
		}
	}
	return (precision);
}
