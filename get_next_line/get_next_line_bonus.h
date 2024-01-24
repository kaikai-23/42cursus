#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

// BUFFER_SIZEが定義されていなければ5で定義
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

// size_t
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char *get_next_line(int fd);
char	*read_line(int fd, char *store);
char *get_oneline(char *store, int *count_p);
char *find_next_line(char *store, int *count_p);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

#endif
