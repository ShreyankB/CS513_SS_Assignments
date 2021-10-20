/*
    32. Write a program to implement semaphore to protect any critical section
        d. remove the created semaphore
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    key_t key1 = ftok("sema1", 0);
    key_t key2 = ftok("counting_sem", 435);

    int sem_id1 = semget(key1, 1, 0);
    int sem_id2 = semget(key2, 2, 0);

    if(sem_id1 == -1)
        printf("%s", strerror(errno));
    else if(semctl(sem_id1, IPC_RMID, 0) == -1)
        printf("%s", strerror(errno));

    if(sem_id2 == -1)
        printf("%s", strerror(errno));
    else if(semctl(sem_id2, IPC_RMID, 0) == -1)
        printf("%s", strerror(errno));
}
