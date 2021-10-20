/*
    7. Write a simple program to print the created thread ids.
*/
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void* thread_routine(void *);

int main() {
    pthread_t t1, t2, t3;
    if(pthread_create(&t1, NULL, (void*)thread_routine, NULL) != 0)
        printf("%s", strerror(errno));

    if(pthread_create(&t2, NULL, (void*)thread_routine, NULL) != 0)
        printf("%s", strerror(errno));

    if(pthread_create(&t3, NULL, (void*)thread_routine, NULL) != 0)
        printf("%s", strerror(errno));


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
}

void* thread_routine(void *args) {
    printf("Thread id :\t %ld\n", pthread_self());     
    return NULL;
}

