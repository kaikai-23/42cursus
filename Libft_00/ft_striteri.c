/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:36:30 by hkai              #+#    #+#             */
/*   Updated: 2023/10/04 13:36:58 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void odd_upper(unsigned int index, char *s) {
//     if ((index % 2 != 0) && (('a' <= *s) && (*s <= 'z')))
// 	{
// 		*s -= 'a' - 'A';
// 	}
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
//     char s[] = "abcdefg";
//     ft_striteri(s, odd_upper);
//     printf("%s\n", s);

// 	// //sがNULL
// 	// printf("%s\n", ft_striteri(NULL, odd_upper));
// 	// //fがNULL
// 	// printf("%s\n", ft_striteri("abcdefg", NULL));
// 	// //両方NULL
// 	// 	//fがNULL
// 	// printf("%s\n", ft_striteri(NULL, NULL));
//     return 0;
// }