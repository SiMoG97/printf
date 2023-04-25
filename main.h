#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_d(int num);
int print_s(char *str);
int print_handler(const char *format, va_list args);

#endif
