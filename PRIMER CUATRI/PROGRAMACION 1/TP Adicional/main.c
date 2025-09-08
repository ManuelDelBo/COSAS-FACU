#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

int potencia (int base, int exponente);
int fibonacci(int num1);

int main()
{
    int base = 2;
    int exponente = 3;
    int nro1 = 0;

    int nroPotenciado = potencia(base, exponente);

    printf("%i, potenciado a la %i, es %i\n", base, exponente, nroPotenciado);

    printf("Intoduzca el numero: \n");
    scanf("%i", &nro1);

    int fibonacciSuma = fibonacci(nro1);

    printf("La sumatoria de fibonacci para el numero %i es %i\n", nro1, fibonacciSuma);

    return 0;
}

int potencia (int base, int exponente){
    int numMulti = base;

    for(int i = 0;i<exponente;i++){
        numMulti = numMulti * base;
    }
    return numMulti;

}

int fibonacci(int num1) {
    if (num1 == 0) return 0;
    if (num1 == 1) return 1;

    int a = 0, b = 1, sum = 1;

    for (int i = 2; i <= num1; i++) {
        int aux = a + b;
        sum = aux;
        a = b;
        b = aux;
    }

    return sum;
}


