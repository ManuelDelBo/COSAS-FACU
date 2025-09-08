#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor;
    int * punt = &valor;
    int ** ppunt = &punt;

    printf("Dirección de memoria de valor: %p\n", &valor);
    printf("Dirección de memoria de punt: %p\n", &punt);
    printf("Dirección de memoria de ppunt (puntero doble): %p\n\n\n", &ppunt);

    *punt = 30;
    printf("Dato guardado en 'valor' con puntero simple *punt: %i\n", valor);
    **ppunt = 50;
    printf("Dato guardado en 'valor'con puntero doble **ppunt: %i\n\n", valor);

    //----------------------------------------------------------------------------

    int arreglo[10] = {1,2,3,4,5,6,7,8,9,10};



    return 0;
}

int arregloDinamico (int arreglo[10]){}
