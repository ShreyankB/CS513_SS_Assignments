/*
    6. Write a simple program to create three threads.
*/
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void* thread1_routine(void *);
void* thread2_routine(void *);
void* thread3_routine(void *);

int main() {
    pthread_t t1, t2, t3;
    if(pthread_create(&t1, NULL, (void*)thread1_routine, NULL) != 0)
        printf("%s", strerror(errno));

    if(pthread_create(&t2, NULL, (void*)thread2_routine, NULL) != 0)
        printf("%s", strerror(errno));

    if(pthread_create(&t3, NULL, (void*)thread3_routine, NULL) != 0)
        printf("%s", strerror(errno));


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
}

void* thread1_routine(void *args) {
    int i = 0;
    while(i++ < 500)    
        printf("thread1_itr : %d\n", i);
    return NULL;
}

void* thread2_routine(void *args) {
    int i = 0;
    while(i++ < 500)    
        printf("thread2_itr : %d\n", i);
    return NULL;
}

void* thread3_routine(void *args) {
    int i = 0;
    while(i++ < 500)    
        printf("thread3_itr : %d\n", i);
    return NULL;
}