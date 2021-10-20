/*
    9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
       signal - Use signal system call.
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signal_num);

int main() {

    // ignore SIGINT
    signal(SIGINT, SIG_IGN);
    printf("catching SIGINT --> will ignore it if catched\n");
    sleep(3);
    printf("No SIGINT in 3 sec");

    // reseting default action SIGINT
    signal(SIGINT, sigint_handler);
    printf("catching SIGINT --> will execute reseted handler\n");
    sleep(3);
    printf("No SIGINT in 3 sec");
}   

void sigint_handler(int signal_num) {
    printf("caught SIGINT with signum : %d\n\n", signal_num);
    exit(0);
}