#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <windows.h>
#define N 5

sem_t mySemaphore1,mySemaphore2,mySemaphore3;

void *f1(void *param)
{
    int i=0;
    while ( i<N){
        sem_wait(&mySemaphore1);
        printf("thread %d\n", param);

        sem_post(&mySemaphore2);
        Sleep(1);
        i++;
    }
}

void *f2(void *param)
{
    int i=0;
    while ( i< N){

        sem_wait(&mySemaphore2);

        printf("thread %d\n", param);

        sem_post(&mySemaphore3);
        Sleep(1);
        i++;
    }
}

void *f3(void *param)
{
    int i=0;
    while (i < N){
        sem_wait(&mySemaphore3);

        printf("thread %d\n", param);

        sem_post(&mySemaphore1);
        Sleep(1);
        i++;
    }
}

int main()
{
        pthread_t myThread[3];

        sem_init(&mySemaphore1, 0, 1);
        sem_init(&mySemaphore2, 0, 0);
        sem_init(&mySemaphore3, 0, 0);

        int one = 1, two = 2, three=3;

        pthread_create(&myThread[0], 0, f1, one);
        pthread_create(&myThread[1], 0, f2, two);
        pthread_create(&myThread[2], 0, f3, three);

        pthread_join(myThread[0], 0);
        pthread_join(myThread[1], 0);
        pthread_join(myThread[2], 0);

        sem_destroy(&mySemaphore1);
        sem_destroy(&mySemaphore2);
        sem_destroy(&mySemaphore3);
        return 0;
}
