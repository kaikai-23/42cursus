#include <unistd.h>

// open関数専用
#include <fcntl.h>

// printf専用
#include <stdio.h>
#include <stdlib.h>

// BUFFER_SIZEが定義されていなければ5で定義
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

// まずはすべてを読み込んで返す関数を作ってみる
void    get_next_line(int fd);
char    *get_next_line_test(int fd);

int main(int argc, char *argv[])
{
    
    if (argc < 2)
    {
        write(1, "標準入力から受付", 27);
        return 0;
    }
    // 読み取り専用でopen
    // 実際はopenしたファイルディスクリプタを引数で取得する
    int fd = open(argv[1], O_RDONLY);


    char *oneline;
    oneline = get_next_line_test(fd);
    printf("結果%s\n", oneline);
    free(oneline);
    oneline = get_next_line_test(fd);
    printf("結果%s\n", oneline);
    free(oneline);
    oneline = get_next_line_test(fd);
    printf("結果%s\n", oneline);
    free(oneline);

    close(fd);
    return 0;
}
