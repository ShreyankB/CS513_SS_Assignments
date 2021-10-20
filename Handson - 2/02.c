/*
    2. Write a program to print the system resource limits. Use getrlimit system call. 
*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main() {
    struct rlimit rm;

    /*
        RLIMIT_AS: max size of virtual memory in bytes
        RLIMIT_CORE: max file of core size in bytes
        RLIMIT_CPU: amount of cpu time a process can consume in seconds
        RLIMIT_DATA: max size of process's data segment(initialized data, uninitialized data, and heap)
        RLIMIT_FSIZE: This is the maximum size in bytes of files that the process may create.
        RLIMIT_LOCKS: max number of lock fcntl can lease
        RLIMIT_MEMLOCK: max bytes of memory that may be locked into RAM in bytes.
        RLIMIT_MSGQUEUE: amount of bytes that can be allocates to message queue.
        RLIMIT_NICE: ceiling to which process's nice value can be raised.
        RLIMIT_NOFILE: value one greater than the maximum file descriptor number that can be opened by this process.
        RLIMIT_STACK: max size of process stack.
    */
    getrlimit(RLIMIT_AS, &rm);
    printf("max size of virtual memory in bytes:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_CORE, &rm);
    printf("max size of core file in bytes:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_CPU, &rm);
    printf("max size of core file in bytes:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_DATA, &rm);
    printf("max size of process's data segment:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_FSIZE, &rm);
    printf("maximum size in bytes of files that the process may create:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);   
    getrlimit(RLIMIT_LOCKS, &rm);
    printf("max number of lock fcntl can lease:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_MEMLOCK, &rm);
    printf("max bytes of memory that may be locked into RAM in bytes:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_MSGQUEUE, &rm);
    printf("amount of bytes that can be allocated to message queue.:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_NICE, &rm);
    printf("ceiling to which process's nice value can be raised.:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_NOFILE, &rm);
    printf("value one greater than the maximum file descriptor number that can be opened by this process:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
    getrlimit(RLIMIT_STACK, &rm);
    printf("max size of process stack.:\t soft limit: %ld\thard limit%ld\n", rm.rlim_cur, rm.rlim_max);
}