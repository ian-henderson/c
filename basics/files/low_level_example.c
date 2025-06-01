#include <errno.h>  // errno
#include <fcntl.h>  // O_WRONLY, O_CREAT
#include <stdio.h>  // perror, printf
#include <stdlib.h> // exit
#include <unistd.h> // close, open, write

int main(void) {
    char *filename = "low_level_example.txt";
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);

    if (fd < 0) {
        printf("error number %d\n", errno);
        perror(filename);
        exit(1);
    }

    write(fd, "Hello, world!\n", 14);
    close(fd);
}
