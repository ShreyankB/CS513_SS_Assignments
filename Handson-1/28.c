/*
    28. Write a program to get maximum and minimum real time priority.
*/

#include <sched.h>
#include <stdio.h>

int main() {
    int policy[3] = {SCHED_OTHER, SCHED_FIFO, SCHED_RR};
    char *policy_list[] = {"SCHED_OTHER", "SCHED_FIFO", "SCHED_RR"};
    int ip = 1;

    while(ip >= 1 && ip <= 3) {
        printf("enter scheduling policy number: ");
        printf("\n1.SCHED_OTHER\n2.SCHED_FIFO\n3.SCHED_RR\n4.exit\n:");
        scanf("%d", &ip);

        if(ip >=1 && ip <=3) 
            printf("%s policy\nmin_priority: %d\nmax_priority: %d\n",policy_list[ip-1], sched_get_priority_min(policy[ip-1]),sched_get_priority_max(policy[ip-1]));
        
    }
}