#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s from-file to-file\n", *argv);
        exit(1);
    }

    FILE *from, *to;

    if ((from = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        exit(1);
    }

    if ((to = fopen(argv[2], "a")) == NULL)
    {
        perror(argv[2]);
        exit(1);
    }

    int c;
    while ((c = getc(from)) != EOF)
        putc(c, to);

    fclose(from);
    fclose(to);
    exit(0);
}
