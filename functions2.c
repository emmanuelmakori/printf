#include "main.h"

/************************* PRINT STRING REVERSE *************************/
/**
 * print_string_reverse - Prints a string in reverse
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_string_reverse(va_list list, char *buffer, int *index)
{
	char *string;
	int i, length;

	string = va_arg(list, char *);
	if (string == NULL)
		string = ")llun(";
	length = _strlen(string);
	for (i = length - 1; i >= 0; i--)
	{
		buffer[*index] = string[i];
		*index += 1;
	}
}

/************************* PRINT ROT13 STRING *************************/
/**
 * print_rot13 - Prints a string in rot13
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_rot13(va_list list, char *buffer, int *index)
{
	char *string;
	int i;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i] != '\0'; i++)
	{
		if ((string[i] >= 'a' && string[i] <= 'z') ||
		    (string[i] >= 'A' && string[i] <= 'Z'))
			buffer[*index] = output[_strchr(input, string[i])];
		else
			buffer[*index] = string[i];
		*index += 1;
	}
}

/************************* PRINT STRING IN BINARY *************************/
/**
 * print_binary - Prints a number in binary base
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_binary(va_list list, char *buffer, int *index)
{
	unsigned int number;
	unsigned int temp, digit, base;

	number = va_arg(list, unsigned int);
	digit = 0;
	base = 1;
	temp = number;
	while (temp > 0)
	{
		temp /= 2;
		base *= 2;
		digit++;
	}
	if (number == 0)
	{
		buffer[*index] = '0';
		digit++;
	}
	while (digit > 0)
	{
		base /= 2;
		buffer[*index] = ((number / base) % 2) + '0';
		digit--;
		*index += 1;
	}
}
