/*
    11. Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors 
        and check whether the file is updated properly or not.
            a. use dup
            b. use dup2
            c. use fcntl
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("./11.c", O_RDWR | O_APPEND);

    if(fd == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    int d_fd = dup(fd); //using dup
    int d2_fd = dup2(fd, 99);   // using dup2

    if(d_fd == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    if(d2_fd == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    if(write(d_fd, "\n/*\n added using d_fd \n*/\n",26) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    if(write(d2_fd, "/*\n added using d2_fd \n*/\n", 26) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    int fcn_fd = fcntl(fd, F_DUPFD, 3);

    if(fcn_fd == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    if(write(fcn_fd, "/*\n added using d2_fd \n*/\n", 26) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    close(fd);
    close(d_fd);
    close(d2_fd);
    close(fcn_fd);

}
