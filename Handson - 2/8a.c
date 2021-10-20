/*
    8. Write a separate program using signal system call to catch the following signals.
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
    signal(SIGSEGV, sig_handler);

    /*
       SIGSEGV - Invalid memory reference 
       below code is to generate invalid memory reference
       else can be generated using raise system call aswell
    */

    int *z;
    *z = 0;
}