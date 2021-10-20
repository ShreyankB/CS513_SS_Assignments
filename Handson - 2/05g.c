/*
    5. Write a program to print the system limitation of 
        g.  number of currently available pages in the physical memory. 
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    long int max;
    errno = 0;

    max = sysconf(_SC_AVPHYS_PAGES);
    
    if(errno != 0 && max == -1) 
        printf("%s", strerror(errno));
    else
        printf(" number of currently available pages in the physical memory. :\t%ld\n", max);
}