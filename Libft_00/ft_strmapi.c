#include "libft.h"

// char odd_upper(unsigned int index, char c) {
//     if (index % 2 != 0)
// 		return (ft_toupper(c));
//     return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// int main()
// {
//     char *s = "abcdefg";
//     char *result = ft_strmapi(s, odd_upper);
//     printf("%s\n", result);
//     free(result);

// 	//sがNULL
// 	printf("%s\n", ft_strmapi(NULL, odd_upper));
// 	//fがNULL
// 	printf("%s\n", ft_strmapi("abcdefg", NULL));
// 	//両方NULL
// 		//fがNULL
// 	printf("%s\n", ft_strmapi(NULL, NULL));
//     return 0;
// }
