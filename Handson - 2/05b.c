/*
    5. Write a program to print the system limitation of 
        b.  maximum number of simultaneous process per user id.  
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    long int max;
    errno = 0;

    max = sysconf(_SC_CHILD_MAX);
    
    if(errno != 0 && max == -1) 
        printf("%s", strerror(errno));
    else
        printf(" maximum number of simultaneous process per user id:\t%ld\n", max);
}