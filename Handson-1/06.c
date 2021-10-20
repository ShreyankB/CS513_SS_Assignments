/*
    6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    char buf[128];
    int buf_size = 0;

    if(write(STDOUT_FILENO, "what is your name?(127 chars max) \t:", 38) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }
    
    if(read(STDIN_FILENO, buf, 128) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }
    
    for(int i=0; buf[i] != '\0'; i++,buf_size++);   //calculating buffer size

    if(write(STDIN_FILENO, buf, buf_size) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }
}