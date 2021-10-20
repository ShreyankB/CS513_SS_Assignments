/*
    5. Write a program to create five new files with infinite loop. 
       Execute the program in the background and check the file descriptor table at /proc/pid/fd.
*/
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    int file_cnt = 0;
    char path[10];
    int fd = -1;

    while (1)
    {
        if (file_cnt < 5)
        {
            sprintf(path, "./0%d.c", file_cnt+6);
            fd = creat(path, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
            
            if(fd == -1)
                printf("error: %s\n", strerror(errno));
            else {
                printf("file created \n file descriptor value %d \n", fd);
                file_cnt++;
            }
        }
    }
}