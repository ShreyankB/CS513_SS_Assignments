/*
    30. Write a program to create a shared memory.
        b. attach with O_RDONLY and check whether you are able to overwrite.
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main() {
    char *data;
    key_t key = ftok("shm1", 0);
    int shm_id = shmget(key, 512, IPC_CREAT | 0744);

    if(shm_id == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    data = shmat(shm_id, 0, SHM_RDONLY);
    
    printf("Data to add in shared memory : ");
    scanf("%s", data);  // since, we're trying to write onto read only space, it'll give segmentation fault.
}   