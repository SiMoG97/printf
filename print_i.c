#include "main.h"

/**
 * print_hex - prints an unsigned int in hexadecimal form
 * @n: unsigned int to print
 * @c: flag to determine case of printing (0 = lower, 1 = upper)
 *
 * Return: number of digits printed
 */
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int a[8];
	unsigned int i, m = 268435456; /* (16 ^ 7) */
	char diff = c ? 'A' - ':' : 'a' - ':';
	int count = 0;

	a[0] = n / m;
	for (i = 1; i < 8; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0; i < 8; i++)
	{
		if (a[i] || count)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + diff + a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_x - takes an unsigned int and prints it in lowercase hex notation
 * @x: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}

/**
 * print_X - takes an unsigned int and prints it in uppercase hex notation
 * @X: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}

/**
 * _pow - calculates an exponent
 * @base: base of exponent
 * @exponent: exponent of number
 *
 * Return: base ^ exponent
 */
static unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned long ans = base;

	for (; exponent > 1; exponent--)
		ans *= base;

	return (ans);
}

/**
 * print_p - prints an address
 * @p: address to print
 *
 * Return: number of characters to print
 */
int print_p(va_list p)
{
	unsigned long n = va_arg(p, unsigned long);
	int count = 0;
	unsigned int a[16];
	unsigned int i, sum;
	char *str = "(nil)";

	if (n == 0)
	{
		while (*str)
		{
			_putchar(*str++);
			count++;
		}
		return (count);
	}

	_putchar('0');
	_putchar('x');
	count = 2;

	for (i = 0; i < 16; i++)
	{
		a[i] = (n / _pow(16, 15 - i)) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
