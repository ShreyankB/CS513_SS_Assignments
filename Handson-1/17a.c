/*
    17. Write a program to simulate online ticket reservation. Implement write lock 
        Write a program to open a file, store a ticket number and exit. Write a separate program, to 
        open the file, implement write lock, read the ticket number, increment the number and print 
        the new ticket number then close the file.
*/

//17a program opens a file. using write lock it'll store a ticket number.
//17b program opens a file. using read lock to read ticket number. using write lock updates it and prints it.

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "17.h"

int main() {
    int fd = open("./db", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IROTH);

    if(fd == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    struct db t1;
    t1.t_num = 22;

    struct flock f1;
    f1.l_type = F_WRLCK;
    f1.l_whence = SEEK_SET;
    f1.l_start = 0;
    f1.l_len = sizeof(t1);
    f1.l_pid = getpid();

    
    if(fcntl(fd, F_SETLKW, &f1) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    if(write(fd, &t1, sizeof(t1)) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    f1.l_type = F_UNLCK;

    if(fcntl(fd, F_SETLK, &f1) == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    close(fd);
}