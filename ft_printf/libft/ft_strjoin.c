/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:20:42 by hkai              #+#    #+#             */
/*   Updated: 2023/10/13 15:12:20 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (ft_strdup("\0"));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
	return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	//ft_strlcpyはヌル文字まで入れてくれるやつ
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	//return (ft_strdup(s1));で終端文字が返ってくる
// 	printf("%s\n", ft_strjoin("", NULL));
// 	// return (ft_strdup(s2));で終端文字が返ってくる
// 	printf("%s\n", ft_strjoin(NULL, ""));
// 	// return (ft_strdup("\0"));で終端文字が返ってくる
// 	printf("%s\n", ft_strjoin(NULL, NULL));
// 	// 最後のreturnまでいく 1だけ確保されて終端文字が入る
// 	printf("%s\n", ft_strjoin("", ""));
// }
