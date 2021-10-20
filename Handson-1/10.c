/*
    10. Write a program to open a file with read write mode, write 10 bytes, 
        move the file pointer by 10 bytes (use lseek) and write again 10 bytes. 
            a. check the return value of lseek
            b. open the file with od and check the empty spaces in between the data. 
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("./temp", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRGRP);

    if (fd == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    if (write(fd, "/* added*/", 10) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    int off = lseek(fd, 10, SEEK_CUR);

    if (off == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    if (write(fd, "/* again*/", 10))
        printf("current offset of file %d", off);

    close(fd);
} 