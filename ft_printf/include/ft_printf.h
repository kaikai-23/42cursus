#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>//write用
#include <stdarg.h>//va_start, va_arg, va_copy, va_end専用
#include "libft.h"//libft.h用

int	print_char(va_list ap);
int	print_string(va_list ap);
int	print_pointer(va_list ap);
int	print_decimal(va_list ap);
int print_unsigned(va_list ap);
int print_lower_hex(va_list ap);
int print_upper_hex(va_list ap);
int print_positive_num(unsigned num);
int	ft_printf(const char *format, ...);

#endif
