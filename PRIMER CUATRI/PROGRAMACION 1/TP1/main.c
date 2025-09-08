#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nroRandom();
int mayor(int nro1, int nro2, int nro3);
int menor(int nro1, int nro2, int nro3);
void mayorYMenor(int nro1, int nro2, int nro3);
int sumaMenores(int numEj3);
int tablaMult(int numEj4);
int opcionSeleccionada(char seleccion);
int suma();
int resta();
int multiplicacion();
int division();
int pasoANegativo(int numEj6);

int main() {
    // Ej 1:
    int nro = nroRandom();
    //printf("El numero random entre 0 y 100 es: %i", nro);

    /* Ej 2:
    int num1 = 1;
    printf("Nro 1: %i\n", num1);
    int num2 = 2;
    printf("Nro 2: %i\n", num2);
    int num3 = 3;
    printf("Nro 3: %i\n", num3);

    int nroMayor = mayor(num1, num2, num3);
    printf("El numero mayor de los tres es: %i\n", nroMayor);

    int nroMenor = menor(num1, num2, num3);
    printf("El numero menor de los tres es: %i\n", nroMenor);

    */

    /* Ej 3:

    int numEj3 = 0;

    printf("Ingrese un numero: ");
    scanf("%i", &numEj3);
    printf("El numero ingresado es: %i\n", numEj3);

    int suma = sumaMenores(numEj3);

    printf("La suma de los numeros anteriores a %i es: %i\n", numEj3, suma);

    */

    /*Ej 4:

    int numEj4 = 0;

    printf("Ingrese un numero y te damos su tabla de multiplicar: ");
    scanf("%i", &numEj4);
    printf("El numero ingresado es: %i\n", numEj4);

    int resultado = tablaMult(numEj4);

    */

    /*Ej 5:
    char seleccion;

    printf("Si quiere sumar presiones s, \n");
    printf("Si quiere restar presiones r, \n");
    printf("Si quiere multiplicar presiones m, \n");
    printf("Si quiere dividir presiones d. \n");
    scanf(" %c", &seleccion);

    int resultado = opcionSeleccionada(seleccion);

    printf("El resultado es: %i", resultado);

    */

    //Ej 6:

    int numEj6 = 0;

    printf("Ingrese un numero: \n");
    scanf("%i", &numEj6);

    int numNegativo = pasoANegativo(numEj6);

    printf("El numero ingresado es %i, su negativo es %i", numEj6, numNegativo);



    return 0;
}

// Ej 1:

int nroRandom() {
    srand(time(NULL));
    return rand() % 100;
}

// Ej 2:

int mayor(int nro1, int nro2, int nro3) {
    if (nro1 >= nro2 && nro1 >= nro3) {
        return nro1;
    } else if (nro2 >= nro1 && nro2 >= nro3) {
        return nro2;
    } else {
        return nro3;
    }
}

int menor(int nro1, int nro2, int nro3) {
    if (nro1 <= nro2 && nro1 <= nro3) {
        return nro1;
    } else if (nro2 <= nro1 && nro2 <= nro3) {
        return nro2;
    } else {
        return nro3;
    }
}

void mayorYMenor(int nro1, int nro2, int nro3) {
    int max = mayor(nro1, nro2, nro3);
    int min = menor(nro1, nro2, nro3);

    printf("El numero mayor es %i\n", max);
    printf("El numero menor es %i\n", min);
}

// Ej 3:

int sumaMenores(int numEj3) {
    int suma = 0;
    for(int i=1;i<numEj3;i++){
        suma += i;
    }
    return suma;
}

// Ej 4:

int tablaMult(int numEj4) {
    for(int i=1;i<=10;i++){
        int numMultiplicado = 0;
        numMultiplicado = numEj4 * i;

        printf("%i multiplicado por %i es igual a : %i\n", numEj4, i, numMultiplicado);
    }

}

// Ej 5:

int opcionSeleccionada(char seleccion) {
    int resultado = 0;

    if(seleccion == 's'){
     resultado = suma();
    } else if (seleccion == 'r') {
        resultado = resta();
    } else if (seleccion == 'm') {
        resultado = multiplicacion();
    } else if (seleccion == 'd') {
        resultado = division();
    } else {
        printf("El valor ingresado es incorrecto.");
    }

    //Ej 7:

    int num1, num2;
    cargarNumeros(num1, num2);

    return resultado;
}

int suma(){
    int num1 = 0;
    int num2 = 0;


    printf("Ingrese el primer numero:\n");
    scanf("%i", &num1);
    printf("Ingrese el segundo numero:\n");
    scanf("%i", &num2);

    int sumados = num1 + num2;

    return sumados;

}
int resta() {
    int num1 = 0;
    int num2 = 0;

    printf("Ingrese el primer numero:\n");
    scanf("%i", &num1);
    printf("Ingrese el segundo numero:\n");
    scanf("%i", &num2);

    int restados = num1 - num2;

    return restados;

}
int multiplicacion() {
    int num1 = 0;
    int num2 = 0;


    printf("Ingrese el primer numero:\n");
    scanf("%i", &num1);
    printf("Ingrese el segundo numero:\n");
    scanf("%i", &num2);

    int multiplicados = num1 * num2;

    return multiplicados;

}
int division() {
    int num1 = 0;
    int num2 = 0;
    int divididos;


    printf("Ingrese el primer numero:\n");
    scanf("%i", &num1);
    printf("Ingrese el segundo numero:\n");
    scanf("%i", &num2);

    if (num2 == 0) {
        printf("Error: No se puede dividir por cero.\n");
        return 0;
    } else {
        divididos = num1 / num2;
    }



    return divididos;

}

// Ej 6:

int pasoANegativo(int numEj6) {
    int negativo = numEj6 - (numEj6 + numEj6);
    return negativo;
}

// Ej 7:

void cargarNumeros(int *num1, int *num2){
    printf("Cargar un numero: ");
    fflush(stdin);
    scanf("%i", num1);
    printf("Cargar otro numero: ");
    fflush(stdin);
    scanf("%i", num2);
}




