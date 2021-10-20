/*
    16. Write a program to send and receive data from parent to child vice versa. Use two way communication.
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd1[2], fd2[2];

    pipe(fd1);
    pipe(fd2);

    if(!fork()) {
        close(fd1[0]);
        char buff[30];

        write(fd1[1], "Hello, from child process !! \n", 30);
        close(fd2[1]);

        read(fd2[0], &buff, 30);
        printf("rcvd from parent: %s", buff);
    }
    else {
        close(fd1[1]);
        char buff[30];

        read(fd1[0], &buff, 30);
        printf("rcvd from child : %s", buff);

        close(fd2[0]);
        write(fd2[1], "Hello, from parent process !!\n", 30);
    }
}