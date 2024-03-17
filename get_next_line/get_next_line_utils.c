/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:36:00 by hkai              #+#    #+#             */
/*   Updated: 2024/03/17 10:58:12 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[len] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*arr;
	size_t			n;
	size_t			i;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	if (count == 0 || size == 0)
		n = 1;
	else
		n = count * size;
	arr = malloc(n);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

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
