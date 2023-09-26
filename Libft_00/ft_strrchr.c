/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:58:06 by hkai              #+#    #+#             */
/*   Updated: 2023/09/26 19:22:06 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *str);

char	*ft_strrchr(const char *s, int c)
{
	char	after_convert;
	size_t	s_length;

	s_length = ft_strlen(s);
	after_convert = (char)c;
	while (0 < s_length && s[s_length] != after_convert)
		s_length--;
	if (s[s_length] == after_convert)
		return ((char *)s + s_length);
	else
		return ((char *)0);
}

// #include <stdio.h>
// int main(){
// 	printf("%s\n", strrchr("ABCBA", 'Z' + 256));
// 	printf("%s\n", ft_strrchr("ABCBA", 'Z' + 256));
// 	printf("%s\n", strrchr("ABCBA", '\0'));
// 	printf("%s\n", ft_strrchr("ABCBA", '\0'));
// }