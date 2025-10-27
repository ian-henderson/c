#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s from-file to-file", *argv);
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

    int n;
    char buffer[BUFSIZ];
    while ((n = fread(buffer, sizeof(char), BUFSIZ, from)) > 0)
        fwrite(buffer, sizeof(char), n, to);

    fclose(from);
    fclose(to);
    exit(0);
}
