/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaramonkai <takaramonkai@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:19:51 by hkai              #+#    #+#             */
/*   Updated: 2023/11/08 11:06:18 by takaramonka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "include/libft.h"

void	print_pointer(va_list ap)
{
	void				*ptr;
	unsigned long long	address;
	char				buffer[20];
	int					i;

	i = 0;
	ptr = va_arg(ap, void *);
	if (ptr == NULL)
		buffer[i++] = '0';
	else
	{
		address = (unsigned long long)ptr;
		while (address)
		{
			unsigned char hex_digit = address % 16;
			if (hex_digit < 10)
				buffer[i++] = '0' + hex_digit;
			else
				buffer[i++] = 'a' + (hex_digit - 10);
			address /= 16;
		}
	}
	write(1, "0x", 2); // 16進数を表す接頭辞
	while (i > 0) // バッファの内容を逆順に出力
	{
		write(1, &buffer[--i], 1);
	}
}
