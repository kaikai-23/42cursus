// ssize_t用
#include <unistd.h>

// printf用
#include <stdio.h>

// BUFFER_SIZEが定義されていなければ5で定義
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif


// まずはすべてを読み込んで返す関数を作ってみる
void    get_next_line(int fd)
{
    // BUFFER_SIZEの分だけ定義
    char buf[BUFFER_SIZE];
	// バイト数を扱う変数
	ssize_t byte_read;
	// 1行分確保する関数mallocで格納
	char *line;

	// エラーハンドリング(無効な識別子、無効なバッファサイズ、read関数エラー)
    if (fd < 0 || BUFFER_SIZE <= 0 ||
		(byte_read = read(fd, buf, BUFFER_SIZE)) < 0)
    {
        write(1, "無効なファイルディスクリプタ", 42);
        return;
    }

	// リード後\nを特定するまで数える
	int count = 0;
	while (0 < byte_read)
	{
		int i = 0;
		// BUFFER_SIZE分だけ継続格納
		while(i < byte_read && buf[i] != '\0')
		{
			if (buf[i] == '\n' || buf[i] == EOF){
				printf("改行発見\n");
				break;
			}
			// 一文字ずつbufを取得
			printf("%c\n", buf[i]);
			i++;
		}
		
		if (i == byte_read)
		{
			count += i;
			// まだ読み込めるのでもう一周
			printf("再びreadする\n");
			byte_read = read(fd, buf, BUFFER_SIZE);
		}
		else
		{
			// 改行が見つかったかファイルの終端のケース
			count += i;
			printf("break\n");
			break;
		}
	}

	printf("一行目の文字数は%d\n", count);

	// line = malloc((count+1) * sizeof(char));
	// int i = 0;
	// while (i < count)
	// {
	// 	// 1文字ずつ格納
	// 	line[i] = 
	// }
}

// エラーハンドリング

	// // 無効な識別子
    // if (fd < 0)
    // {
    //     write(1, "無効なファイルディスクリプタ", 42);
    //     return;
    // }
	// // 無効なバッファサイズ
    // if (BUFFER_SIZE <= 0)
    // {
    //     write(1, "無効なファイルディスクリプタ", 42);
	// 	// 実際はヌルを返す
    //     return;
    // }

	// // エラーハンドリング
	// if ((byte_read = read(fd, buf, BUFFER_SIZE)) < 0)
	// {
	// 	// read関数に不具合
	// 	write(1, "read関数読み込み失敗", 42);
	// 	return ;
	// }
