#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - returns the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int index = 0;

	while (s[index])
		index++;
	return (index);
}

/**
 * _abs - returns the absolute value of an integer
 * @n: the integer to evaluate
 *
 * Return: the absolute value of n
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/**
 * _pow - returns the power of a number raised to an exponent
 * @base: the base number
 * @exponent: the exponent number
 *
 * Return: the result of base raised to exponent
 */
int _pow(int base, int exponent)
{
	int result = 1;

	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}
