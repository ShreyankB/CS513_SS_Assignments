/*
    18. Write a program to perform Record locking.
        a. Implement write lock
        b. Implement read lock
        Create three records in a file. Whenever you access a particular record, first lock it then modify/access 
        to avoid race condition.
*/
//18a creates file adds 3 records
//18b acquires writelock on record 2 and modifies it
//18c tries to acquire readlock on record 1 and record 2.

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("./db1", O_WRONLY);

    if(fd == -1) {
        printf("error: %s\n",strerror(errno));
        return 0;
    }

    struct flock f1;

    f1.l_type = F_WRLCK;
    f1.l_whence = SEEK_SET;
    f1.l_start = 11;
    f1.l_len = 10;
    f1.l_pid = getpid();
    fcntl(fd, F_SETLKW, &f1);
    printf("%ld", lseek(fd, 10, SEEK_SET));
    
    write(fd, "record nw\n", 10);
    printf("acquired lock and upadted record 2 \n");
    printf("press enter to release lock \n");
    getchar();

    f1.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &f1);
    printf("released lock");

    close(fd);
}