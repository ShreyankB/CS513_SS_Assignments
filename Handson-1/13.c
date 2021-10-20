/*
    13. Write a program to wait for a STDIN for 10 seconds using select. 
        Write a proper print statement to verify whether the data is available within 10 seconds or not
        (check in $man 2 select).
*/

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    fd_set rfds;
    struct timeval t1;
    int res;

    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);
    t1.tv_sec = 10;
    t1.tv_usec = 0;

    res = select(1, &rfds, NULL, NULL, &t1);

    if(res)
        printf("received input on stdin within 10 sec");
    else
        printf("didn't received input on stdin within 10 sec");
}


