/*
    17. Write a program to execute ls -l | wc.
        a. use dup
*/

#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd[2];
    pipe(fd);

    if(!fork()) {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    }
    else {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        execlp("wc", "wc", NULL);
    }
}