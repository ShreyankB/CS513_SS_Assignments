/*
    5. Write a program to print the system limitation of 
        d. size of a page  
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    long int max;
    errno = 0;

    max = sysconf(_SC_PAGESIZE);
    
    if(errno != 0 && max == -1) 
        printf("%s", strerror(errno));
    else
        printf("size of a page in Bytes:\t%ld\n", max);
}