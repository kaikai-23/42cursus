/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:04:41 by hkai              #+#    #+#             */
/*   Updated: 2023/10/08 18:27:10 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//isprint range is between ' ' and '~'
int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (040 <= c && c <= 0176)
		return (1);
	return (0);
}

#include <stdio.h>
#include <ctype.h>
int main(){
int c = '\t';
	printf("%d\n", isprint(c));
	printf("%d", ft_isprint(c));
}