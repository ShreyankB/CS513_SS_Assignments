/*
    21. Write two programs so that both can communicate by FIFO -Use two way communications.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd1 = open("./myfifo1", O_WRONLY);
    int fd2 = open("./myfifo2", O_RDONLY);    
    char buff[20];

    printf("Enter text for pipe :");
    scanf("%[^\n]", buff);
    write(fd1, buff, sizeof(buff));
    read(fd2, buff, sizeof(buff));

    printf("%s", buff);
}