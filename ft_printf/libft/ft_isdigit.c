/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:00:35 by hkai              #+#    #+#             */
/*   Updated: 2023/09/25 19:28:42 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//ft_isdigit according to manual(ascii base function)
int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

//ft_isdigit visually easy to understand(char base function)
// //however this function can't deal with the value outside ascii range(ex 128)
// int	ft_isdigit(char d)
// {
// 	if ('0' <= d && d <= '9')
// 		return (1);
// 	return (0);
// }

// #include <ctype.h>
// #include <stdio.h>

// int main (void)
// {
// 	char num = '9';
// 	if (isdigit(num)){
// 		printf("%cは数字です\n", num);
// 	}
// 	if (ft_isdigit(num)){
// 		printf("%cは数字です\n", num);
// 	}
// }