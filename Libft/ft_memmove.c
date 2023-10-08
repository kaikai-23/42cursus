/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:59:47 by hkai              #+#    #+#             */
/*   Updated: 2023/10/04 13:26:55 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//両方ともNULLのケースではNULLを返す
//重複のケースは考慮に入れる
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str_dest;
	unsigned char	*str_src;

	if (!dst && !src)
		return (NULL);
	str_dest = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	if (str_dest <= str_src)
	{
		i = 0;
		while (0 < len--)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	}
	else
	{
		while (0 < len--)
			str_dest[len] = str_src[len];
	}
	return ((void *)str_dest);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(){
//     char buf[] = "ABCDEFG";
//     char buf2[] = "123456789";
// 	memmove(buf,buf2,3);
// 	printf("%s\n",buf);
// 	//領域がかぶるケース
// 	char buf5[] = "abcdefg";
// 	memmove(buf5 + 2, buf5, 3);
// 	printf("%s\n",buf5);

//     char buf3[] = "ABCDEFG";
//     char buf4[] = "123456789";
// 	ft_memmove(buf3,buf4,3);
// 	printf("%s\n",buf3);
// 	//領域がかぶるケース
// 	char buf6[] = "abcdefg";
// 	ft_memmove(buf6 + 2, buf6, 3);
// 	printf("%s\n",buf6);
// }
// // //なぜlenスタートなのか、iじゃダメなのか（ちゃんと説明できるように)