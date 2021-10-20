/*
    28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
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
    struct msqid_ds p1;

    p1.msg_perm.uid = 750;
    p1.msg_perm.gid = 770;
    p1.msg_perm.mode = 0700;
    
    if(msgctl(msgq_id, IPC_SET, &p1) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }
}