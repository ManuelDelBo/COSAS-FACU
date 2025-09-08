#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t s;
int a = 0; // Recurso Compartido
void *p (){
    while(1){
        sem_wait(&s);
        a++;
        //Sleep(5);
        a--;
        printf ("%d \n",a);
        sem_post(&s);
    }
}

int main()
{
    pthread_t h[10];
    int i =0;
    sem_init(&s, 0 , 1);
    for ( i = 0; i<10 ; i++){
        pthread_create (&h[i], NULL, p,NULL);
    }
    Sleep(100);
    return 0;
}
