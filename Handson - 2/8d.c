/*
    8. Write a separate program using signal system call to catch the following signals
        d. SIGALRM (use alarm system call)
*/
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sig_handler();

int main() {

    alarm(10);
    signal(SIGALRM, sig_handler);
    while(1);
}

void sig_handler() {
    printf("Alarm triggered after 10 sec.\n");
    exit(0);
}