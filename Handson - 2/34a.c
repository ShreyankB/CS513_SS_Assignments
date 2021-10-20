/*
    34. Write a program to create a concurrent server.
        a. use fork
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>

int main() {
    struct sockaddr_in ser_addr, cli_addr;
    int sd = socket(AF_UNIX, SOCK_STREAM, 0);
    int cl_size = sizeof(cli_addr);
    int nsd;
    char buff[80];

    ser_addr.sin_family = AF_UNIX;
    ser_addr.sin_addr.s_addr = INADDR_ANY;
    ser_addr.sin_port = htons(9999);

    if(sd == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    if(bind(sd, (void *)(&ser_addr), sizeof(ser_addr)) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    if(listen(sd, 5) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    while(1) {
        nsd = accept(sd, (void *)(&cli_addr), &cl_size);

        if(nsd == -1) {
            printf("%s", strerror(errno));
            continue;
        }

        if(!fork()) {
            // close(sd);
            read(nsd, buff, sizeof(buff));
            printf("client: %s", buff);
            write(nsd, "msg received\n", 13);
        }
        else 
            close(nsd);
    }

}