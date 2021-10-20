/*
    33. Write a program to communicate between two machines using socket.
*/
//client side code
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    struct sockaddr_in ser_addr;
    int sd = socket(AF_UNIX, SOCK_STREAM, 0);
    char buff[80];

    ser_addr.sin_family = AF_UNIX;
    ser_addr.sin_addr.s_addr = INADDR_ANY;
    ser_addr.sin_port = htons(9999);

    if(connect(sd, (void *)(&ser_addr), sizeof(ser_addr)) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    write(sd, "Hey, there!!\n", 13);
    read(sd, buff, sizeof(buff));
    printf("Server : %s", buff);
}