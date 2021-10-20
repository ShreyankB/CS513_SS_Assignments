/*
    20. Find out the priority of your running program. Modify the priority with nice command.
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    errno = 0;
    int priority = getpriority(PRIO_PROCESS, 0);
    
    if(errno != 0){
        printf("error: %s\n",strerror(errno));
        return 0;    
    }

    printf("priority for current process : %d\n", priority); //check for error handling

    //changing priority using nice
    priority = nice(5);
    if(errno != 0){
        printf("error: %s\n",strerror(errno));
        return 0;    
    }

    printf("updated priority : %d\n", priority);    

    //changing priority using setpriority
    if(setpriority(PRIO_PROCESS, 0, 6) == -1)
        printf("error: %s\n",strerror(errno));
    else
        printf("updated priority using setpriority: %d", getpriority(PRIO_PROCESS, 0)); 
}