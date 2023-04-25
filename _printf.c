#include "main.h"

/**
 * _printf - Printf function
 * @format: format
 * @...: arguments list
 *
 * Return: the number of characters printed, or -1 if an error occurred
 */

int _printf(const char *format, ...)
{
	va_list(args);
	int len = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(args, format);
	len = print_handler(format, args);
	va_end(args);
	return (len);
}

/**
 * print_handler - Entry point
 * @format: format
 * @args: args
 * Return: length
 */

int print_handler(const char *format, va_list args)
{
	int i, len = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					len += _putchar(va_arg(args, int));
					break;
				case 's':
					len += print_s(va_arg(args, char *));
					break;
				case '%':
					len += _putchar('%');
					break;
				case 'd':
					len += print_d(va_arg(args, int));
					break;
				default:
					len += _putchar('%');
					len += _putchar(format[i]);
					break;
			}
		}
		else
		{
			len += _putchar(format[i]);
		}
	}
	return (len);
}

