/*
    17. Write a program to execute ls -l | wc.
        b. use dup2
*/

#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd[2];
    pipe(fd);

    if(!fork()) {
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("ls", "ls", "-l", NULL);
    }
    else {
        close(fd[1]);
        dup2(fd[0], 0);
        execlp("wc", "wc", NULL);
    }
}