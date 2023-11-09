/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:39:39 by hkai              #+#    #+#             */
/*   Updated: 2023/11/09 17:42:06 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	hex_rec(unsigned int num)
{
	unsigned int	c;
	unsigned int	count;

	count = 0;
	if (num < 16)
	{
		if (num < 10)
			c = '0' + num;
		else
			c = 'a' + (num - 10);
		count += write(1, &c, 1);
		return (count);
	}
	count += hex_rec((num / 16));
	count += hex_rec((num % 16));
	return (count);
}

int	print_lower_hex(va_list ap)
{
	unsigned int	num;
	int				count;

	count = 0;
	num = va_arg(ap, unsigned int);
	count += hex_rec(num);
	return (count);
}
