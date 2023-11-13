/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:57:43 by hkai              #+#    #+#             */
/*   Updated: 2023/11/13 15:03:58 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int print_unsigned(va_list *ap)
{
	int count;
	unsigned unum;

	unum = va_arg(*ap, unsigned); 
	count = print_positive_num(unum);
	return (count);
}
