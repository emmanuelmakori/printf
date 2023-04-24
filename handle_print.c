#include "main.h"

/**
 * handle_print - prints a formatted string
 * @format: the format string
 * @args: the list of arguments
 * @buffer: the buffer to store the output
 * @buffer_index: the index of the buffer
 * Return: the number of characters printed
 */
int handle_print(const char *format, va_list args, char *buffer, int buffer_index)
{
	int index = 0;
	int chars_printed = 0;
	int total_chars_printed = 0;
	char character;
	char *string;
	int number;
	int digit;
	int base;
	int temp;

	while (format && format[index])
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] == '\0')
				return (-1);
			switch (format[index])
			{
				case 'c':
					character = va_arg(args, int);
					chars_printed = print_char(buffer, buffer_index, character);
					break;
				case 's':
					string = va_arg(args, char *);
					chars_printed = print_string(buffer, buffer_index, string);
					break;
				case 'd':
				case 'i':
					number = va_arg(args, int);
					digit = count_digits(number, 10);
					chars_printed = print_number(buffer, buffer_index, number, digit, 10);
					break;
				case 'b':
					number = va_arg(args, int);
					digit = count_digits(number, 2);
					chars_printed = print_number(buffer, buffer_index, number, digit, 2);
					break;
				default:
					buffer[buffer_index] = '%';
					buffer_index++;
					buffer[buffer_index] = format[index];
					buffer_index++;
					chars_printed = 2;
			}
			index++;
			total_chars_printed += chars_printed;
			buffer_index += chars_printed;
		}
		else
		{
			buffer[buffer_index] = format[index];
			index++;
			buffer_index++;
			total_chars_printed++;
		}
	}
	return (total_chars_printed);
}

/**
 * count_digits - counts the number of digits in a number
 * @number: the number to count
 * @base: the base of the number system
 * Return: the number of digits
 */
int count_digits(int number, int base)
{
	int digit = 0;
	int temp = number;

	while (temp != 0)
	{
		digit++;
		temp /= base;
	}
	if (number < 0)
		digit++;
	return (digit);
}
