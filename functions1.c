#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned_number - Prints an unsigned number
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_unsigned_number(va_list list, char *buffer, int *index)
{
	unsigned int number;
	unsigned int temp, digit, base;

	number = va_arg(list, unsigned int);
	digit = 0;
	base = 1;
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
		base /= 10;
		buffer[*index] = ((number / base) % 10) + '0';
		digit--;
		*index += 1;
	}
}

/************************* PRINT OCTAL NUMBER *************************/
/**
 * print_octal_number - Prints a number in octal base
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_octal_number(va_list list, char *buffer, int *index)
{
	unsigned int number;
	unsigned int temp, digit, base;

	number = va_arg(list, unsigned int);
	digit = 0;
	base = 1;
	temp = number;
	while (temp > 0)
	{
		temp /= 8;
		base *= 8;
		digit++;
	}
	if (number == 0)
	{
		buffer[*index] = '0';
		digit++;
	}
	while (digit > 0)
	{
		base /= 8;
		buffer[*index] = ((number / base) % 8) + '0';
		digit--;
		*index += 1;
	}
}

/************************* PRINT HEXADECIMAL NUMBER LOWERCASE *************************/
/**
 * print_hexadecimal_number_lowercase - Prints a number in hexadecimal base in lowercase
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_hexadecimal_number_lowercase(va_list list, char *buffer, int *index)
{
	unsigned int number;
	unsigned int temp, digit, base;

	number = va_arg(list, unsigned int);
	digit = 0;
	base = 1;
	temp = number;
	while (temp > 0)
	{
		temp /= 16;
		base *= 16;
		digit++;
	}
	if (number == 0)
	{
		buffer[*index] = '0';
		digit++;
	}
	while (digit > 0)
	{
		base /= 16;
                temp = (number / base) % 16;
                if (temp < 10)
                        buffer[*index] = temp + '0';
                else
                        buffer[*index] = temp - 10 + 'a';
                digit--;
                *index += 1;
        }
}

/************************* PRINT HEXADECIMAL NUMBER UPPERCASE *************************/
/**
 * print_hexadecimal_number_uppercase - Prints a number in hexadecimal base in uppercase
 * @list: list of arguments
 * @buffer: array that stores string
 * @index: pointer to number of characters
 */
void print_hexadecimal_number_uppercase(va_list list, char *buffer, int *index)
{
	unsigned int number;
	unsigned int temp, digit, base;

	number = va_arg(list, unsigned int);
	digit = 0;
	base = 1;
	temp = number;
	while (temp > 0)
        {
                temp /= 16;
                base *= 16;
                digit++;
        }
        if (number == 0)
        {
                buffer[*index] = '0';
                digit++;
        }
        while (digit > 0)
        {
                base /= 16;
                temp = (number / base) % 16;
                if (temp < 10)
                        buffer[*index] = temp + '0';
                else
                        buffer[*index] = temp - 10 + 'A';
                digit--;
                *index += 1;
        }
}
