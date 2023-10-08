/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:41:54 by hkai              #+#    #+#             */
/*   Updated: 2023/09/26 16:01:18 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//fill with with zero for n
//任意のデータ型に対して、具体的な操作を行う（今回でいうと0で埋める）ためにキャストする必要がある。
//charの値の範囲が-128から127に対し、unsignedは正負の逆転がない
//実際のビットパターンを維持したい時に有効
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char buf[8] = "ABCDEFG";
// 	bzero(buf + 3, 2);
// 	printf("%s\n", buf);
// 	char buf2[8] = "ABCDEFG";
// 	ft_bzero(buf2 + 3, 2);
// 	printf("%s\n", buf2);
// }