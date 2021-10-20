/*
    8. Write a separate program using signal system call to catch the following signals.
        b. SIGINT
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler() {
    printf("Caught SIGFPE: Floating point exception\n");
    exit(0);
}

int main() {
    signal(SIGFPE, sig_handler);

    /*
        SIGFPE : Floating-point exception       
        generate using divide by zero.
        else can be generated using raise system call aswell
    */

    int x = 0;
    int y = 5 / x;
} 
 
