#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_d(int num);
int print_s(char *str);
int print_handler(const char *format, va_list args);

int print_hex(unsigned int n, unsigned int c);
int print_x(va_list x);
int print_X(va_list X);
static unsigned long _pow(unsigned int base, unsigned int exponent);
int print_p(va_list p);

#endif
