/*
    29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  SCHED_RR).
*/
#include <sys/types.h>
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    /* constant values:
        SCHED_OTHER = 0
        SCHED_FIFO = 1
        SCHED_RR = 2
    */
    struct sched_param p1;
    p1.sched_priority = 2;
    int pid = getpid();

    char *policy_list[] = {"SCHED_OTHER", "SCHED_FIFO", "SCHED_RR"};
    printf("current scheduling policy %s\n", policy_list[sched_getscheduler(pid)]);

    if(sched_setscheduler(pid, SCHED_FIFO, &p1) == -1) {
        printf("error : %s\n",strerror(errno));
        return 0;
    }
    printf("changed scheduling policy %s\n", policy_list[sched_getscheduler(pid)]);

    if(sched_setscheduler(pid, SCHED_RR, &p1) == -1) {
        printf("error : %s\n",strerror(errno));
        return 0;
    }
    printf("changed scheduling policy %s\n", policy_list[sched_getscheduler(pid)]);
}
