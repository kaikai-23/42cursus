#include "get_next_line.h"
#include "get_next_line_bonus.h"

#include <fcntl.h>

int main(int argc, char *argv[])
{
    
    if (argc < 2)
    {
        write(1, "standard input", 27);
        return 0;
    }

    int fd = open(argv[1], O_RDONLY);

    char *oneline;
    oneline = get_next_line(fd);
    printf("result:%s\n", oneline);
    free(oneline);
    oneline = get_next_line(fd);
    printf("result%s\n", oneline);
    free(oneline);
    oneline = get_next_line(fd);
    printf("result%s\n", oneline);
    free(oneline);

    close(fd);
    return 0;
}
