/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:19:51 by hkai              #+#    #+#             */
/*   Updated: 2023/11/09 19:12:12 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int address_rec(unsigned long long num)
{
	int c;
	int count;

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
	count += address_rec((num / 16));
	count += address_rec((num % 16));
	return (count);
}

int	print_pointer(va_list ap)
{
	void				*ptr;
	unsigned long long	address;
	int					count;

	count = 0;
	count += write(1, "0x", 2); // 16進数を表す接頭辞
	ptr = va_arg(ap, void*);//va_argを使用してポインタを取得する際は、通常 void * 型として取得する
	address = (unsigned long long)ptr;
	if (ptr == NULL)//直接unsigned long longとNULLは比較できない
		count += write(1, "0", 1);
	else
		count += address_rec(address);
	return (count);
}
