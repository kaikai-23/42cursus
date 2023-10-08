/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:38:47 by hkai              #+#    #+#             */
/*   Updated: 2023/10/08 17:30:10 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//ft_isalpha according to manual(ascii base function)
int	ft_isalpha(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		return (1);
	return (0);
}

// //ft_isalpha visually easy to understand(char base function)
// //however this function can't deal with the value outside ascii range(ex 128)
// int	ft_isalpha(char c)
// {
// 	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
// 		return (1);
// 	return (0);
// }

#include <ctype.h>
#include <stdio.h>

int main (void)
{
	int c = 'a';
	if (isalpha(c)){
		printf("%cは英字です\n", c);
	}
	if (ft_isalpha(c)){
		printf("%cは英字です\n", c);
	}
}