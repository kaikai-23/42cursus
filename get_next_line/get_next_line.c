/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkai <hkai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:26:46 by hkai              #+#    #+#             */
/*   Updated: 2024/03/17 11:54:55 by hkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

char	*free_store_on_error(char **target)
{
	free(*target);
	*target = NULL;
	return (NULL);
}

char	*get_oneline(char *store, int *count_p)
{
	char	*oneline;

	if (!store || store[0] == '\0')
	{
		store = NULL;
		return (NULL);
	}
	while (store[*count_p] && store[*count_p] != '\n')
		*count_p = *count_p + 1;
	oneline = ft_calloc(*count_p + 2, sizeof(char));
	if (!oneline)
		return (free_store_on_error(&store));
	*count_p = 0;
	while (store[*count_p] && store[*count_p] != '\n')
	{
		oneline[*count_p] = store[*count_p];
		*count_p = *count_p + 1;
	}
	if (store[*count_p] && store[*count_p] == '\n')
		oneline[*count_p] = '\n';
	return (oneline);
}

char	*find_next_line(char *store, int *count_p)
{
	int		temp_len;
	char	*temp;
	int		i;

	if (store[*count_p] == '\0')
		return (free_store_on_error(&store));
	temp_len = ft_strlen(store) - *count_p;
	temp = ft_calloc((temp_len + 1), sizeof(char));
	if (!temp)
		return (free_store_on_error(&store));
	*count_p = *count_p + 1;
	i = 0;
	while (store[*count_p])
	{
		temp[i] = store[*count_p];
		i++;
		*count_p = *count_p + 1;
	}
	free(store);
	return (temp);
}

char	*read_line(int fd, char *store, char *buf)
{
	int		byte_read;
	char	*temp;

	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
			return (free_store_on_error(&store));
		buf[byte_read] = '\0';
		temp = ft_strjoin(store, buf);
		if (!temp)
		{
			free(buf);
			return (free_store_on_error(&store));
		}
		free(store);
		store = temp;
		if (ft_strchr(store, '\n'))
			break ;
	}
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*oneline;
	int			count;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!store)
		store = ft_strdup("");
	if (!store)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (free_store_on_error(&store));
	store = read_line(fd, store, buf);
	if (!store)
		return (NULL);
	free(buf);
	count = 0;
	oneline = get_oneline(store, &count);
	store = find_next_line(store, &count);
	return (oneline);
}
