/*
    32. Write a program to implement semaphore to protect any critical section
        c. protect multiple pseudo resources ( may be two) using counting semaphore
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
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
    key_t key = ftok("counting_sem", 435);
    int sem_id = semget(key, 2, IPC_CREAT|0644);
    union semun arg;
    int fd = open("./db",  O_RDWR);
    struct ticket_db tdb;
    tdb.tnum = 10;

    if(fd == -1) {
        printf("fd:\t %s", strerror(errno));
        return 0;
    }

    if(sem_id == -1) {
        printf("sem_id:\t%s", strerror(errno));
        return 0;
    }

    arg.val = 3;

    if(semctl(sem_id, 0, SETVAL, arg) == -1) {
        printf("sem setval\t%s", strerror(errno));
        return 0;
    }

    struct sembuf buf = {0, -1, 0};
    semop(sem_id, &buf, 1);
    
    printf("Inside critical section\n");
    printf("Enter to increment ticket number and unlock semaphore\n");
    getchar();

    tdb.tnum++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &tdb, sizeof(tdb));
    lseek(fd, 0, SEEK_SET);  
    close(fd);

    buf.sem_op = 1;
    semop(sem_id, &buf, 1);
    printf("Outside critical section\n");

}