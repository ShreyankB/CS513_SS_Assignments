/*
    11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - 
        use sigaction system call.
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signal_num);

int main() {
    struct sigaction my_action;

    // ignore SIGINT
    my_action.sa_handler = SIG_IGN;
    my_action.sa_flags = SA_RESTART;
    sigaction (SIGINT, &my_action, NULL);
    printf ("Ignoring SIGINT\n");
    sleep(3);
    printf (" Sleep is over\n");

    // reseting default action SIGINT
    my_action.sa_handler = sigint_handler;
    my_action.sa_flags = SA_RESTART;
    sigaction (SIGINT, &my_action, NULL);
    printf ("Catching SIGINT\n");
    sleep(3);
    printf (" No SIGINT within 3 seconds\n");
}   

void sigint_handler(int signal_num) {
    printf("caught SIGINT with signum : %d\n\n", signal_num);
    exit(0);
}