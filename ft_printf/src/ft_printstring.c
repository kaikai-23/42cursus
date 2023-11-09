/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaramonkai <takaramonkai@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:59:12 by hkai              #+#    #+#             */
/*   Updated: 2023/11/09 13:07:58 by takaramonka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_string(va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (*str)
	{
		i += write(1, str, 1);
		str++;
	}
	return (i);
}
