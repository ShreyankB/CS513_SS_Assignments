/*
    5. Write a program to print the system limitation of 
        d.  maximum number of open files  
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    long int max;
    errno = 0;

    max = sysconf(_SC_OPEN_MAX);
    
    if(errno != 0 && max == -1) 
        printf("%s", strerror(errno));
    else
        printf("maximum number of open files:\t%ld\n", max);
}