/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:34:21 by hkai              #+#    #+#             */
/*   Updated: 2023/10/04 13:47:02 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_putendl_fd(char *s, int fd)
// {
// 	if (s != NULL)
// 		write(fd, s, ft_strlen(s));
// 	write(fd, "\n", 1);
// }

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// int main()
// {
// 	char str[] = "abcdefg";
// 	ft_putendl_fd(str, 1);
// }