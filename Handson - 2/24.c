/*
    24. Write a program to create a message queue and print the key and message queue id.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    key_t key = ftok("1..", 7);
    int msgq_id;

    msgq_id = msgget(key, IPC_CREAT | IPC_EXCL | 0766);

    if(msgq_id == -1) {
        printf("%s", strerror(errno));
        return 0;
    }
    
    printf("key : %d", key);
    printf("\nkey value in hex 0x%0x", key);
    printf("\nmessage queue id: %d", msgq_id);
}