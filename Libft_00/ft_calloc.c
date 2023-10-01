/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:46:14 by hkai              #+#    #+#             */
/*   Updated: 2023/10/01 19:01:55 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	n;

	n = count * size;
	arr = malloc(n);
	if (!arr)
		return (arr);
	ft_bzero(arr, n);
	return (arr);
}

	// /* 15,16 overflow */ check_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);