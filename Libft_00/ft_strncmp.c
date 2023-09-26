#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char   str1;
    unsigned char   str2;

    while((*s1 || *s2) && (0 < n--))
    {
        str1 = (unsigned char)*s1;
        str2 = (unsigned char)*s2;
        if (str1 != str2)
        {
            if ((unsigned char)*s1 > (unsigned char)*s2)
                return (1);
            else
                return (-1);
        }
        s1++;
        s2++;
    }
        return (0);
}

// #include <stdio.h>
// int main()
// {
//     printf("%d\n", strncmp("acd", "ac", 5));
//     printf("%d\n", ft_strncmp("acd", "ac", 5));
// }
