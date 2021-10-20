/*
    16. Write a program to perform mandatory locking.
        a. Implement write lock
        b. Implement read lock
*/
// 16a program will acquire mandatory write lock
// 16b program will acquire mandatory read lock

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("./temp", O_RDONLY);
    
    if(fd == -1){
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    struct flock f1;
    f1.l_type = F_RDLCK;
    f1.l_whence = SEEK_SET;
    f1.l_start = 0;
    f1.l_len = 0;
    f1.l_pid = getpid();

    printf("\ntrying to acquire read lock...\n");
    int res = fcntl(fd, F_SETLKW, &f1);
    if(res == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }
    
    printf("read lock applied on temp file");
    printf("\npress enter to unlock");
    getchar();

    f1.l_type = F_UNLCK;

    res = fcntl(fd, F_SETLK, &f1);
    if(res == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    printf("\nlock released");
    close(fd);
}