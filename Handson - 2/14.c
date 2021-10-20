/*
    14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main() {
    int fd[2];
    if(pipe(fd) == -1) {
        printf("%s", strerror(errno));
        exit(0);
    }

    char buff[20];
    int size = write(fd[1], "Hey, there!!\n", 13);
    read(fd[0], &buff, size);
    printf("data received at read end of pipe : %s", buff);

    close(fd[0]);
    close(fd[1]);
}