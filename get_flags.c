#include "main.h"

/**
 * get_flags - Gets the flags from a format string
 * @format: format string
 * @index: pointer to index in format string
 * Return: flags
 */
int get_flags(const char *format, int *index)
{
	int flags;

	flags = 0;
	while (format[*index] == '+' || format[*index] == ' ' ||
	       format[*index] == '#' || format[*index] == '0' ||
	       format[*index] == '-')
	{
		if (format[*index] == '+')
			flags |= PLUS_FLAG;
		if (format[*index] == ' ')
			flags |= SPACE_FLAG;
		if (format[*index] == '#')
			flags |= HASH_FLAG;
		if (format[*index] == '0')
			flags |= ZERO_FLAG;
		if (format[*index] == '-')
			flags |= MINUS_FLAG;
		*index += 1;
	}
	return (flags);
}
