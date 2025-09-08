#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>>

/*
7.	Se tienen 3 procesos A, B y C. Implementar en máquina:
    a.	El código con semáforos de manera tal que la secuencia sea ABC, ABC,ABC…
    b.	¿Y si quiero que la secuencia sea BCA, BCA, BCA…?
*/

/*
//////////////////////////////////////////////////////OPCION 1

sem_t sem;
void *mostrar(char arg)
{
    while(1)
    {
        sem_wait(&sem);
        printf(" %c\n", arg);
        sleep(1);
        sem_post(&sem);

    }
    return NULL;
}


int main()
{
    pthread_t tA,tB,tC;

    sem_init(&sem,0,1);

    pthread_create(&tA,NULL,mostrar,'A');
    pthread_create(&tB,NULL,mostrar,'B');
    pthread_create(&tC,NULL,mostrar,'C');

    sleep(300);


    pthread_join(&tA, NULL);
    pthread_join(&tB, NULL);
    pthread_join(&tC, NULL);



    sem_destroy(&sem);


    return 0;
}
*/

/
//////////////////////////////////////////////////////OPCION 2
sem_t semA, semB, semC;

void* procesoA(void* arg) {
    while(1) {
        sem_wait(&semA);
        printf("A\n");
        //sleep(1);
        sem_post(&semB);
    }
    return NULL;
}

void* procesoB(void* arg) {
    while(1) {
        sem_wait(&semB);
        printf("B\n");
        //sleep(1);
        sem_post(&semC);
    }
    return NULL;
}

void* procesoC(void* arg) {
    while(1) {
        sem_wait(&semC);
        printf("C\n");
        //sleep(1);
        sem_post(&semA);
    }
    return NULL;
}

int main() {
    pthread_t tA, tB, tC;

    sem_init(&semA, 0, 1); // Empieza A
    sem_init(&semB, 0, 0);
    sem_init(&semC, 0, 0);

    pthread_create(&tA, NULL, procesoA, NULL);
    pthread_create(&tB, NULL, procesoB, NULL);
    pthread_create(&tC, NULL, procesoC, NULL);

    sleep(30);  // tiempo de ejecución

    return 0;
}
*/

/*9.	Implementar en máquina la sincronización de los procesos A y B de tal manera que, siendo X una variable global:

A
x=199;
x=x+1;
Print(x);

B
x=500;
x=X/10;
Print(x);

a.	Siempre el resultado de la ejecución sea 200 y 50.
b.	Siempre el resultado de la ejecución sea 50 y 200.

*/
//EJ 9:

sem_t sem1;
sem_t sem2;

int x;

void *A(int* arg)
{
    //sem_wait(&sem1);
    sem_wait(&sem2);

    x=199;
    x=x+1;
    printf("A: %d\n", x);

    //sem_post(&sem2);
    return NULL;
}

void *B(int* arg)
{
    //sem_wait(&sem2);
    sem_wait(&sem1);

    x=500;
    x=x/10;
    printf("B: %d\n", x);

    sem_post(&sem2);

    return NULL;
}

int main()
{
    pthread_t tA, tB;

    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);

    pthread_create(&tA,NULL,A,NULL);
    pthread_create(&tB,NULL,B,NULL);


    sem_post(&sem1);


    pthread_join(tA, NULL);
    pthread_join(tB, NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;
}
*/

//Ej 10:

#define N 5  // Tamaño del buffer

// Semáforos
sem_t espacioLibre;             // Cuenta los espacios libres en el buffer
sem_t elementoDisponible;       // Cuenta los elementos disponibles en el buffer
sem_t manipulacionDelBuffer;    // Mutex para acceso al buffer

// Buffer simulado
int buffer[N];
int in = 0, out = 0;

// Funciones simuladas
void producirUnElemento(int *elemento) {
    static int contador = 1;
    *elemento = contador++;
    printf("Productor produjo: %d\n", *elemento);
}

void depositarElementoEnBuffer(int elemento) {
    buffer[in] = elemento;
    in = (in + 1) % N;
    printf("Productor depositó: %d\n", elemento);
}

int sacarElementoDelBuffer() {
    int elemento = buffer[out];
    out = (out + 1) % N;
    printf("Consumidor sacó: %d\n", elemento);
    return elemento;
}

void consumirElemento(int elemento) {
    printf("Consumidor consumió: %d\n", elemento);
}

// Hilo productor
void *productor(void *arg) {
    int elem;
    while (1) {
        producirUnElemento(&elem);
        sem_wait(&espacioLibre);
        sem_wait(&manipulacionDelBuffer);
        depositarElementoEnBuffer(elem);
        sem_post(&manipulacionDelBuffer);
        sem_post(&elementoDisponible);
        sleep(1);  // Simula tiempo de producción
    }
    return NULL;
}

// Hilo consumidor
void *consumidor(void *arg) {
    int elem;
    while (1) {
        sem_wait(&elementoDisponible);
        sem_wait(&manipulacionDelBuffer);
        elem = sacarElementoDelBuffer();
        sem_post(&manipulacionDelBuffer);
        sem_post(&espacioLibre);
        consumirElemento(elem);
        sleep(2);  // Simula tiempo de consumo
    }
    return NULL;
}

int main() {
    pthread_t hiloProductor, hiloConsumidor;

    // Inicialización de semáforos
    sem_init(&espacioLibre, 0, N);         // Buffer completamente libre
    sem_init(&elementoDisponible, 0, 0);   // Nada disponible para consumir al inicio
    sem_init(&manipulacionDelBuffer, 0, 1); // Mutex con valor 1

    // Crear hilos
    pthread_create(&hiloProductor, NULL, productor, NULL);
    pthread_create(&hiloConsumidor, NULL, consumidor, NULL);

    // Esperar hilos (en un caso real esto nunca termina)
    pthread_join(hiloProductor, NULL);
    pthread_join(hiloConsumidor, NULL);

    // Destruir semáforos
    sem_destroy(&espacioLibre);
    sem_destroy(&elementoDisponible);
    sem_destroy(&manipulacionDelBuffer);

    return 0;
}

