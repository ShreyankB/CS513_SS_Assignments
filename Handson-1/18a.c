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
    char r1[10] = "record 1 \n";
    char r2[10] = "record 2 \n";
    char r3[10] = "record 3 \n";

    int fd = open("./db1", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IROTH);

    if(fd == -1) {
        printf("error: %s\n",strerror(errno));
        return 0;
    }

    // applied 3 record locks and written parallely(i.e without releasing other locks) 
    // into file to show case that record locking is done not mandatory locking 
    struct flock f1;
    struct flock f2;
    struct flock f3;

    f1.l_type = F_WRLCK;
    f1.l_whence = SEEK_SET;
    f1.l_start = 0;
    f1.l_len = sizeof(sizeof(r1));
    f1.l_pid = getpid();
    fcntl(fd, F_SETLKW, &f1);

    f2.l_type = F_WRLCK;
    f2.l_whence = SEEK_SET;
    f2.l_start = sizeof(r1)+1;
    f2.l_len = sizeof(r2);
    f2.l_pid = getpid();
    fcntl(fd, F_SETLKW, &f2);

    f3.l_type = F_WRLCK;
    f3.l_whence = SEEK_SET;
    f3.l_start = sizeof(r1) + sizeof(r2) + 1;
    f3.l_len = sizeof(r3);
    f3.l_pid = getpid();
    fcntl(fd, F_SETLKW, &f3);

    write(fd, &r1, sizeof(r1));
    write(fd, &r2, sizeof(r2));
    write(fd, &r3, sizeof(r3));

    f1.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &f1);

    f2.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &f1);
    
    f3.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &f1);

    close(fd);
}