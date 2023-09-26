/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:15:39 by hkai              #+#    #+#             */
/*   Updated: 2023/09/25 19:32:48 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

// //issue1:overflow occurs if int max is exceeded
// //issue2:negative values aren't used if int is used
// //issue3:arguments must not be rewritten
// int	ft_strlen(char *str)
// {
// 	int	length;

// 	length = 0;
// 	while (str[length] != '\0')
// 		length++;
// 	return (length);
// }

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// 	char str[10] = "abcdefg";
// 	printf("%zu\n", strlen(str));
// 	printf("%zu", ft_strlen(str));
// }