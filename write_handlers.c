#include "main.h"

/**
 * write_char - writes a character to the buffer
 * @buffer: the buffer to write to
 * @buffer_index: the index of the buffer
 * @character: the character to write
 */
void write_char(char *buffer, int buffer_index, char character)
{
	buffer[buffer_index] = character;
}

/**
 * write_string - writes a string to the buffer
 * @buffer: the buffer to write to
 * @buffer_index: the index of the buffer
 * @string: the string to write
 */
void write_string(char *buffer, int buffer_index, char *string)
{
	int index = 0;

	while (string[index])
	{
		buffer[buffer_index] = string[index];
		index++;
		buffer_index++;
	}
}

/**
 * write_number - writes a number to the buffer
 * @buffer: the buffer to write to
 * @buffer_index: the index of the buffer
 * @number: the number to write
 */
void write_number(char *buffer, int buffer_index, int number)
{
	int digit;
	int temp;
	int base = 10;

	if (number < 0)
	{
		write_char(buffer, buffer_index, '-');
		buffer_index++;
		number = -number;
	}
	temp = number;
	while (temp != 0)
	{
		digit = temp % base;
		write_char(buffer, buffer_index, digit + '0');
		buffer_index++;
		temp /= base;
	}
	reverse_buffer(buffer, buffer_index);
}

/**
 * reverse_buffer - reverses a portion of the buffer
 * @buffer: the buffer to reverse
 * @end: the end index of the portion to reverse
 */
void reverse_buffer(char *buffer, int end)
{
	int start = 0;
	char temp;

	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
}
