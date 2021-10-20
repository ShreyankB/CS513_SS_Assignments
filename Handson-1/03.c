/*
    3. Write a program to create a file and print the file descriptor value. 
       Use creat ( ) system call
*/
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    const char *path = "./temp1";
    mode_t mod = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; 
    int fd = creat(path, mod);

    if(fd == -1)
        printf("error: %s\n", strerror(errno));
    else {
        printf("file descriptor value : %d", fd);
    }
}