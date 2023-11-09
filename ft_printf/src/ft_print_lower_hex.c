#include "../include/ft_printf.h"

static int hex_rec(unsigned num)
{
	unsigned	c;
	unsigned	count;

	count = 0;
	if (num < 16)
	{
		if (num < 10)
			c = '0' + num;
		else
			c = 'a' + (num - 10);
		count += write(1, &c, 1);
		return count;
	}
	count += hex_rec((num / 16));
	count += hex_rec((num % 16));
	return (count);
}

int print_lower_hex(va_list ap)
{
	unsigned num;
	int count = 0;

	num = va_arg(ap, unsigned); 
	count += hex_rec(num);
	return (count);
}
