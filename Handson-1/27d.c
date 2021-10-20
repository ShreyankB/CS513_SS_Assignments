/*
    27. Write a program to execute ls -Rl bythe following system calls
        d. execv
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    char *path = "/usr/bin/ls";
    char *argv[] = {"ls", "-Rl", NULL};

    errno = 0; //setting error no 0, so incase exec family function fails it'll catch -1
    execv(path, argv);

    //this part will only get executed if there is some error
    printf("error : %s\n", strerror(errno));
    

}
