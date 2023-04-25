#include "main.h"

void print_buffer(char buff[], int *buff_ind);

/**
 * _printf - Printf function shows a printed string 
 * @formatthis forgood text: format.
 * Return:this returns the Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buff, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buff, &buff_ind);
			flags = flags(format, &i);
			width = width(format, &i, list);
			precision = precision(format, &i, list);
			size = size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buff,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buff, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buff[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buff[0], *buff_ind);

	*buff_ind = 0;
}
