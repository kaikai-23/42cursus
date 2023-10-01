#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t 	i;
	char	*str;

	if (!s)
		return (NULL);
	//動的確保が求められてるからfreeできる形でreturnする
	if (ft_strlen(s) - 1 <= start)
		return (ft_strdup("\0"));
	str = malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while(0 < start--)
		s++;
	while (*s && i < len)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}
