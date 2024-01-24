// ssize_t用
#include <unistd.h>

// printf用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BUFFER_SIZEが定義されていなければ5で定義
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

// Leakのチェック
__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (src[count] != '\0')
		count++;
	if (dstsize == 0)
		return (count);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
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


// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*res;
// 	int		i;
// 	int		j;
// 	int sizetotal = ft_strlen(s1) + ft_strlen(s2);
// 	i = 0;
// 	res = malloc(sizeof(char) * (sizetotal + 1));
// 	if (!res || !s1 || !s2)
// 		return (NULL);
// 	while (s1[i] != 0)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != 0)
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[sizetotal] = 0;
// 	return (res);
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
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[len] = '\0';

	return (str);
}

char *get_oneline(char *store, int *count_p)
{
	char *oneline;
	
    // 処理後ファイルが終わりに達した場合はNULLを返す
    if (!store || store[0] == '\0')
	{
        // ここでstoreはfreeしちゃだめ（次のところでfreeするから）
        store = NULL;
        return NULL;
    }

	// *count_p = 0;
	while (store[*count_p] && store[*count_p] != '\n')
		*count_p = *count_p + 1;
	
	// 出力するためのoneline。\nと\0の2つ分を考慮してコピー
	if (store[*count_p] && store[*count_p] == '\n')
	{
		oneline = strndup(store, (*count_p + 2));
		oneline[*count_p + 1] = '\0';
	}
	else
	{
		// 改行見つからないケース
		oneline = strndup(store, (*count_p + 1));
		oneline[*count_p] = '\0';
	}

	return (oneline);
}

// read_line関数(readしたものをstoreに保存)
char	*read_line(int fd, char *store)
{
	// BUFFER_SIZE分の一時保存場所
	char *buf;
	ssize_t		byte_read;
	char		*temp;

	// 最初だけstore確保
	if (!store)
		store = strdup("");
	// BUFFER_SIZEが大きくなるとbufに残ったりするから動的確保
	buf = calloc(BUFFER_SIZE+1, sizeof(char));

	byte_read = 1;

	while (byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		// read失敗のエラー処理,storeがNULLのケース
		if (byte_read < 0)
		{
			free(store);
			return (NULL);
		}
		// 最後の文字をヌル埋め
		buf[byte_read] = '\0';

		temp = ft_strjoin(store, buf);
		free(store);
		store = temp;
		
		// 改行が見つかった場合の処理
		if (ft_strchr(store, '\n')) break;
	}
	free(buf);
	return (store);
}

char *find_next_line(char *store, int *count_p)
{
	// ファイル終端
	if (store[*count_p] == '\0')
	{
		// freeしてからNULL返す
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

// まずはすべてを読み込んで返す関数を作ってみる
char    *get_next_line(int fd)
{
	
	// 改行が見つかるまで読み込んだ行を保持し続ける変数
	static char *store;
	char		*oneline;
	int	count = 0;

	// 無効な識別子
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        write(1, "無効なファイルディスクリプタorバッファサイズ", 42);
        return (NULL);
    }
	store = read_line(fd, store);
	if (!store)
	{
		free(store);
		return NULL;
	}
	oneline = get_oneline(store, &count);

	store = find_next_line(store, &count);

    return (oneline);
}
