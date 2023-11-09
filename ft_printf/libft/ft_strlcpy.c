/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:20:57 by hkai              #+#    #+#             */
/*   Updated: 2023/10/10 17:28:07 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//最後のヌル終端をdestsizeが0の時はスキップしたい
//そのため早めの処理を入れる
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (src[count] != '\0')
		count++;
	if (dstsize == 0)
		return (count);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dst1[15] = {0}; // Initialize to 0
// 	char dst2[5] = {0};  // Initialize to 0
// 	char dst3[1] = {0};  // Initialize to 0

// 	printf("Original: %s\n", src);

// 	ft_strlcpy(dst1, src, sizeof(dst1));
// 	printf("Copy (full size): %s\n", dst1);

// 	ft_strlcpy(dst2, src, sizeof(dst2));
// 	printf("Copy (limited size): %s\n", dst2); // 出力は "Hell" になるべきです。

// 	// dst3のサイズが0なので、何もコピーされず、戻り値はsrcの長さとなる
// 	size_t result = ft_strlcpy(dst3, src, sizeof(dst3));
// 	printf("Return  0: %lu (should be length of src)\n", result);
// 	return 0;
// }