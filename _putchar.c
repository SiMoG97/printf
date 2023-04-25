#include "main.h"

/**
 * _putchar - prints c
 * @c: the character to print
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
