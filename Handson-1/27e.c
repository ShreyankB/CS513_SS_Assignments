/*
    27. Write a program to execute ls -Rl bythe following system calls
        e. execvp
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    char *argv[] = {"ls", "-Rl", NULL};
    char *file = "ls";
    char *envp[] = {"PATH=usr/bin/" ,NULL};
    
    errno = 0; //setting error no 0, so incase exec family function fails it'll catch -1
    execvp(file, argv);

    //this part will only get executed if there is some error
     printf("error : %s\n", strerror(errno));

}
