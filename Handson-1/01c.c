/*
    1. Create the following types of a files using (i) shell command (ii) system call
        c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    // using mkfifo library function
    const char *path = "./fifo1";
    mode_t mode = S_IROTH|S_IRGRP|S_IRUSR;

    int res = mkfifo(path, mode);

    if(res == 0)
        printf("succesfully created fifo file : %s \n", path);
    else if(res == -1)
        printf("error: %s\n", strerror(errno));

    //using mknod syscall
    const char *path1 = "./fifo2";
    mode_t mod = S_IFIFO;
    dev_t dev = S_IFIFO;

    res = mknod(path1, mod, dev);

    if(res == 0)
        printf("successfully created fifo file \n %s", path);
    else if(res == -1)
        printf("error: %s\n", strerror(errno));

}