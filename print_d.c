#include "main.h"

/**
 * print_d - prints a number
 * @num: the number to print
 * Return: the length of the number
 */

int print_d(int num)
{
	int len = 0, i;
	int digits[10];

	while (num > 0)
	{
		digits[len] = num % 10;
		num /= 10;
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(digits[i] + '0');
	}
	return (len);
}

