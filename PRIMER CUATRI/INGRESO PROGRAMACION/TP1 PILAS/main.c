#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

int main()
{
    /*
    Pila pila;
    inicpila(&pila);

    Pila pila2;
    inicpila(&pila2);

    int numero;

    printf("ingrese un numero");
    scanf("%i", &numero);
    apilar(&pila, numero);
    mostrar(&pila);

    apilar(&pila2, desapilar(&pila));
    mostrar(&pila2);
    mostrar(&pila);

    */

    /*Ej 1:


    Pila dada,aux1,aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    apilar(&dada, 1);
    apilar(&dada, 2);
    apilar(&dada, 3);
    apilar(&dada, 4);
    apilar(&dada, 5);
    mostrar(&dada);

    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));

    mostrar(&aux1);

    apilar(&aux2, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));

    mostrar(&aux2);

    */

    /* Ej 2

    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);
    int num1, num2, num3;

    printf("ingrese el primer numero: ");
    scanf("%i", &num1);
    printf("ingrese el segundo numero: ");
    scanf("%i", &num2);
    printf("ingrese el tercer numero: ");
    scanf("%i", &num3);

    apilar(&origen, num1);
    apilar(&origen, num2);
    apilar(&origen, num3);

    mostrar(&origen);

    apilar(&destino, desapilar(&origen));
    apilar(&destino, desapilar(&origen));
    apilar(&destino, desapilar(&origen));
    mostrar(&destino);

    */

    /* Ej 3



    Pila dada, distintos;
    int num1, num2, num3;

    inicpila(&dada);
    inicpila(&distintos);

    printf("ingrese el primer numero: ");
    scanf("%i", &num1);

    printf("ingrese el segundo numero: ");
    scanf("%i", &num2);

    printf("ingrese el tercer numero: ");
    scanf("%i", &num3);

    if(num1 == 8) {
        apilar(&distintos, num1);
    } else {
        apilar(&dada, num1);
    }

    if(num2 == 8) {
        apilar(&distintos, num2);
    } else {
        apilar(&dada, num2);
    }

    if(num3 == 8) {
        apilar(&distintos, num3);
    } else {
        apilar(&dada, num3);
    }

    mostrar(&dada);
    mostrar(&distintos);

    */

    /* Ej 4

    Pila origen, destino, intermedio;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&intermedio);

    int num1, num2, num3;

    printf("ingrese el primer numero: ");
    scanf("%i",&num1);
    printf("ingrese el segundo numero: ");
    scanf("%i",&num2);
    printf("ingrese el tercer numero: ");
    scanf("%i",&num3);

    apilar(&origen, num1);
    apilar(&origen, num2);
    apilar(&origen, num3);

    mostrar(&origen);

    apilar(&intermedio, desapilar(&origen));
    apilar(&intermedio, desapilar(&origen));
    apilar(&intermedio, desapilar(&origen));

    apilar(&destino, desapilar(&intermedio));
    apilar(&destino, desapilar(&intermedio));
    apilar(&destino, desapilar(&intermedio));

    mostrar(&destino);

    */

    /*Ej 5

    Pila dada, intermedio1, intermedio;
    inicpila(&dada);
    inicpila(&intermedio);
    inicpila(&intermedio1);

    int num1, num2, num3;

    printf("ingrese el primer numero: ");
    scanf("%i",&num1);
    printf("ingrese el segundo numero: ");
    scanf("%i",&num2);
    printf("ingrese el tercer numero: ");
    scanf("%i",&num3);

    apilar(&dada, num1);
    apilar(&dada, num2);
    apilar(&dada, num3);

    mostrar(&dada);

    apilar(&intermedio, desapilar(&dada));
    apilar(&intermedio, desapilar(&dada));
    apilar(&intermedio, desapilar(&dada));

    apilar(&intermedio1, desapilar(&intermedio));
    apilar(&intermedio1, desapilar(&intermedio));
    apilar(&intermedio1, desapilar(&intermedio));

    apilar(&dada, desapilar(&intermedio1));
    apilar(&dada, desapilar(&intermedio1));
    apilar(&dada, desapilar(&intermedio1));

    mostrar(&dada);

    */

    /*ej 6:

    Pila dada, intermedio1, intermedio;
    inicpila(&dada);
    inicpila(&intermedio);
    inicpila(&intermedio1);

    int num1, num2, num3;

    printf("ingrese el primer numero: ");
    scanf("%i",&num1);
    printf("ingrese el segundo numero: ");
    scanf("%i",&num2);
    printf("ingrese el numero TOPE: ");
    scanf("%i",&num3);

    apilar(&dada, num1);
    apilar(&dada, num2);
    apilar(&dada, num3);

    mostrar(&dada);

    apilar(&intermedio, desapilar(&dada));


    apilar(&intermedio1, desapilar(&dada));
    apilar(&intermedio1, desapilar(&dada));

    apilar(&dada, desapilar(&intermedio));

    apilar(&dada, desapilar(&intermedio1));
    apilar(&dada, desapilar(&intermedio1));

    mostrar(&dada);
    */

    /* Ej 7:

    Pila dada, intermedio1, intermedio;
    inicpila(&dada);
    inicpila(&intermedio);
    inicpila(&intermedio1);

    int num1, num2, num3;

    printf("ingrese el numero BASE: ");
    scanf("%i",&num1);
    printf("ingrese el segundo numero: ");
    scanf("%i",&num2);
    printf("ingrese el tercer numero: ");
    scanf("%i",&num3);

    apilar(&dada, num1);
    apilar(&dada, num2);
    apilar(&dada, num3);

    mostrar(&dada);

    apilar(&intermedio1, desapilar(&dada));
    apilar(&intermedio1, desapilar(&dada));

    apilar(&intermedio, desapilar(&dada));


    apilar(&dada, desapilar(&intermedio1));
    apilar(&dada, desapilar(&intermedio1));

    apilar(&dada, desapilar(&intermedio));

    mostrar(&dada);

    */

    /* Ej 8:

    Pila mazo, jugador1, jugador2;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    apilar(&mazo, 1);
    apilar(&mazo, 2);
    apilar(&mazo, 3);
    apilar(&mazo, 4);
    apilar(&mazo, 5);
    apilar(&mazo, 6);

    int i;

    for(i = 0; i < 6; i++)
    {
        if(i % 2 == 0)
            {
            apilar(&jugador1, desapilar(&mazo));
            }
        else{
            apilar(&jugador2, desapilar(&mazo));
        };
    };

    mostrar(&jugador1);
    mostrar(&jugador2);

    */

    /*EJ 9

    Pila a, b;

    inicpila(&a);
    inicpila(&b);

    apilar(&a, 1);
    apilar(&a, 1);
    apilar(&a, 1);
    apilar(&a, 1);
    apilar(&a, 1);

    apilar(&b, 1);
    apilar(&b, 1);
    apilar(&b, 1);
    apilar(&b, 1);

    while (!pilavacia(&a) && !pilavacia(&b)) {
        desapilar(&a);
        desapilar(&b);
    }

    if(!pilavacia(&a) == !pilavacia(&b))
    {
        printf("Las pilas tienen la misma cantidad de elementos");
    }
    else
    {
        printf("Las pilas no tienen la misma cantidad de elementos.");
    }

    */

    /*Ej 10


    int sonPilasIguales(Pila *a, Pila *b) {
    Pila auxA, auxB;
    inicpila(&auxA);
    inicpila(&auxB);

    int iguales = 1; // Suponemos que son iguales

    while (!pilavacia(a) && !pilavacia(b)) {
        int valA = tope(a);
        int valB = tope(b);

        if (valA != valB) {
            iguales = 0;
        }

        apilar(&auxA, desapilar(a));
        apilar(&auxB, desapilar(b));
    }

    // Si una de las pilas a�n tiene elementos, no son iguales
    if (!pilavacia(a) || !pilavacia(b)) {
        iguales = 0;
    }

    // Restaurar las pilas originales
    while (!pilavacia(&auxA)) {
        apilar(a, desapilar(&auxA));
        apilar(b, desapilar(&auxB));
    }

    return iguales;
    }

    Pila a, b;
    inicpila(&a);
    inicpila(&b);

    // Cargar la pila A
    apilar(&a, 1);
    apilar(&a, 2);
    apilar(&a, 3);
    apilar(&a, 4);

    // Cargar la pila B
    apilar(&b, 1);
    apilar(&b, 2);
    apilar(&b, 3);
    apilar(&b, 4);

    if (sonPilasIguales(&a, &b)) {
        printf("Las pilas son completamente iguales.\n");
    } else {
        printf("Las pilas NO son iguales.\n");
    }

    */

    /*Ej 11:

    Pila modelo, DADA, aux;
    inicpila(&modelo);
    inicpila(&DADA);
    inicpila(&aux);

    apilar(&modelo, 1);

    apilar(&DADA, 1);
    apilar(&DADA, 3);
    apilar(&DADA, 1);
    apilar(&DADA, 4);
    apilar(&DADA, 5);


    printf("Pila DADA antes de eliminar elementos diferentes:\n");
    mostrar(&DADA);


    int topeModelo = tope(&modelo);


    while (!pilavacia(&DADA)) {
        int valDada = desapilar(&DADA);
        if (valDada != topeModelo) {
            apilar(&aux, valDada);
        }
    }


    while (!pilavacia(&aux)) {
        apilar(&DADA, desapilar(&aux));
    }

    printf("Pila DADA despu�s de eliminar los elementos iguales al tope de MODELO:\n");
    mostrar(&DADA);

    */

    /* EJ 12:

    Pila modelo, dada, auxM, auxD;
    inicpila(&modelo);
    inicpila(&auxM);
    inicpila(&dada);
    inicpila(&auxD);

    srand(time(NULL));
    int cantidad = rand()%4;
    for(int i = 0; i < cantidad; i++)
    {
        apilar(&modelo, rand()%15 + 1);
    }

    cantidad = rand()%3 + 1;
    for(int i = 0; i < cantidad; i++)
    {
        apilar(&dada, rand()%15 + 1);
    }

    printf("Pila modelo: ");
    mostrar(&modelo);

    printf("Pila dada: ");
    mostrar(&dada);


    while(!pilavacia(&modelo)){
            int topeModelo = tope(&modelo);
        while(!pilavacia(&dada)){
        int topeDada = tope(&dada);
        if(topeModelo == topeDada) {
            desapilar(&dada);
        } else {
            apilar(&auxD, desapilar(&dada));
        }
    }
    while(!pilavacia(&auxD)){
        apilar(&dada, desapilar(&auxD));
    }
    apilar(&auxM, desapilar(&modelo));
    }
    printf("La pila dada ahora es: ");
    mostrar(&dada);

    */

    /*Ej 13:

    Pila dada, limite, mayores;
    inicpila(&dada);
    inicpila(&limite);
    inicpila(&mayores);



    do {
        printf("Desea añadir un elemento nuevo a la pila dada? s o n");
        fflush(stdin);
        scanf(" %c", &control);
    } while(control == 's');

    */



    /*Ej 14:

    Pila dada, par, impar, aux;
    inicpila(&dada);
    inicpila(&par);
    inicpila(&impar);
    inicpila(&aux);

    apilar(&dada, 1);
    apilar(&dada, 3);
    apilar(&dada, 1);
    apilar(&dada, 4);
    apilar(&dada, 4);
    apilar(&dada, 4);


    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada));
        if(!pilavacia(&dada)) {
            apilar(&aux, desapilar(&dada));
        } else {
        apilar(&impar, desapilar(&aux));
    }

    }
    if (pilavacia(&impar)) {
        apilar(&par, desapilar(&aux));
        printf("La pila tiene una cantidad de elementos pares\n");
        mostrar(&par);
    } else {
        printf("La pila tiene una cantidad de elementos impares\n");
        mostrar(&impar);
    }
    */

    /*Ej 1 tp 3:

    Pila pila1, respaldo;
    inicpila(&pila1);
    inicpila(&respaldo);

    srand(time(NULL));
    int cantidad = rand()%10;
    for(int i = 0; i < cantidad; i++)
    {
        apilar(&pila1, rand()%15 + 1);
    }

    mostrar(&pila1);



    int suma = 0;

    while(!pilavacia(&pila1)){
            int topePila = tope(&pila1);
            suma = suma + topePila;
            apilar(&respaldo, desapilar(&pila1));
        }


    printf("La suma de los elementos de la pila es: %i", suma);

    */

    /*Ej 2 tp 3:


    Pila pila1, aux;
    inicpila(&pila1);
    inicpila(&aux);

    int numero = 0;
    char son;

    do {
        printf("Desea añadir un elemento nuevo a la pila dada? s o n");
        scanf(" %c", &son);

        if(son == 's') {
            printf("Ingres un numero:");
            scanf("%i", &numero);
            apilar(&pila1, numero);
        }
    } while(son == 's');



    int contador = 0;

    while(!pilavacia(&pila1)) {
        apilar(&aux, desapilar(&pila1));
        contador++;
    }

    printf("La cantidad de elemntos de la pila es: %i", contador);

    */

    //Ej 3:

    Pila pila1, respaldo;
    inicpila(&pila1);
    inicpila(&respaldo);

    srand(time(NULL));
    int cantidad = rand()%10;
    for(int i = 0; i < cantidad; i++)
    {
        apilar(&pila1, rand()%15 + 1);
    }

    mostrar(&pila1);



    int suma = 0;
    int contador = 0;

    while(!pilavacia(&pila1)){
            int topePila = tope(&pila1);
            suma = suma + topePila;
            apilar(&respaldo, desapilar(&pila1));
            contador++;
    }

    float promedio = (float)suma / contador;

    printf("El promedio de los valores es de: %.2f\n", promedio);




    return 0;
}
