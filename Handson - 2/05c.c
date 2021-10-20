/*
    5. Write a program to print the system limitation of 
       c. number of clock ticks (jiffy) per second.  
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    long int max;
    errno = 0;

    max = sysconf(_SC_CLK_TCK);
    
    if(errno != 0 && max == -1) 
        printf("%s", strerror(errno));
    else
        printf(" number of clock ticks (jiffy) per second:\t%ld\n", max);
}