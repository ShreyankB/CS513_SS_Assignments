/*
    4. Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
*/

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    int fd = open("./03.c", O_RDWR);

    if (fd == -1)
        printf("error: %s\n", strerror(errno));
    else
        printf("opened file with fd %d \n", fd);

    //using O_EXCL mode
    fd = open("./05.c", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

    /*
        since we've used O_EXCL,
            if given file already exists than it'll give EEXIST error and fd will be -1
            if given path is symbolic link than regardless of where it points open syscall will fail 

    */
    if (fd == -1)
        printf("error: %s\n", strerror(errno));
    else
        printf("opened file with fd %d ", fd);

    close(fd);
}