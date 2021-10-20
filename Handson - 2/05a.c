/*
    5. Write a program to print the system limitation of 
        a. maximum length of the arguments to the exec family of functions. 
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    long int max;
    errno = 0;

    max = sysconf(_SC_ARG_MAX);
    
    if(errno != 0 && max == -1) 
        printf("%s", strerror(errno));
    else
        printf("maximum length of the arguments to the exec family of functions:\t%ld\n", max);
}