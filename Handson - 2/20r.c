/*
    20. Write two programs so that both can communicate by FIFO -Use one way communication.
*/
// first execute 20w.c so that pipe'll have something to read.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("./myfifo", O_RDONLY);
    char buff[20];

    if(fd == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    read(fd, buff, sizeof(buff));
    printf("%s", buff);
    close(fd);
}   