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

	if (!s1 && !s2)
		return (ft_strdup("\0"));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
	return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	//ft_strlcpyはヌル文字まで入れてくれるやつ
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (str);
}

// read_line関数(readしたものをstoreに保存)
char	*read_line(int fd, char *store)
{
	// BUFFER_SIZE分の一時保存場所
	char buf[BUFFER_SIZE+1];
	ssize_t		byte_read;
	char		*temp;

	while ((byte_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		// 最後の文字をヌル埋め
		buf[byte_read] = '\0';

		temp = ft_strjoin(store, buf);
		free(store);
		store = temp;
		// 改行が見つかった場合の処理
		if (ft_strchr(store, '\n')) break;
	}
	// readが失敗した時のエラー処理
	if (byte_read < 0)
	{
		free(store);
		return (NULL);
	}
	return (store);
}



// まずはすべてを読み込んで返す関数を作ってみる
char    *get_next_line_test(int fd)
{
	// 無効な識別子
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        write(1, "無効なファイルディスクリプタorバッファサイズ", 42);
        return (NULL);
    }

	// 改行が見つかるまで読み込んだ行を保持し続ける変数
	static char *store;
	ssize_t		byte_read;

	// 最初だけstore確保
	if (!store)
	{
		if (!(store = strdup("")))
		{
			free(store);
			return (NULL);
		}
	}

// ここから下をread_line関数に入れる

	// // 一時保存場所の確保
	// char buf[BUFFER_SIZE+1];


	// while ((byte_read = read(fd, buf, BUFFER_SIZE)) > 0)
	// {
	// 	// 最後の文字をヌル埋め
	// 	buf[byte_read] = '\0';

	// 	char *temp = ft_strjoin(store, buf);
	// 	if(!temp)
	// 	{
	// 		free(temp);
	// 		return (NULL);
	// 	}
	// 	free(store);
	// 	store = temp;

	// 	if (strchr(store, '\n'))
	// 	{
	// 		break;
	// 	}
	// }
	// // readが失敗した時のエラー処理
	// if (byte_read < 0)
	// {
	// 	free(store);
	// 	return (NULL);
	// }
	if ((store = read_line(fd, store)) == NULL)
		return NULL;

    // 処理後storeが空の場合はNULLを返す
    if (!store || *store == '\0') {
        free(store);
        store = NULL;
        return NULL;
    }

	
	// 出力の１行を見つける
	int count = 0;
	while (store[count] && store[count] != '\n') count++;
	
	// 出力するためのoneline。\nと\0の2つ分を考慮してコピー
	char *oneline;
	if (store[count] && store[count] == '\n')
	{
		oneline = strndup(store, (count + 2));
		// 改行の次に'\0'
		oneline[count+1] = '\0';
	}
	else
	{
		// 改行見つからないケース
		oneline = strndup(store, (count + 1));
		oneline[count] = '\0';
	}

	// 以降行更新の処理

	// ファイルの最後だったら
	if (store[count] == '\0')
	{
		free(store);
		return NULL;
	}

	int newline_len = ft_strlen(store) - count;
	char *temp = malloc(sizeof(char) * (newline_len + 1));
	count++;


	int j = 0;
	while(store[count])
	{
		temp[j] = store[count];
		j++;
		count++;
	}
	free(store);
	store = temp;

    return (oneline);
}
