/*
    25. Write a program to create three child processes. 
        The parent should wait for a particular child (use waitpid system call).
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    int cpid = fork();
    if(!cpid) {
        printf("child 1 pid : %d \n", getpid());
        sleep(7);
    }
    else {
        if(!fork()) {
            printf("child 2 pid : %d \n", getpid());
            exit(0);
        }
        else {
            if(!fork()) {
                printf("child 3 pid : %d \n", getpid());
                exit(0);
            }
            else {
                printf("parent waiting for child 1(pid) %d to complete ...\n", cpid);
                if(waitpid(cpid, NULL, 0) == -1){
                    printf("error: %s\n",strerror(errno));
                    return 0;
                }
                printf("%d finished. parent exits", cpid);
                exit(0);
            }
        }
    }
}
