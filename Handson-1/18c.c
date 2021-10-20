/*
    18. Write a program to perform Record locking.
        a. Implement write lock
        b. Implement read lock
        Create three records in a file. Whenever you access a particular record, first lock it then modify/access 
        to avoid race condition.
*/
//18a creates file adds 3 records
//18b acquires writelock on record 2
//18c tries to acquire readlock on record 1 and record 2.

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("./db1", O_RDONLY);
    char r1[10];
    char r2[10];

    if(fd == -1) {
        printf("error: %s\n",strerror(errno));
        return 0;
    }

    struct flock f1;
    struct flock f2;

    printf("acquiring read lock on record 1");
    f1.l_type = F_RDLCK;
    f1.l_whence = SEEK_SET;
    f1.l_start = 0;
    f1.l_len = 10;
    f1.l_pid = getpid();
    fcntl(fd, F_SETLKW, &f1);
    printf("acquired read lock on record 1");
    read(fd, &r1, sizeof(r1));
    printf("%s\n", r1);

    printf("acquiring read lock on record 2");
    f2.l_type = F_RDLCK;
    f2.l_whence = SEEK_SET;
    f2.l_start = 11;
    f2.l_len = 10;
    f2.l_pid = getpid();
    fcntl(fd, F_SETLKW, &f2);
    printf("acquired read lock on record 2");
    read(fd, &r2, sizeof(r2));
    printf("%s \n", r2);


    f1.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &f1);
    printf("released lock 1");

    f2.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &f1);
    printf("released lock 2");

    close(fd);
}