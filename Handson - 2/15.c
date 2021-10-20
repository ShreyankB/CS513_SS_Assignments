/*
    15. Write a simple program to send some data from parent to the childprocess.
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd[2];
    if(pipe(fd) == -1){
        printf("%s", strerror(errno));
        exit(0);
    }

    if(fork()) {
        close(fd[0]);
        write(fd[1], "Hey, There", 10);
        sleep(2);   // without sleep fd[1] is being closed before child reads it.
        close(fd[1]);
    }
    else {
        close(fd[1]);
        char buff[11];
        read(fd[0], &buff, 10);
        printf("received from parent process : %s", buff);
        close(fd[0]);
    }

}