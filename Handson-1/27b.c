/*
    27. Write a program to execute ls -Rl bythe following system calls
        b. execlp

*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    char *file = "ls";
    errno = 0; //setting error no 0, so incase exec family function fails it'll catch -1
    execlp(file, "ls", "-Rl", NULL);

    //this part will only get executed if there is some error
    printf("error : %s\n", strerror(errno));
}
