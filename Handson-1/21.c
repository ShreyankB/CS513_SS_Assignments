/*
    21. Write a program, call fork and print the parent and child process id.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    
    if(!fork())
        printf("child process id: %d \n", getpid());
    else    
        printf("parent process id: %d \n", getpid());
}