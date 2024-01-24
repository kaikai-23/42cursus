#include "get_next_line.h"

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

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	n;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	if (count == 0 || size == 0)
		n = 1;
	else
		n = count * size;
	arr = malloc(n);
	if (!arr)
		return (arr);
	ft_bzero(arr, n);
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
