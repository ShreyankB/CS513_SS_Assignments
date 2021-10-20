/*
    30. Write a program to run a script at a specific time using a Daemon process.
*/
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    if(!fork()) {
        setsid();
        chdir("/");
        umask(0);

        while(1) {
            sleep(5);
            printf("Daemon process still running (PID : %d)\n", getpid());
        }
    }
    else 
        exit(0);
}