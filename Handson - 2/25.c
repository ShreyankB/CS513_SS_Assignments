/*
    25. Write a program to print a message queue's  (use msqid_ds and ipc_perm structures)
        a. access permission
        b. uid, gid
        c. time of last message sent and received   
        d. time of last change in the message queue
        e. size of the queue
        f. number of messages in the queue 
        g. maximum number of bytes allowed 
        h. pid of the msgsnd and msgrcv
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>

int main() {
    key_t key = ftok("aa", 99);
    int msgq_id = msgget(key, 0);

    struct ipc_perm msg_perm;
    struct msqid_ds mq;
    struct msginfo info;

    if(msgq_id == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    msgctl(msgq_id, IPC_STAT, &mq);
    printf("Permissions: %03o\n", mq.msg_perm.mode & 0777);
    printf("Effective UID of owner: %d\n", msg_perm.uid);
    printf("Effective GID of owner: %d\n", msg_perm.gid);
    printf("Effective UID of creator: %d\n", msg_perm.cuid);
    printf("Effective GID of creator: %d\n", msg_perm.cgid);
    printf("Time of last msgsnd: %s", ctime(&mq.msg_stime));
    printf("Time of last msgrce: %s", ctime(&mq.msg_rtime));
    printf("Time of last change: %s", ctime(&mq.msg_ctime));
    printf("Current number of message in queue: %lu\n", mq.msg_qnum);
    printf("Maximum number of bytes allowed in queue: %lu\n", mq.msg_qbytes);
    printf("PID of last msgsnd: %d\n", mq.msg_lspid);    
    printf("PID of last msgrce: %d\n", mq.msg_lrpid);
}