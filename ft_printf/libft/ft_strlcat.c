/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:53:45 by hkai              #+#    #+#             */
/*   Updated: 2023/09/26 16:57:45 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//destがNULLならsizeを返し、srcがNULLならクラッシュする
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count_dest;
	size_t	count_src;
	size_t	index;

	count_dest = 0;
	count_src = 0;
	while (dest != NULL && dest[count_dest] != '\0')
		count_dest++;
	while (src[count_src] != '\0')
		count_src++;
	if (size <= count_dest)
		return (size + count_src);
	index = count_dest;
	while ((index < size - 1) && *src != '\0')
	{
		dest[index] = *src;
		index++;
		src++;
	}
	dest[index] = '\0';
	return (count_dest + count_src);
}

//説明までちゃんとできるようにしておく
// #include <stdio.h>
// int main(){
// 	char dest_1[10] = {0};
// 	char src_1[10] = "aaa";
// 	//destがヌルのケース→size+count_destを返す
// 	// printf("%lu\n", strlcat(NULL, src_1, 0));
// 	// //srcがヌルのケース→セグフォ起こす
// 	// printf("%lu\n", strlcat(dest_1, NULL, 0));
// 	///
// 	char dest_2[10] = {0};
// 	char src_2[10] = "aaa";
// 	//destがヌルのケース→size+count_destを返す
// 	// printf("%u\n", ft_strlcat(NULL, src_2, 0));
// 	// //srcがヌルのケース→セグフォ起こす
// 	// printf("%lu\n", strlcat(dest_2, NULL, 0));
// }