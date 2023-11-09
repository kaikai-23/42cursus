#include "../include/ft_printf.h"

int print_positive_num(unsigned num)
{
	unsigned	c;
	unsigned	count;

	count = 0;
	if (num < 10)
	{
		c = '0' + num;
		count += write(1, &c, 1);
		return count;
	}
	count += print_positive_num((num / 10));
	c = '0' + (num % 10);
	count += write(1, &c, 1);
	return (count);
}
