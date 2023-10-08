/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:20:57 by hkai              #+#    #+#             */
/*   Updated: 2023/09/26 16:14:16 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//最後のヌル終端をdestsizeが0の時はスキップしたい
//そのため早めの処理を入れる
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (src[count] != '\0')
		count++;
	if (destsize == 0)
		return (count);
	i = 0;
	while (src[i] != '\0' && i < destsize - 1)
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
// 	char dest1[15] = {0}; // Initialize to 0
// 	char dest2[5] = {0};  // Initialize to 0
// 	char dest3[1] = {0};  // Initialize to 0

// 	printf("Original: %s\n", src);

// 	ft_strlcpy(dest1, src, sizeof(dest1));
// 	printf("Copy (full size): %s\n", dest1);

// 	ft_strlcpy(dest2, src, sizeof(dest2));
// 	printf("Copy (limited size): %s\n", dest2); // 出力は "Hell" になるべきです。

// 	// dest3のサイズが0なので、何もコピーされず、戻り値はsrcの長さとなる
// 	size_t result = ft_strlcpy(dest3, src, sizeof(dest3));
// 	printf("Return  0: %lu (should be length of src)\n", result);
// 	return 0;
// }