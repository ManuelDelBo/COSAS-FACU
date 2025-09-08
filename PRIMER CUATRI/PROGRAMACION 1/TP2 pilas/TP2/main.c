#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

void ingresarElementoPila(Pila *pila1);
void cambiarPila(Pila *pila1, Pila *pilaCopia);
void copiaMismoOrden (Pila *pila1, Pila *pilaIgual, Pila *pilaCopia);
void menor(Pila *pila1);
void ordenamientoPorSeleccion (Pila *pila1, Pila *pilaOrdenada);
void regresarAPila1 (Pila *pila1, Pila *pilaIgual, Pila *pilaCopia, Pila *pilaOrdenada);
void insertarOrdenada (Pila *pila1, Pila *pilaOrdenada);
void sumaPrimeros(Pila *pila1);
int promedio(Pila *pila1);
int sumaElementos(Pila *pila1);
int cuenta(Pila *pila1);
int division(int suma, int cantidad);
int digitosContinuos(Pila *pilaDigito);

int main()
{
    Pila pila1, pilaCopia, pilaIgual, pilaOrdenada, pilaDigito;
    inicpila(&pila1);
    inicpila(&pilaCopia);
    inicpila(&pilaIgual);
    inicpila(&pilaOrdenada);
    inicpila(&pilaDigito);


    ingresarElementoPila(&pila1);
    cambiarPila(&pila1, &pilaCopia);
    copiaMismoOrden (&pila1, &pilaIgual, &pilaCopia);
    regresarAPila1(&pila1, &pilaIgual, &pilaCopia, &pilaOrdenada);
    menor(&pila1);
    ordenamientoPorSeleccion (&pila1, &pilaOrdenada);
    insertarOrdenada (&pila1, &pilaOrdenada);
    regresarAPila1(&pila1, &pilaIgual, &pilaCopia, &pilaOrdenada);
    sumaPrimeros(&pila1);
    int prmedio = promedio(&pila1);
    int digitosContRta = digitosContinuos(&pilaDigito);


    return 0;
}

void ingresarElementoPila(Pila *pila1){
    char continuar;
    int numPila = 0;

    do{
        printf("Desea añadir un elemento a la pila?\n Ingrese s o n\n");
        scanf(" %c", &continuar);

        if(continuar == 's') {
            printf("Ingrese un numero a la pila: \n");
            scanf("%i", &numPila);
            apilar(pila1, numPila);
        }

    }while(continuar == 's');

    printf("La pila se ve asi: \n");

    mostrar(pila1);

}

void cambiarPila(Pila *pila1, Pila *pilaCopia) {
    char continuar;

    printf("Desea pasar todos los elementos de pila1 a pilaCopia?\n Ingrese s o n\n");
    scanf(" %c", &continuar);

    if (continuar == 's') {
        while (!pilavacia(pila1)) {
            int elemento = desapilar(pila1);
            apilar(pilaCopia, elemento);
        }
        printf("Se pasaron todos los elementos a pilaCopia.\n");
        mostrar(pilaCopia);
    } else {
        printf("Ok, no se pasaron los elementos.\n");
    }

}

void copiaMismoOrden(Pila *pila1, Pila *pilaIgual, Pila *pilaCopia)
{
    char continuar;

    printf("Desea pasar todos los elementos de pila1 a pilaIgual en el mismo orden?\n Ingrese s o n\n");
    scanf(" %c", &continuar);

    if (continuar == 's')
    {
        if(!pilavacia(pila1)) {
            Pila auxiliar;
            inicpila(&auxiliar);


            while (!pilavacia(pila1))
            {
                int elemento = desapilar(pila1);
                apilar(&auxiliar, elemento);
            }

            while (!pilavacia(&auxiliar))
            {
                int elemento = desapilar(&auxiliar);
                apilar(pilaIgual, elemento);
            }
            while (!pilavacia(&auxiliar))
            {
                int elemento = desapilar(&auxiliar);
                apilar(pila1, elemento);
                apilar(pilaIgual, elemento);
            }

        }

        if(!pilavacia(&pilaCopia)) {
            Pila auxiliar;
            inicpila(&auxiliar);

            while (!pilavacia(pilaCopia))
            {
                int elemento = desapilar(pilaCopia);
                apilar(pilaIgual, elemento);
            }
            while (!pilavacia(&auxiliar))
            {
                int elemento = desapilar(&auxiliar);
                apilar(pilaCopia, elemento);
                apilar(pilaIgual, elemento);
            }

        }

        printf("Los elementos estan en pilaIgual en el mismo orden que estaban orignalmente en pila1.\n");
        mostrar(pilaIgual);
    }else
    {
        printf("No se pasaron los elementos.\n");
    }


}

