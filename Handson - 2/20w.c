/*
    20. Write two programs so that both can communicate by FIFO -Use one way communication.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("./myfifo", O_WRONLY);
    char buff[20];

    if(fd == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    printf("Enter text for pipe :");
    scanf("%[^\n]", buff);
    write(fd, buff, sizeof(buff));
    close(fd);
}