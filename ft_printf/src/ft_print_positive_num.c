/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_positive_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:42:15 by hkai              #+#    #+#             */
/*   Updated: 2023/11/09 17:42:49 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_positive_num(unsigned int num)
{
	unsigned int	c;
	unsigned int	count;

	count = 0;
	if (num < 10)
	{
		c = '0' + num;
		count += write(1, &c, 1);
		return (count);
	}
	count += print_positive_num((num / 10));
	c = '0' + (num % 10);
	count += write(1, &c, 1);
	return (count);
}
