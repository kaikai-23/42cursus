#include "../include/ft_printf.h"

int print_unsigned(va_list ap)
{
	int count;
	unsigned unum;

	unum = va_arg(ap, unsigned); 
	count = print_positive_num(unum);
	return (count);
}
