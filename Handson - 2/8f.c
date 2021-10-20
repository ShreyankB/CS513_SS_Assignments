/*
    8. Write a separate program using signal system call to catch the following signals
        f. SIGVTALRM (use setitimer system call)
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

    if(setitimer(ITIMER_VIRTUAL, &t1, NULL) == -1) 
        printf("%s", strerror(errno));
    
    signal(SIGVTALRM, sig_handler);
    while(1);
}

void sig_handler() {
    printf("Virtual Alarm triggered after 10 sec.\n");
    exit(0);
}