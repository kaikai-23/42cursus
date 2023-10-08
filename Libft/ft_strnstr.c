/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:45:27 by hkai              #+#    #+#             */
/*   Updated: 2023/10/01 18:37:53 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	match_check(const char *str, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (*str != needle[i] || i >= len)
			return (0);
		i++;
		str++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	//これによって空文字対応もできる（下で処理してしまうと*haystackに引っかかってNULLを返す）
	if (needle[0] == '\0')
		return ((char *)haystack);
	//謎仕様
	if ((haystack == NULL) && (len == 0))
		return (NULL);
	while (*haystack && 0 < len)
	{
		if (*haystack == needle[0] || needle[0] == '\0')
		{
			if (match_check(haystack, needle, len) == 1)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n",strnstr("apple", NULL, 5));
// 	printf("%s\n",ft_strnstr("apple", NULL, 5));
// }