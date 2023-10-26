/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:14:41 by hkai              #+#    #+#             */
/*   Updated: 2023/10/12 15:55:13 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strtolについてmanで確認せよ

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		flag;
	long	num;

	num = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	flag = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if ((flag == 1) && (num > (LONG_MAX / 10)
				|| (num == (LONG_MAX / 10) && (*str - '0') > 7)))
			return ((int)LONG_MAX);
		else if ((flag == -1) && (num > (LONG_MAX / 10)
				|| (num == (LONG_MAX / 10) && (*str - '0') > 8)))
			return ((int)LONG_MIN);
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)num * flag);
}

// #include <stdio.h>
// int main(){

// 	printf("%d\n", atoi("9223372036854775808"));
// 	printf("%d\n", atoi("-9223372036854775809"));
// 	printf("%d\n", ft_atoi("9223372036854775808"));
// 	printf("%d\n", ft_atoi("-9223372036854775809"));
// }