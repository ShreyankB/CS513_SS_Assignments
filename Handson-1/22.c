/*
    22. Write a program, open a file, call fork, and then write to the file by both the child as well as the parent
        processes. Check output of the file.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("./22.c", O_WRONLY | O_APPEND);

    if(fd == -1) {
        printf("error %s\n",strerror(errno));
        return 0;
    }

    if(!fork()) 
        write(fd, "\n/*\nadded by child process\n*/", 29);
    else 
        write(fd, "\n/*\nadded by parent process\n*/", 30);
    
    close(fd);
}
