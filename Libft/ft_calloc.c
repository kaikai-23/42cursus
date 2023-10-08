/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:46:14 by hkai              #+#    #+#             */
/*   Updated: 2023/10/07 14:47:45 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	n;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	n = count * size;
	arr = malloc(n);
	if (!arr)
		return (arr);
	ft_bzero(arr, n);
	return (arr);
}

// #include <stdio.h>

// int main(void)
// {
//     void *ptr;

//     // テストケース9の模倣
//     ptr = ft_calloc(-5, -5);
//     if (ptr == NULL)
//     {
//         printf("NULLを返す\n");
//     }
//     else
//     {
//         printf("NULLを返さない＝間違ってる\n");
//         free(ptr); // 必要な場合、メモリを解放
//     }
//     return 0;
// }