void menor(Pila *pila1) {

    char continuar = 0;

    printf("Desea encontrar y eliminar el menor elemento de la pila?\n Ingrese s o n\n");
    scanf(" %c", &continuar);

    if(continuar == 's') {
        Pila aux, aux2;
        inicpila(&aux);
        inicpila(&aux2);

        int nroMenor = tope(pila1);

        while (!pilavacia(pila1)) {
            int elemento = desapilar(pila1);
            if (elemento < nroMenor) {
                nroMenor = elemento;
            }
            apilar(&aux, elemento);
        }

        while (!pilavacia(&aux)) {
            int elemento = desapilar(&aux);
            if (elemento != nroMenor) {
                apilar(&aux2, elemento);
            }
        }

        while (!pilavacia(&aux2)) {
            apilar(pila1, desapilar(&aux2));
        }

        printf("El número menor eliminado es %i\n", nroMenor);
        printf("Pila1 sin el menor elemento: \n");
        mostrar(pila1);

    } else {
        printf("Entendido, no se busco el menor\n.");

    }
    return 0;
}

void ordenamientoPorSeleccion (Pila *pila1, Pila *pilaOrdenada){
    char continuar = 0;

    printf("Desea ordenar el contenido de pila1?\n Ingrese s o n\n");
    scanf(" %c", &continuar);

    if(continuar == 's') {
        Pila aux;
        inicpila(&aux);

        printf("Pila1 desordenada: \n");
        mostrar(pila1);

        while(!pilavacia(pila1))
        {
            int menor = desapilar(pila1);

            while(!pilavacia(pila1))
            {
                int elemento = desapilar(pila1);
                if(menor > elemento)
                {
                    apilar(&aux, menor);
                    menor = elemento;
                }
                else
                {
                    apilar(&aux, elemento);
                }

            }

            apilar(pilaOrdenada, menor);
            while(!pilavacia(&aux))
            {
                apilar(pila1, desapilar(&aux));
            }


        }

        printf("Nueva pila ordenada: \n");
        mostrar(pilaOrdenada);

    } else {
        printf("Entendido, no se ordeno el contenido.\n");
    }


    return 0;
}
void regresarAPila1 (Pila *pila1, Pila *pilaIgual, Pila *pilaCopia, Pila *pilaOrdenada) {
    if(pilavacia(pila1)){
        if(!pilavacia(&pilaCopia)) {
            while(!pilavacia(pilaCopia)) {
                int elemento = desapilar(pilaCopia);
                apilar(pila1, elemento);
            }
        }
        if(!pilavacia(&pilaIgual)) {
            while(!pilavacia(pilaIgual)) {
                int elemento = desapilar(pilaIgual);
                apilar(pila1, elemento);
            }
        }
        Pila aux;
        inicpila(&aux);

        if(!pilavacia(&pilaOrdenada)) {
            while(!pilavacia(pilaOrdenada)) {
                int elemento = desapilar(pilaOrdenada);
                apilar(&aux, elemento);
            }
            while(!pilavacia(&aux)) {
                int elemento = desapilar(&aux);
                apilar(pila1, elemento);
            }
        }
    }

    return 0;

}
void insertarOrdenada (Pila *pila1, Pila *pilaOrdenada) {
    int contador = 0;
    int num = 0;

    printf("Desea isertar un nuevo numero en la pila y que este ordenado? \n Ingrese s o n\n");
    scanf(" %c", &contador);

    if(contador == 's') {
        printf("Entendido, que numero desea ingresar? \n");
        scanf(" %i", &num);

        apilar(pila1, num);

        while(!pilavacia(pilaOrdenada)){
            int elemento = desapilar(pilaOrdenada);
            apilar(pila1, elemento);
        }
        ordenamientoPorSeleccion (pila1, pilaOrdenada);

        printf("El numero %i se insertó correctamente\n", &num);
        mostrar(pilaOrdenada);
    } else {
        printf("Entendido, no se insertarà ningun elemento.\n");
    }
    return 0;
}
void sumaPrimeros(Pila *pila1){
    char continuar = 0;

    printf("Desea sumar el tope y el anterior de la pila?\n Ingrese s o n\n");
    scanf(" %c", &continuar);

    if(continuar == 's') {
        Pila aux;
        inicpila(&aux);
        int num1 = desapilar(pila1);
        int num2 = desapilar(pila1);
        int suma = num1 + num2;

        apilar(pila1, num2);
        apilar(pila1, num1);

        printf("La suma de %i y de %i es:\n %i \n", num1, num2, suma);
        mostrar(pila1);

    } else {
        printf("Entendido, no se realizo al suma\n.");

    }

    return 0;


}
int promedio(Pila *pila1){

    char continuar = 0;

    printf("Desea caluclar el promedio de los numeros de la pila?\n Ingrese s o n\n");
    scanf(" %c", &continuar);

    if(continuar == 's') {
        int suma = sumaElementos(pila1);
        int contador = cuenta(pila1);

        if (contador == 0) {
            printf("No hay elementos en la pila para calcular el promedio.\n");
            return 0;
        }


        int resultado = division(suma, contador);
        printf("Perfecto, el resultado es %i", resultado);
        return resultado;
    }


    return 0;

}
int sumaElementos(Pila *pila1){
    Pila aux;
    inicpila(&aux);
    int suma = 0;

    while(!pilavacia(pila1)) {
        int elemento = desapilar(pila1);
        suma += elemento;
        apilar(&aux, elemento);
    }


    while(!pilavacia(&aux)) {
        int elemento = desapilar(&aux);
        apilar(pila1, elemento);
    }

    return suma;

}
int cuenta(Pila *pila1){
    Pila aux;
    inicpila(&aux);
    int contador = 0;

    while(!pilavacia(pila1))
    {
        int elemento = desapilar(pila1);
        apilar(&aux, elemento);
        contador ++;
    }
    while(!pilavacia(&aux))
    {
        int elemento = desapilar(&aux);
        apilar(pila1, elemento);
    }

    return contador;

}
int division(int suma, int cantidad){
    if (cantidad == 0) {
        printf("Error: División entre 0\n");
        return 0;
    }
    return suma / cantidad;
}
int digitosContinuos(Pila *pilaDigito) {
    Pila aux;
    inicpila(&aux);
    int numeroDecimal = 0;
    int multiplicador = 1;
    char continuar;
    int numPila = 0;

    printf("Desea ingreesar digitos para realizar un numero continuo?\n Ingrese s o n\n");
    scanf(" %c", &continuar);

    if(continuar == 's') {
        ingresarElementoPila(pilaDigito);
    }
    //En este while paso todos los digitos a aux, para poder tenerlo dado vuelta
    while(!pilavacia(pilaDigito)){
        int nro = desapilar(pilaDigito);
        apilar(&aux, nro);
    }
    //Aca voy pasando nro por numero, guardando en numerdoDecimal dicho numero multipplicado por la potencia que
    //corresponde, primero potencia de 10, despues de 100, 1000, etc. gracias a la linea multiplicador += 10
    while(!pilavacia(&aux)) {
        int nro = desapilar(&aux);
        numeroDecimal += nro * multiplicador;
        multiplicador *= 10;
    }

    printf("El numero es: %i \n", numeroDecimal);

    return numeroDecimal;
}



























