#include "get_next_line.h"
#include "get_next_line_bonus.h"

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    int fd = open(argv[1], O_RDONLY);
    (void)argc;

    char *oneline;
    while (1)
    {
        oneline = get_next_line(fd);
        printf("result:%s\n", oneline);
        free(oneline);
        if (!oneline)
            break ;
    }

    close(fd);
    return 0;
}
