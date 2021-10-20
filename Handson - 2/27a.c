/*
    27. Write a program to receive messages from the message queue.
        a. with 0 as a flag
*/
// note, first create a message and add a message queue using 26.c, than execute this program
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    key_t key = ftok("mq", 1);
    int msgq_id = msgget(key, 0);
    struct msgbuf {
        long int mtype;
        char mtext[80];
    }msg1;

    if(msgrcv(msgq_id, &msg1, sizeof(msg1.mtext), 10, 0) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    printf("\nmessage type: %ld", msg1.mtype);
    printf("\nmsg: %s", msg1.mtext);
}