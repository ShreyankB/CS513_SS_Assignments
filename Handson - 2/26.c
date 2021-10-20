/*
    26. Write a program to send messages to the message queue. Check $ipcs -q
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

    struct msgbuf {
        long int mtype;
        char mtext[80];
    };

    struct msgbuf msg1 = {20, "This is first message in the queue with mtype 20"};
    struct msgbuf msg2 = {10, "This is first message in the queue with mtype 20"};

    if(msgq_id == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    if(msgsnd(msgq_id, (void *)&msg1, sizeof(msg1.mtext), IPC_NOWAIT) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    if(msgsnd(msgq_id, (void *)&msg2, sizeof(msg2.mtext), IPC_NOWAIT) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }
}