/*
    27. Write a program to execute ls -Rl bythe following system calls
        a. execl
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    char *path = "/usr/bin/ls";
    errno = 0; //setting error no 0, so incase exec family function fails it'll catch -1
    execl(path, "ls", "-Rl", NULL);
    
    //this part will only get executed if there is some error
    printf("error : %s\n", strerror(errno));
}
