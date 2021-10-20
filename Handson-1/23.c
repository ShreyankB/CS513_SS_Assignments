/*
    23. Write a program to create a Zombie state of the running program.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    if(!fork()){ 
        printf("%d process will be in zombie state \ncheck it at cat /proc/%d/status | head", getpid(), getpid());
        exit(0);
    }
    else
        sleep(60);
}