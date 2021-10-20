/*
    29. Write a program to remove the message queue
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main() {
    key_t key = ftok("mq", 1);
    int msgq_id = msgget(key, IPC_CREAT);

    if(msgctl(msgq_id, IPC_RMID, 0) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }
}