/*
    7. Write a program to copy file1 into file2 ($cp file1 file2).
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd1 = open("./07.c", O_RDONLY);
    int fd2 = open("./temp.c", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IROTH);

    if(fd1 == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    if(fd2 == -1) {
        printf("error: %s\n", strerror(errno));
        return 0;
    }

    char temp = 'a';

    while(read(fd1, &temp, 1))
        write(fd2, &temp, 1);
    //check for error handling

    close(fd1);
    close(fd2);
}