/*
    24. Write a program to create an orphan process.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if(!fork()) {
        printf("child process pid : %d\n", getpid());
        sleep(10);
    }
    else {
        printf("parent process pid : %d\n", getpid());
        exit(0);
    }
}