#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%p\n", argv);
	printf("%p\n", &argv[0]);
	printf("%p\n", argv[0]);
	printf("%p\n", &argv[0][0]);
}