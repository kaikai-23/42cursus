/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:42:35 by hkai              #+#    #+#             */
/*   Updated: 2023/10/03 16:57:21 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_machine(size_t end, char **store)
{
	size_t	free_start;

	free_start = 0;
	while (free_start < end)
	{
		free(store[free_start]);
		free_start++;
	}
	free(store);
	return (NULL);
}

static size_t	word_counter(const char *str, char c)
{
	size_t	count;

	count = 0;
	while ((str[count] != '\0') && (str[count] != c))
		count++;
	return (count);
}

static char	*input_to_store(const char *str, char c)
{
	size_t	count;
	char	*word;

	count = word_counter(str, c);
	word = malloc(sizeof(char) * (count + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, count + 1);
	return (word);
}

static	size_t	store_len_counter(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] != '\0') && (s[i] == c))
			i++;
		if (s[i] != '\0')
			count++;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**store;
	size_t	store_len;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	store_len = store_len_counter(s, c);
	store = malloc(sizeof(char *) * (store_len + 1));
	if (!store)
		return (NULL);
	while (i < store_len)
	{
		while ((*s != '\0') && (*s == c))
			s++;
		store[i] = input_to_store(s, c);
		if (!store[i])
			return (free_machine(i - 1, store));
		i++;
		while ((*s != '\0') && (*s != c))
			s++;
	}
	store[i] = NULL;
	return (store);
}

// #include <stdio.h>
// int main()
// {
// 	char **str;
// 	str = ft_split("abv,acd,ccc", ',');
// 	int i = 0;
// 	while (i < 5)
// 	{
// 		printf ("%s\n", str[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 4)
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }