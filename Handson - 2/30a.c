/*
    30. Write a program to create a shared memory.
        a. write some data to the shared memory
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main() {
    char *data;
    key_t key = ftok("shm", 0);
    int shm_id = shmget(key, 512, IPC_CREAT | 0744);

    if(shm_id == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    data = shmat(shm_id, 0, 0);
    
    printf("Data to add in shared memory : ");
    scanf("%s", data);
}   