/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:12:33 by hkai              #+#    #+#             */
/*   Updated: 2023/09/26 17:27:52 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		c -= 32;
	return (c);
}

#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%c\n", toupper('a'));
	printf("%c\n", ft_toupper('a'));
}
