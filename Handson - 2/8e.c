/*
    8. Write a separate program using signal system call to catch the following signals
         e. SIGALRM (use setitimer system call)
*/
#include <sys/time.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler();

int main() {
    struct itimerval t1;
    t1.it_value.tv_sec = 10;
    t1.it_value.tv_usec = 10;

    t1.it_interval.tv_sec = 10;
    t1.it_interval.tv_usec = 10;

    if(setitimer(ITIMER_REAL, &t1, NULL) == -1) 
        printf("%s", strerror(errno));

    signal(SIGALRM, sig_handler);

    while(1);
}

void sig_handler() {
    printf("Alarm triggered after 10 sec.\n");
    exit(0);
}