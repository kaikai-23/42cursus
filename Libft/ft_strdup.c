/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:11:25 by hkai              #+#    #+#             */
/*   Updated: 2023/10/01 19:36:00 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		size;
	char		*arr;
	size_t		i;

	size = 0;
	size = ft_strlen(s1);
	arr = malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

// #include <stdio.h>
// int main(){
// 	printf("%s\n", ft_strdup("abcdefg"));
// }