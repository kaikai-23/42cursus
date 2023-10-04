#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main()
{
	write(2, "a", 1);
	ft_putchar_fd('a',  2);
}
