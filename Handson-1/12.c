/*
    12. Write a program to find out the opening mode of a file. Use fcntl
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("./12.c", O_RDWR);

    if(fd == -1) {
        printf("error while opening the file");
        return 0;
    }

    int mode = O_ACCMODE & fcntl(fd, F_GETFL);

    switch (mode)
    {
    case O_RDONLY:
        printf("Read only mode");
        break;
    case O_WRONLY:
        printf("Write only mode");
        break;
    case O_RDWR:
        printf("Read Write mode");
        break;
    default:
        printf("error");
    }

    close(fd);
}