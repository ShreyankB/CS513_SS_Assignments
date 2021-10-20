/*
    10. Write a separate program using sigaction system call to catch the following signals.
        a. SIGSEGV
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler() {
    printf("Caught SIGSEGV: Invalid memory refrence");
    exit(1);
}

int main() {
    struct sigaction my_action;
    my_action.sa_handler = sig_handler;
    my_action.sa_flags = SA_RESTART;
    sigaction (SIGSEGV, &my_action, NULL);

    signal(SIGSEGV, sig_handler);

    /*
       SIGSEGV - Invalid memory reference 
       below code is to generate invalid memory reference
    */

    int *z;
    *z = 0;
}