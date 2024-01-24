#include "get_next_line.h"

// function for Leak
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
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

// read_line関数(readしたものをstoreに保存)
char	*read_line(int fd, char *store)
{
	// BUFFER_SIZE分の一時保存場所
	char *buf;
	ssize_t		byte_read;
	char		*temp;

	// 最初だけstore確保
	if (!store)
		store = ft_strdup("");
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
	oneline = ft_calloc(*count_p + 2, sizeof(char));
	*count_p = 0;
	while (store[*count_p] && store[*count_p] != '\n')
	{
		oneline[*count_p] = store[*count_p];
		*count_p = *count_p + 1;
	}

	// 出力するためのoneline。\nと\0の2つ分を考慮してコピー
	if (store[*count_p] && store[*count_p] == '\n')
		oneline[*count_p] = '\n';

	return (oneline);
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
