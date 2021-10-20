/*
    10. Write a separate program using sigaction system call to catch the following signals.
        b. SIGINT
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler() {
    printf("Caught SIGINT : Invalid memory refrence\n");
    exit(1);
}

int main() {
    struct sigaction my_action;
    signal(SIGINT, sig_handler);

    /*
       SIGINT - Interrupt from keyboard
       ctrl + c generates SIGINT interrupt.
       else can be generated using raise system call aswell
    */

    my_action.sa_handler = sig_handler;
    my_action.sa_flags = SA_RESTART;
    sigaction (SIGINT, &my_action, NULL);

    printf ("Catching SIGINT\n");
    sleep(5);
    printf("didn't receive SIGINT signal within 5 second");
}