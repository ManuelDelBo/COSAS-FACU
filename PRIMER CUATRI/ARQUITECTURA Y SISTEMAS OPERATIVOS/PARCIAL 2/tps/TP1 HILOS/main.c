#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


/*EJ 4:
void *function(){
    printf("Thread: %d\n", pthread_self);
    pthread_exit(0);
}

int main()
{
    pthread_t th1, th2;
    pthread_create(&th1, NULL, function, NULL);
    pthread_create(&th2, NULL, function, NULL);
    printf("El thread principal continua ejecutrando: %d\n", pthread_self);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);


    return 0;
}
*/

/*EJ 5
#include <windows.h>

#define MAX 10

void *funcion1(int *i)
{
    printf("Thread: %d, el valor de i: %d\n", pthread_self(), i );
    pthread_exit(0);
}

int main()
{
    pthread_t thid[MAX];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for(int i = 0; i < MAX; i++){
        pthread_create(&thid[i], &attr, funcion1, i);
    }

    printf("Start sleep\n");
    Sleep(10000);
    printf("End sleep\n");

    return 0;
}
*/

/*EJ 6
int var = 10;

void *funcion1()
{
    sleep(30);
    var = var*2;
    printf("Thread: %d - valor de var: %d\n", pthread_self(), var);
    pthread_exit(0);
}

void *funcion2()
{
    sleep(5);
    var = var+5;
    printf("Thread: %d - valor de var: %d\n", pthread_self(), var);
    pthread_exit(0);
}

int main()
{
    pthread_t th1, th2;
    pthread_create(&th1,NULL,funcion1,NULL);
    pthread_create(&th2,NULL,funcion2,NULL);
    printf("El thread princial continua ejecutando: %d\n", pthread_self);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    return 0;
}
*/

//EJ 7:
#define MAX 10

void *funcionEj(int *i)
{
    printf("Hola Threads!. Soy el thread %d ejecutando por %d vez\n", pthread_self(), i);
    pthread_exit(0);
}

int main()
{
    pthread_t th[MAX];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    for(int i =0;i<MAX;i++)
    {
        pthread_create(&th[i],&attr,funcionEj,i);
    }

    for(int j=0;j<MAX;j++)
    {
        pthread_join(th[j], NULL);
    }


    return 0;
}



