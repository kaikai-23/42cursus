/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:26:28 by hkai              #+#    #+#             */
/*   Updated: 2023/10/04 14:45:34 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;

	if ((s1 == NULL) && (n == 0))
		return (0);
	while ((*s1 || *s2) && (0 < n))
	{
		str1 = (unsigned char)*s1;
		str2 = (unsigned char)*s2;
		if (str1 != str2)
			return (str1 - str2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
    // printf("%d\n", strncmp("acd", "ac", 5));
    // printf("%d\n", ft_strncmp("acd", "ac", 5));
    // printf("%d\n", strncmp("ac\0a", "ac", 5));
    // printf("%d\n", ft_strncmp("ac\0a", "ac", 5));
    // printf("%d\n", strncmp("ac\0a", NULL, 5));
    // printf("%d\n", ft_strncmp("ac\0a", NULL, 5));
    // printf("%d\n", strncmp(NULL, "abcd", 0));
    // printf("%d\n", ft_strncmp(NULL, "abcd", 0));
    // printf("%d\n", strncmp(NULL, NULL, 0));
    // printf("%d\n", ft_strncmp(NULL, NULL, 0));
// }