/*
    13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program 
        will send the signal (using kill system call). Find out whether the first program is able to catch 
        the signal or not.
*/
//waiting to catch SIGSTOP Signal.


/*
    NOTE: for SIGSTOP signal its default action can't be altered nor SIGSTOP can be ignored.
*/
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler();

int main() {
    long int pid = getpid();

    signal(SIGSTOP, sig_handler);

    while(1)
        printf("%ld executing\n", pid);
}

void sig_handler() {
    // this function will never be called because SIGSTOP default action can't be altered.
    printf("caught SIGSTOP\n");
    exit(0);
}