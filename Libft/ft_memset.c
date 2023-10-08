/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:58:36 by hkai              #+#    #+#             */
/*   Updated: 2023/10/08 20:57:19 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//null character don't need to be considered
//memset is used ex )initialization
//任意のデータ型に対して、具体的な操作を行う（今回でいうと0で埋める）ためにキャストする必要がある。
//charの値の範囲が-128から127に対し、unsignedは正負の逆転がない
//実際のビットパターンを維持したい時に有効
//そもそも一文字は含まれている必要がある
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char *)b;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return ((void *)dest);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char buf[8] = "ABCDEFG";
// 	printf("%s\n", memset(buf+1, 'Z', 3));
// 	char buf2[8] = "ABCDEFG";
// 	printf("%s\n", ft_memset(buf2+1, 'Z', 3));
// 	char buf3[8] = "ABCDEFG";
// 	printf("%s\n", memset(buf3+1, '', 3));
// 	char buf4[8] = "ABCDEFG";
// 	printf("%s\n", ft_memset(buf4+1, '', 3));
// }