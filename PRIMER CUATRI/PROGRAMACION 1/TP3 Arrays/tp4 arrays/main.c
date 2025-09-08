#include <stdio.h>
#include <stdlib.h>
#include "../../pila.h"

#define CANTIDAD 5
#define CANTFLOAT 100
#define CARACTERES 28
#define CANTINVERTIDOS 12
#define CANTCHAR 4
#define CANTCHAR2 7
#define NUMSSUM 5



int ingresarNumArray(int arr[], int validos);
void mostrarArray(int arr[], int validos);
int sumaElementos(int arr[], int validos);
void arrayAPila(int arr[], int validos, Pila pila);
float cargarEnArrFloat (float arrFloat[], int validosFloat);
float sumarFloat (float arrFloat[], int validosFloat);
void buscarEnArray (int arr[], int validos);
int agregarChar (char arrChar[], int validos);
int maximoDelArray(int arr[], int validos);
void capicua(int arr[], int validos);
void invertir(int arrInvertido[], int validos);
int posicionMenor(int arr[], int pos, int validos);
void ordSeleccion(int arr[], int validos);
void insertar(int arr[], int ult, int dato);
void ordenacionInsercion (int arr[], int validos);
void arrIntercalados(char arrABC1[], char arrABC2[], char arrIntercalado[], int validosLetras);
void sumaNumsArray(int arrNums[], int arrSumados[], int validosSuma);

