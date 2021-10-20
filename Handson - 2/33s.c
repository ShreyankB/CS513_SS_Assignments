/*
    33. Write a program to communicate between two machines using socket.
*/
//server side code
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>

int main() {
    struct sockaddr_in ser_addr, cli_addr;
    int sd = socket(AF_UNIX, SOCK_STREAM, 0);
    int cl_size;
    int nsd;
    char buff[80];

    ser_addr.sin_family = AF_UNIX;
    ser_addr.sin_addr.s_addr = INADDR_ANY;
    ser_addr.sin_port = htons(9999);

    bind(sd, (void *)(&ser_addr), sizeof(ser_addr));
    listen(sd, 5);
    cl_size = sizeof(cli_addr);
    nsd = accept(sd, (void *)(&cli_addr), &cl_size);

    read(nsd, buff, sizeof(buff));
    printf("Client : %s", buff);
    write(nsd, "msg received\n", 13);

    close(nsd);
}