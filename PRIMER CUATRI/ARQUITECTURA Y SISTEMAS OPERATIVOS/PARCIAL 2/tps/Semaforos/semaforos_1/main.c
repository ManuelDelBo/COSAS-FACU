#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t s;
void *hi (int i){
    while(1){
        sem_wait (&s);
        printf ("Soy el hilo %d \n",i);// seccion critica
        sem_post(&s);
    }
}

int main()
{

   pthread_t h1,h2,h3;
   sem_init(&s, 0 , 1);
   pthread_create (&h1, NULL, hi,1);
   pthread_create (&h2, NULL, hi,2);
   pthread_create (&h3, NULL, hi,3);
   Sleep (300);
    return 0;
}
