/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:33:22 by hkai              #+#    #+#             */
/*   Updated: 2023/10/08 20:57:48 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//c should be coverted to char = you have to cast c to char
char	*ft_strchr(const char *s, int c)
{
	char	after_convert;

	after_convert = (char)c;
	while (*s && *s != after_convert)
		s++;
	if (*s == after_convert)
		return ((char *)s);
	else
		return (NULL);
}

// #include <stdio.h>
// int main(){
// 	printf("%s\n", NULL);
// 	printf("%s\n", strchr("AAA", 'A' + 256));
// 	printf("%s\n", ft_strchr("AAA", 'A' + 256));
// }