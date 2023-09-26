/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:34:34 by hkai              #+#    #+#             */
/*   Updated: 2023/09/26 16:07:15 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//両方ともNULLのケースではNULLを返す
//重複のケースは考慮に入れない
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return ((void *)str_dst);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(){
	// char buf[] = "ABCDEFG";
	// char buf2[] = "123456789";
	// memcpy(buf,buf2,3);
	// printf("%s\n",buf);
	// //領域がかぶるケース(memcpyは対応しない)
	// char buf5[] = "abcdefg";
	// memcpy(buf5 + 2, buf5, 3);
	// printf("%s\n",buf5);

	// //以下ヌルケースと0ケース
	// char *result_1;
	// char src_1[20] = "Hello World";
	// char dest_1[20] = {0};
	// //dstがヌル
	// result_1 = memcpy(NULL, src_1, 3);
	// printf("%s\n", result_1);
	// //src_1がヌル
	// result_1 = memcpy(dest_1, NULL, 3);
	// printf("%s\n", result_1);
	//両方ヌル
	// result_1 = memcpy(NULL, NULL, 3);
	// printf("%s\n", result_1);

	// //長さが0
	// result_1 = memcpy(dest_1, src_1, 0);
	// printf("%s\n", result_1);

	/////////////////////////////

	// char buf3[] = "ABCDEFG";
	// char buf4[] = "123456789";
	// ft_memcpy(buf3,buf4,3);
	// printf("%s\n",buf3);
	// //領域がかぶるケース(memcpyは対応しない)
	// char buf6[] = "abcdefg";
	// ft_memcpy(buf6 + 2, buf6, 3);
	// printf("%s\n",buf6);

	// //以下ヌルケースと0ケース
	// char *result_2;
	// char src_2[20] = "Hello World";
	// char dest_2[20] = {0};
	// // //dstがヌル
	// result_2 = ft_memcpy(NULL, src_2, 3);
	// printf("%s\n", result_2);
	// //srcがヌル
	// result_2 = ft_memcpy(dest_2, NULL, 3);
	// printf("%s\n", result_2);
	//両方ヌル
	// result_2 = ft_memcpy(NULL, NULL, 3);
	// printf("%s\n", result_2);

	// //長さが0
	// result_2 = ft_memcpy(dest_2, src_2, 0);
	// printf("%s\n", result_2);
// }
// //restrictはあらかじめ重複がないようにちゃんとチェックしてねという意味