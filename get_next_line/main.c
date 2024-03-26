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
		// oneline = get_next_line(0);
        if (!oneline)
        {
            free(oneline);
            break ;
        }
        printf("result:%s", oneline);
        free(oneline);
    }

    close(fd);
    return 0;
}