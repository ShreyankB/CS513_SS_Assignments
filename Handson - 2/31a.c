/*
    31. Write a program to create a semaphore and initialize value to the semaphore.
         a. create a binary semaphore
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
  int val;      // value for SETVAL 
  struct semid_ds *buf;  // buffer for IPC_STAT, IPC_SET
  unsigned short int *array;  // array for GETALL, SETALL   
 };

int main() {
    key_t key = ftok("sem", 0);
    int sem_id = semget(key, 1, IPC_CREAT|0644);
    union semun arg;
    arg.val = 1;

    semctl(sem_id, 0, SETVAL, arg);
}