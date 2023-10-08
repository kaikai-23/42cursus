/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:21:31 by hkai              #+#    #+#             */
/*   Updated: 2023/09/25 19:27:18 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// //ft_isalnum according to manual(ascii base function)
int	ft_isalnum(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		return (1);
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

// //ft_isalnum visually easy to understand(char base function)
// //however this function can't deal with the value outside ascii range(ex 128)
// int	ft_isalnum(char c)
// {
// 	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
// 		return (1);
// 	if ('0' <= c && c <= '9')
// 		return (1);
// 	return (0);
// }

// #include <ctype.h>
// #include <stdio.h>

// int main (void)
// {
// 	char c = '0';
// 	if (isalnum(c)){
// 		printf("%cは英数字です\n", c);
// 	}
// 	if (ft_isalnum(c)){
// 		printf("%cは英数字です\n", c);
// 	}
// }