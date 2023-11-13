/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:58:52 by hkai              #+#    #+#             */
/*   Updated: 2023/11/13 15:01:34 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_decimal(va_list *ap)
{
	int				num;
	unsigned int	count;
	unsigned int	unum;

	unum = 0;
	num = va_arg(*ap, int); // int型の数値を引数リストから取得
	count = 0;
	// 負の数値の場合の処理
	if (num < 0)
	{
		count += write(1, "-", 1);
		if (num == INT_MIN)
		{
			//一度INT_MAXにする
			unum = (unsigned)((-1) * (num + 1));
			unum += 1;//絶対値をINT_MINと揃える
		}
		else
		unum = (unsigned)(-num);
	}
	else
		unum = (unsigned)num;
	count += print_positive_num(unum);
	return ((int)count);
}
