#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   ch;
    unsigned char   *str;

    str = (unsigned char *)s;
    ch = (unsigned char)c;
    while(*str && (0 < n--))
    {
        if (*str == ch)
            return (void *)str;
        str++;
    }
    return (NULL);
}

#include <stdio.h>
int main()
{
    printf("%s\n")
}
