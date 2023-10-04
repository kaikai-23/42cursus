#include "libft.h"

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// }

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

int main()
{
	write(1, "abcde", 5);
	write(1, "\n", 1);
	ft_putstr_fd("abcde", 1);
}
