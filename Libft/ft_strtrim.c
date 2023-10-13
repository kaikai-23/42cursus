/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:20:57 by hkai              #+#    #+#             */
/*   Updated: 2023/10/13 15:17:52 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issetchecker(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	start = 0;
	while (s1[start] && (ft_issetchecker(s1[start], set) == 1))
		start++;
	end = ft_strlen(s1) - 1;
	while ((start < end) && ft_issetchecker(s1[end], set) == 1)
		end--;
	str = ft_substr(s1, start, end - start + 1);
	if (!str)
		return (NULL);
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	// printf("%s\n", ft_strtrim(NULL, "abc"));
// 	// printf("%s\n", ft_strtrim("abc", NULL));
// 	// printf("%s\n", ft_strtrim("cab", "ab"));
// }
