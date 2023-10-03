/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:02:48 by hkai              #+#    #+#             */
/*   Updated: 2023/10/03 19:09:33 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//debug
#include <stdio.h>

#include "libft.h"

static int	digit_count(int n)
{
	int	count;

	if (n == INT_MIN)
		return (11);
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
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = digit_count(n);
	//debug
	printf("%d\n", len);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= (-1);
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (str);
}

#include <stdio.h>
int main()
{
	printf("result : %s\n", ft_itoa(-2147483648));
// 	printf("result : %s\n", ft_itoa(2147483647));
// 	printf("result : %s\n", ft_itoa(-2147483647));
// 	printf("result : %s\n", ft_itoa(0));
// 	// printf("result : %s\n", ft_itoa(a));
// 	// printf("result : %s\n", ft_itoa(2147483648));
}
