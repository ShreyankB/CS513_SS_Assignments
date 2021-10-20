/*
    13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program 
        will send the signal (using kill system call). Find out whether the first program is able to catch 
        the signal or not.
*/
//Sends signal to 13a
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    int pid;

    printf("Enter process id to send SIGSTOP:\t");
    scanf("%d", &pid);

    if(kill(pid, SIGSTOP) == -1)
        printf("%s", strerror(errno));
}