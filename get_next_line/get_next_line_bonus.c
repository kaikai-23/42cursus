#include "get_next_line_bonus.h"

// function for Leak
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

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
	while(s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j] != 0)
		str[i++] = s2[j++];
	str[len] = '\0';
	return (str);
}

char	*read_line(int fd, char *store)
{
	char *buf;
	int			byte_read;
	char		*temp;

	if (!store)
		store = ft_strdup("");
	buf = calloc(BUFFER_SIZE+1, sizeof(char));
	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(store);
			return (NULL);
		}
		buf[byte_read] = '\0';
		temp = ft_strjoin(store, buf);
		free(store);
		store = temp;
		if (ft_strchr(store, '\n')) break;
	}
	free(buf);
	return (store);
}

char *get_oneline(char *store, int *count_p)
{
	char *oneline;
	
    if (!store || store[0] == '\0')
	{
        store = NULL;
        return NULL;
	}
	while (store[*count_p] && store[*count_p] != '\n')
		*count_p = *count_p + 1;
	oneline = ft_calloc(*count_p + 2, sizeof(char));
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

char *find_next_line(char *store, int *count_p)
{
	if (store[*count_p] == '\0')
	{
		free(store);
		return NULL;
	}
	int temp_len = ft_strlen(store) - *count_p;
	char *temp = calloc((temp_len + 1), sizeof(char));
	*count_p = *count_p + 1;
	int i = 0;
	while (store[*count_p])
	{
		temp[i] = store[*count_p];
		i++;
		*count_p = *count_p + 1;
	}
	free(store);
	return (temp);
}

char    *get_next_line(int fd)
{
	static char *store[OPEN_MAX];
	char		*oneline;
	int		count;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	if (!(store[fd] = read_line(fd, store[fd])))
	{
		free(store[fd]);
		return NULL;
	}
	count = 0;
	oneline = get_oneline(store[fd], &count);
	store[fd] = find_next_line(store[fd], &count);
    return (oneline);
}

