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
	unsigned int a[4];
	unsigned int i, m, sum;
	char diff;
	int count;

	m = 0x10000000; /* 16 ^ 7 */
	diff = c ? 'A' - ':' : 'a' - ':';
	for (i = 0; i < 4; i++)
	{
		a[i] = (n / m) % 16;
		m /= 16;
	}
	for (i = 0, sum = 0, count = 0; i < 4; i++)
	{
		sum += a[i];
		if (sum || i == 3)
		{
			_putchar(a[i] < 10 ? '0' + a[i] : '0' + diff + a[i]);
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
 * print_X - takes am unsigned int and prints it in uppercase hex notation
 * @X: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}

/**
 * print_p - prints an address
 * @p: address to print
 *
 * Return: number of characters to print
 */
/**
 * _pow - calculates an exponent
 * @base: base of exponent
 * @exponent: exponent of number
 *
 * Return: base ^ exponent
 */
static unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long ans = base;

	for (i = 1; i < exponent; i++)
	{
		ans *= base;
	}
	return (ans);
}

int print_p(va_list p)
{
	int count = 0;
	unsigned int i, sum;
	unsigned long n;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		while (str[count])
		{
			_putchar(str[count]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	for (i = 0, sum = 0; i < 8; i++)
	{
		sum += (n >> ((7 - i) * 8)) & 0xff;
		if (sum || i == 7)
		{
			print_hex((n >> ((7 - i) * 8)) & 0xff, 0);
			count += 2;
		}
	}
	return (count);
}
