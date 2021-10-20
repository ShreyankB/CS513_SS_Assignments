/*
    26. Write a program to execute an executable program.
        a. use some executable program
        b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/
// 26.sh -- contains script to run 26a.c program
// 26.c  -- using execve calls 26.sh script

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *nargv[] = { NULL};
    char *envp[] = {NULL};

    if(argc != 2) {
        printf("program to execute is not passed as cmd line args");
        return 0;
    }

    if(execve(argv[1], nargv, envp) == -1)
        printf("error: %s\n",strerror(errno));   
}