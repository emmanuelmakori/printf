#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int index, chars_printed, total_chars_printed;
	int flags, width, precision, size, buffer_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buffer_index++] = format[index];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			/* write(1, &format[index], 1);*/
			total_chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &index);
			width = get_width(format, &index, list);
			precision = get_precision(format, &index, list);
			size = get_size(format, &index);
			++index;
			chars_printed = handle_print(format, &index, list, buffer,
				flags, width, precision, size);
			if (chars_printed == -1)
				return (-1);
			total_chars_printed += chars_printed;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (total_chars_printed);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffer_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
