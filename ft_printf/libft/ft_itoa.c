/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:02:48 by hkai              #+#    #+#             */
/*   Updated: 2023/10/08 20:56:54 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*special_value(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

static int	digit_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= (-1);
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

//getconf INT_MAX : 2147483647
//getconf INT_MIN : -2147483648
//mallocでINT_MINに対応したい→strdup
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == INT_MIN || n == 0)
		return (special_value(n));
	// if (n == INT_MIN)
	// 	return (ft_strdup("-2147483648"));
	len = digit_count(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= (-1);
	}
	// if (n == 0)
	// 	str[0] = '0';
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	printf("result : %s\n", ft_itoa(-2));
// 	printf("result : %s\n", ft_itoa(2));
// 	printf("result : %s\n", ft_itoa(-2147483648));
// 	printf("result : %s\n", ft_itoa(2147483647));
// 	printf("result : %s\n", ft_itoa(-2147483647));
// 	printf("result : %s\n", ft_itoa(0));
// 	// printf("result : %s\n", ft_itoa(a));
// 	// printf("result : %s\n", ft_itoa(2147483648));
// }
