/*
    19. Write a program to find out time taken to execute getpidsystem call. Use time stamp counter.
*/

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc () {
    unsigned long long dst;
    __asm__ __volatile__("rdtsc":"=A" (dst));
    return dst;
}

int main() {
    long long int start, end;
    start = rdtsc();

    for(int i=0; i<100; i++)
        getpid();

    end = rdtsc();

    //here, time taken will be (end - start)/(frequency of cpu) (unit will depend upon freq)
    //to check freq of cpu use lsstat command
    printf("time taken := %f nano seconds", (end - start)/2.3); 
}