/*
    12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to 
        the parent process from the child process.
*/
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    if(!fork()) {
        int ppid = getppid();
        kill(ppid, SIGKILL);
    }
    else {
        while(1)
            printf("Parent process running\n");
   }
}