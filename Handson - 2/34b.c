/*
    34. Write a program to create a concurrent server.
        a. use pthread_create
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdlib.h>

void* server_routine(void *);
int main() {
    struct sockaddr_in ser_addr, cli_addr1, cli_addr2;
    int sd = socket(AF_UNIX, SOCK_STREAM, 0);
    int cl_size1 = sizeof(cli_addr1);
    int cl_size2 = sizeof(cli_addr2);
    int nsd1, nsd2;
    char buff[80];
    pthread_t t1, t2;

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


    nsd1 = accept(sd, (void *)(&cli_addr1), &cl_size1);
    nsd2 = accept(sd, (void *)(&cli_addr2), &cl_size2);

    if(nsd1 == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    if(nsd2 == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    if (pthread_create(&t1, NULL, server_routine, &nsd1) == -1)
    {
        printf("%s", strerror(errno));
        return 0;    
    }

    if (pthread_create(&t2, NULL, server_routine, &nsd2) == -1)
    {
        printf("%s", strerror(errno));
        return 0; 
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void* server_routine(void * sd1){
    int *nsd = (int *)sd1;
    char buff[80];  
    printf("%d", *nsd);

    read(*nsd, buff, sizeof(buff));
    printf("client: %s", buff);
    write(*nsd, "msg received\n", 13); 

    return NULL;
}