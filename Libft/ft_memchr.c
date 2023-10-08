/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:10:11 by hkai              #+#    #+#             */
/*   Updated: 2023/10/01 12:41:20 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (0 < n--)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", memchr("012345",'2' + 256, 3));
// 	printf("%s\n", ft_memchr("012345",'2' + 256, 3));
// }
// //'\0'がきても検索続けるのでwhile (*str && (0 < n--))ではダメ
