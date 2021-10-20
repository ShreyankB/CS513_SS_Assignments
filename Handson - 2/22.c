/*
    22. Write a program to wait for data to be written into FIFO within 10 seconds, 
        use select system call with FIFO.
*/
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
// for writing into pipe use program 20w.c

int main() {
    char buff[20];
    fd_set rfds;
    struct timeval t1;
    int res;
    int fd = open("./myfifo", O_RDONLY);

    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);
    t1.tv_sec = 10;
    t1.tv_usec = 0;

    res = select(fd+1, &rfds, NULL, NULL, &t1);

    if(res == 0){
        printf("didn't received input on fifo within 10 sec");
        return 0;
    }
    else
        printf("**********Data available*****\n");
       

    read(fd, buff, sizeof(buff));
    printf("%s", buff);
}