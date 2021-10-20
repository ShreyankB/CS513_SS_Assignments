/*
    8. Write a separate program using signal system call to catch the following signals.
        b. SIGINT
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler() {
    printf("Caught SIGINT: Interrupt from keyboard");
    exit(0);
}

int main() {
    signal(SIGINT, sig_handler);

    /*
       SIGINT - Interrupt from keyboard
       ctrl + c generates SIGINT interrupt.
       else can be generated using raise system call aswell
    */

    sleep(5);
    printf("didn't receive SIGINT signal within 5 second");
}