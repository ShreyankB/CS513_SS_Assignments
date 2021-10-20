/*
    3. Write a program to set (any one) system resource limit. Use setrlimit system call. 
*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main() {
    struct rlimit rm;

    //before
    getrlimit(RLIMIT_NICE, &rm);
    printf("ceiling to which process's nice value can be raised.:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);    

    rm.rlim_cur = 10;
    rm.rlim_max = 10;

    //after
    setrlimit(RLIMIT_NICE, &rm);
    printf("ceiling to which process's nice value can be raised.:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);    
}