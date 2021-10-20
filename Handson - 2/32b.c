/*
    32. Write a program to implement semaphore to protect any critical section
         b. protect shared memory from concurrent write access
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

union semun {
  int val;      // value for SETVAL 
  struct semid_ds *buf;  // buffer for IPC_STAT, IPC_SET
  unsigned short int *array;  // array for GETALL, SETALL   
};

struct ticket_db{
    int tnum;
};

int main() {
    key_t key = ftok("sema1", 0);
    key_t key2 = ftok("shm", 0);
    int shm_id = shmget(key2, 512, IPC_CREAT | 0744);
    int sem_id = semget(key, 1, IPC_CREAT);
    union semun arg;
    struct ticket_db tdb;
    tdb.tnum = 10;

    if(sem_id == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    if(shm_id == -1) {
        printf("%s", strerror(errno));
        return 0;
    }
    struct ticket_db *tdb1;
    tdb1 = shmat(shm_id, 0, 0);

    arg.val = 1;

    if(semctl(sem_id, 0, SETVAL, arg) == -1) {
        printf("%s", strerror(errno));
        return 0;
    }

    struct sembuf buf = {0, -1, 0};
    semop(sem_id, &buf, 1);
    
    printf("Inside critical section\n");
    printf("Enter to increment ticket number and unlock semaphore\n");
    getchar();

    tdb1->tnum = ++tdb.tnum;

    buf.sem_op = 1;
    semop(sem_id, &buf, 1);
    printf("Outside critical section\n");
}