int main()
{
    int arr[CANTIDAD];
    float arrFloat[CANTFLOAT];
    char arrChar[CARACTERES] = {'a', 'b', 'c', 'd', 'e', 'f', 'g' ,'h', 'i', 'j', 'k', 'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char arrABC1[CANTCHAR] = {'a', 'b', 'c'};
    char arrABC2[CANTCHAR] = {'d', 'e', 'f'};
    char arrIntercalado[CANTCHAR2];
    int arrNums[NUMSSUM] = {1, 5, 6, 7, 8};
    int arrSumados[NUMSSUM];


    int validos = 0;
    float validosFloat = 0;
    int validosChar = 26;
    int validosLetras = 3;
    int validosSuma = 5;
    int suma = 0;
    int max = 0;
    float sumaF = 0.0;
    Pila pila1;
    inicpila(&pila1);

    //ej1
    validos = ingresarNumArray(arr, validos);
    //ej2
    if(validos != 0) {
        mostrarArray(arr, validos);
        //ej3
        suma = sumaElementos(arr, validos);
        //ej4
        arrayAPila (arr, validos, pila1);
        //ej6
        buscarEnArray(arr, validos);
        //ej8
        max = maximoDelArray(arr, validos);
        //ej9
        capicua(arr, validos);
        //ej10
        invertir(arr, validos);
        //ej11
        ordSeleccion(arr, validos);
        ordenacionInsercion (arr, validos);
    }

    //ej5
    validosFloat = cargarEnArrFloat(arrFloat, validosFloat);
    if(validosFloat != 0) {
        sumaF = sumarFloat(arrFloat, validosFloat);
    }
    //ej6
    validosChar = agregarChar(arrChar, validosChar);
    //ej12
    arrIntercalados(arrABC1, arrABC2, arrIntercalado, validosLetras);
    //ej13
    sumaNumsArray(arrNums, arrSumados, validosSuma);





    return 0;
}
// EJ 1:
int ingresarNumArray(int arr[], int validos) {
    char continuar;
    int i = 0;

    do{
        printf("Desea ingresar numeros al array? s/n\n");
        scanf(" %c", &continuar);

        if(continuar == 's'){
            printf("Ingrese un numero en la posicion %i: \n", i);
            scanf("%i", &arr[i]);
            printf("Nro ingresado: %i\n", arr[i]);
            i++;
            validos ++;
            } if(continuar != 's' && validos == 0){
                printf("No se agregaron numeros al array\n");
            }

        }while(continuar == 's' && i < CANTIDAD);

    return validos;

}
// EJ 2:
void mostrarArray(int arr[], int validos){
    int i = 0;

    printf("Array: \n");

    while(i<validos){
        //printf("Posicion %i del array: %i\n", i, arr[i]);
        printf("%i, ", arr[i]);
        i++;
    }
    printf("\n");
    printf("La cantidad de enteros que tiene el array es de: %i\n", validos);
}
// EJ 3:
int sumaElementos(int arr[], int validos){

    int suma = 0;
    int i= 0;

    while(i<validos){
        suma += arr[i];
        i++;
    }

    printf("La suma de todos los %i elementos del array es %i\n", validos, suma);

    return suma;

}
// EJ 4:
void arrayAPila (int arr[], int validos, Pila pila) {
    char continuar;
    int i = 0;


    printf("Desea copiar los elementos del array en una pila? s/n\n");
    scanf(" %c", &continuar);

    if(continuar == 's'){
            while(i<validos){
            apilar(&pila, arr[i]);
            i++;
        }
        printf("Listo, elemento copiados en pila: \n");
        mostrar(&pila);
    }
    if(continuar != 's'){
            printf("No se pasaron los elementos a la pila\n");
    }


}
// EJ 5:
float cargarEnArrFloat (float arrFloat[], int validosFloat) {
    char continuar;
    int i = 0;
    printf("\n\nARRAY DE NUMEROS REALES ( CON COMA )\n\n");

    do{
        printf("Desea ingresar numeros con decimales al array? s/n\n");
        scanf(" %c", &continuar);

        if(continuar == 's'){
            printf("Ingrese un numero con un decimal en la posicion %i: \n", i);
            scanf("%f", &arrFloat[i]);
            printf("Nro ingresado: %.1f\n", arrFloat[i]);
            i++;
            validosFloat ++;
            } if(continuar != 's' && validosFloat == 0){
                printf("No se agregaron numeros al array\n");
            }

        }while(continuar == 's' && i < CANTFLOAT);

    return validosFloat;
}
float sumarFloat (float arrFloat[], int validosFloat) {
    float sumaF = 0.0;
    int i = 0;

    while(i<validosFloat){
        sumaF += arrFloat[i];
        i++;
    }
    printf("La suma de los elementos del array es %.1f\n", sumaF);

    return sumaF;

}
// EJ 6:
void buscarEnArray (int arr[], int validos) {
    int numero = 0;
    int i = 0;

    printf("Que numero entero desea buscar?\n");
    scanf("%i", &numero);

    while(i < validos && arr[i] != numero) {
        i++;
    }
    if(i < validos && arr[i] == numero) {
        printf("El numero buscado (%i) se encuentra en la posicion %i\n", numero, i);
    }
    if (i == validos && arr[i] != numero) {
        printf("El numero %i no se encuentra en el array.\n", numero);
    }
}
// EJ 7:
int agregarChar (char arrChar[], int validos) {
    char caracter;
    int i = 0;

    printf("Inserte un caracter en la funcion: \n Caracter: \n");
    scanf(" %c", &caracter);

    while(i < validos && caracter > arrChar[i]) {
        i++;
    }
    for(int j = validos; j > i; j--) {
        arrChar[j] = arrChar[j - 1];
    }
    arrChar[i] = caracter;
    validos++;

    printf("Array actualizado:\n");
    for(int k = 0; k < validos; k++) {
        printf("%c ", arrChar[k]);
    }
    printf("\n");

    return validos;
}
// EJ 8:
int maximoDelArray(int arr[], int validos) {
    int maximo = arr[0];

    for(int i = 1;i<validos;i++){
        if(maximo < arr[i]) {
            maximo = arr[i];
        }
    }
    printf("El maximo de array es %i, \n", maximo);


    return maximo;
}
//EJ 9:
void capicua(int arr[], int validos){
    int i = 0;
    int j = validos - 1;
    int correcto = 1;

    do{
        if(arr[i] == arr[j]){
            i++;
            j--;
        } else {
            correcto -= 1;
        }
    }while(i<j && correcto == 1);

    if(correcto == 1){
        printf("El array es capicua.\n");
    } if (correcto == 0) {
        printf("El array NO es capicuoa.\n");

    }

}
//EJ 10:
void invertir(int arrInvertido[], int validos) {
    int i = 0;
    int j = validos - 1;
    char continuar;
    int temp;

    printf("Arreglo: \n");
    while(i<validos){
        printf("%i, ", arrInvertido[i]);
        i++;
    }
    printf("\n");
    printf("Desea invertirno? s/n \n");
    scanf(" %c", &continuar);

    if(continuar == 's') {
        i = 0;

        while(i < j){
            temp = arrInvertido[i];
            arrInvertido[i] = arrInvertido[j];
            arrInvertido[j] = temp;
            i++;
            j--;
        }
        i = 0;
    }

    printf("Arreglo dado vuelta: \n");
    while(i<validos){
        printf("%i, ", arrInvertido[i]);
        i++;
    }
    printf("\n");
}
//Ej 11:
int posicionMenor(int arr[], int pos, int validos) {
    int menor = arr[pos];
    int posmenor = pos;
    int i = pos + 1;
    while(i<validos)
    {
        if(menor>arr[i]){
            menor = arr[i];
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}
void ordSeleccion(int arr[], int validos) {
    char continuar;

    printf("Desea ordenar por seleccion el array? s/n \n");
    scanf(" %c", &continuar);

    if(continuar == 's'){
        int posmenor;
        int i = 0;

        while(i<validos){
            posmenor = posicionMenor(arr, i, validos);
            int aux = arr[posmenor];
            arr[posmenor] = arr[i];
            arr[i] = aux;
            i++;
        }
        printf("Array ordenado: \n");
        for(int j=0;j<validos;j++){
            printf("%i ", arr[j]);
        }
        printf("\n");
    } else {
        printf("Entendido, no se ordeno.\n");

    }

}
void insertar(int arr[], int ult, int dato){
    int i = ult;
    while(i >= 0 && dato < arr[i]){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = dato;

}
void ordenacionInsercion (int arr[], int validos) {
    char continuar;
    printf("Desea realizar el ordenamiento por insercion? s/n \n");
    scanf(" %c", &continuar);

    if(continuar == 's'){
        for (int i = 1; i < validos; i++) {
            insertar(arr, i - 1, arr[i]);
        }
        printf("Array ordenado: \n");
        for(int j=0;j<validos;j++){
            printf("%i ", arr[j]);
        }
        printf("\n");
    } else {
        printf("Entendido, no se ordeno.\n");

    }

}
//Ej 12:
void arrIntercalados(char arrABC1[], char arrABC2[], char arrIntercalado[], int validosLetras){
    char continuar;
    printf("Desea intercalar los siguientes arrays en uno nuevo?\n");

    for(int i=0;i<validosLetras;i++){
            printf("%c ", arrABC1[i]);
    }
    printf("\n");

    for(int j=0;j<validosLetras;j++){
            printf("%c ", arrABC2[j]);
    }
    printf("\n");

    printf("Introduzca s/n: \n");
    scanf(" %c", &continuar);

    if(continuar == 's'){
        int i = 0;
        int j = 0;
        int k = 0;
        int validosInter = 0;
        while(i < validosLetras && j < validosLetras){
            if(arrABC1[i]< arrABC2[j]){
                arrIntercalado[k++]= arrABC1[i++];
            } else {
                arrIntercalado[k++]= arrABC2[j++];
            }
            validosInter ++;
        }
        while(i < validosLetras){
            arrIntercalado[k++]= arrABC1[i++];
            validosInter ++;
        }
        while(j < validosLetras){
            arrIntercalado[k++]= arrABC2[j++];
            validosInter ++;
        }
        printf("\nARREGLO INTECLADAO\n");
        for(int m=0;m<validosInter;m++){
            printf("%c ", arrIntercalado[m]);
        }
        printf("\n");
    } else {
        printf("Entendido, no se realizo el intercalado.\n");
    }
}
//Ej 13:
void sumaNumsArray(int arrNums[], int arrSumados[], int validosSuma) {
    char continuar;
    printf("Desea generar  otro vector con la suma del contenido de todo los elementos anteriores al índice actual:? s/n \n");
    scanf(" %c", &continuar);

    if(continuar == 's'){
        //Muestro el vector inicial
        printf("Vector inicial: \n");

        for(int i = 0; i<validosSuma; i ++){
            printf("%i", arrNums[i]);
        }
        printf("\n");


        int j = 0;
        int k = 0;
        int aux = 0;
        while(j < validosSuma) {
                aux += arrNums[j];
                arrSumados[k] = aux;
                j++;
                k++;
        }
        //Muestro el nuevo vector inicial
        printf("Vector final: \n");
        int m = 0;
        for(int m = 0; m<validosSuma; m++){
            printf("%i, ", arrSumados[m]);
        }
        printf("\n");

    } else {
        printf("Entendido, no se creo el nuevo array.\n");

    }
}

