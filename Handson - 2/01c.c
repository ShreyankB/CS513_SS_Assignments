/*
    1. Write a separate program (for each time domain) to set a interval timer in 10sec and 
       10 micro second.
            c. ITIMER_PROF
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

    if(setitimer(ITIMER_PROF, &t1, NULL) == -1) 
        printf("%s", strerror(errno));

    signal(SIGPROF, sig_handler);
    while(1);
}

void sig_handler() {
    printf("Profiling Timer expired after 10 sec.\n");
    exit(0);
}