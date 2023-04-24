#include "main.h"

/************************* PRINT CHAR *************************/
/**
 * print_char - Prints a char
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_char(va_list list, char *buffer, int *index)
{
	char character;

	character = va_arg(list, int);
	buffer[*index] = character;
	*index += 1;
}

/************************* PRINT STRING *************************/
/**
 * print_string - Prints a string
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_string(va_list list, char *buffer, int *index)
{
	char *string;
	int i;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i] != '\0'; i++)
	{
		buffer[*index] = string[i];
		*index += 1;
	}
}

/************************* PRINT PERCENTAGE SIGN *************************/
/**
 * print_percentage - Prints a percentage sign
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_percentage(__attribute__((unused))va_list list,
		      char *buffer, int *index)
{
	buffer[*index] = '%';
	*index += 1;
}

/************************* PRINT INTEGER *************************/
/**
 * print_integer - Prints an integer
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_integer(va_list list, char *buffer, int *index)
{
	int number;
	unsigned int temp, digit, base;

	number = va_arg(list, int);
	digit = 0;
	base = 1;
	if (number < 0)
	{
		temp = -number;
		buffer[*index] = '-';
		digit++;
	}
	else
		temp = number;
	while (temp > 0)
	{
		temp /= 10;
		base *= 10;
		digit++;
	}
	if (number == 0)
	{
		buffer[*index] = '0';
		digit++;
	}
	while (digit > 0)
	{
		temp = number < 0 ? -number : number;
		base /= 10;
		buffer[*index] = ((temp / base) % 10) + '0';
		digit--;
		*index += 1;
	}
}
