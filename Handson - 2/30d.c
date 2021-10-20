/*
    30. Write a program to create a shared memory.
         d. remove the shared memory
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main() {
    char *shm_addr;
    key_t key = ftok("shm", 0);
    int shm_id = shmget(key, 512, 0);

    if(shm_id == -1) {
        printf("%s", strerror(errno));
        return 0;
    }
    
    if(shmctl(shm_id, IPC_RMID, NULL) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }
}   