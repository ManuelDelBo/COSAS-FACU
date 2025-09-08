#include <stdio.h>
#include <stdlib.h>
#include "../../pila.h"
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>



#define DIAS 10
#define FILAS 2
#define COLUMNAS 8
#define LONGSTR 16

//EJ 1:
void cargaPilaUsr(Pila *pilaDatos, int diasMes);
void cargaPilaRandom(Pila *pilaDatos, int diasMes);
//EJ 2:
int separarPrecipitaciones (Pila pilaDatos, int diasMes, Pila *pilaLLuvias, int vectorLluvias[DIAS]);
//EJ 3:
float promedio0a60(Pila pilaLLuvias);
void mayoresPrecipitaciones(Pila pilaDatos);
//EJ 4:
int buscaMaxima(int vectorLluvias[DIAS], int validosVLL);
int buscaMinima(Pila pilaLluvias);
void informaMaxMin(Pila pilaLLuvias, int vectorLluvias[DIAS], int validosVLL);
//EJ 5:
void extraVocales(char stringEj5[], Pila *pilaVocales);
//EJ 6:
void armaFrase(char matrizLetras[FILAS][COLUMNAS]);
//PRACTICAS PROPIAS
void cadenaCopiada(char stringEj5[LONGSTR]);






int main()
{
    //EJ 1:
    int diasMes = 10;
    Pila pilaDatos;
    inicpila(&pilaDatos);


    //cargaPilaUsr(&pilaDatos, diasMes);
    cargaPilaRandom(&pilaDatos,  diasMes);

    //EJ 2:
    int vectorLluvias[DIAS];
    Pila pilaLLuvias;
    inicpila(&pilaLLuvias);
    int validosVLL = separarPrecipitaciones (pilaDatos, diasMes, &pilaLLuvias, vectorLluvias);

    //EJ 3:
    float promedioPLL = promedio0a60(pilaLLuvias);
    mayoresPrecipitaciones(pilaDatos);

    //EJ 4:
    informaMaxMin(pilaLLuvias, vectorLluvias, validosVLL);

    //EJ 5:
    char stringEj5[] = "Mario";
    Pila pilaVocales;
    inicpila(&pilaVocales);

    extraVocales(stringEj5, &pilaVocales);

    //EJ 6:
    char matrizLetras[FILAS][COLUMNAS] = {{'a','b','c','d','e','f','g',' '},{'i','j','k','l','m','n','o','p'}};
    armaFrase(matrizLetras);

    //PRACTICAS PROPIAS
    cadenaCopiada(stringEj5);





    return 0;
}

//EJ 1:
void cargaPilaUsr(Pila *pilaDatos, int diasMes) {
    printf("Cargue los datos por dia en la pila: \n");

    for(int i=0;i<diasMes;i++){
        printf("Cargue presipitaciones diarias entre 0mmm y 180mmm: \n");
        int aux = 0;
        fflush(stdin);
        scanf("%i", &aux);
        apilar(pilaDatos, aux);
    }
    mostrar(pilaDatos);
}
void cargaPilaRandom(Pila *pilaDatos, int diasMes) {
    printf("CARGA AUTOMATICA\n");
    srand(time(NULL));

    for(int i=0;i<diasMes;i++){
        int aux = rand()%180;
        apilar(pilaDatos, aux);
    }
    mostrar(pilaDatos);
}
//EJ 2:
int separarPrecipitaciones (Pila pilaDatos, int diasMes, Pila *pilaLLuvias, int vectorLluvias[DIAS]) {
    int j = 0;

    for(int i=0;i<diasMes;i++){
        int aux = desapilar(&pilaDatos);

        if(aux<=60){
            apilar(pilaLLuvias, aux);
        } else {
            vectorLluvias[j] = aux;
            j++;
        }
    }

    printf("pilaLLuvias (valores entre 0 y 60): \n");
    mostrar(pilaLLuvias);

    printf("\nvectorLluvias (valores entre 61 y 180): \n\n");
    for(int k = 0;k<j;k++){
        printf("%i, ", vectorLluvias[k]);

    }
    printf("\n\n");

    return j;

}
//EJ 3:
float promedio0a60(Pila pilaLLuvias) {
    printf("Promedio de 0 a 60: \n");
    float promedio = 0.00;
    int aux = 0;
    int suma = 0;
    int dias = 0;

    while(!pilavacia(&pilaLLuvias)){
        aux = desapilar(&pilaLLuvias);
        suma += aux;
        dias++;
    }

    promedio = (float)suma/dias;

    printf("%.2f", promedio);
    printf("\n");

    return dias;

}
void mayoresPrecipitaciones(Pila pilaDatos){
    int mayor = desapilar(&pilaDatos);
    int diasMax = 1;

    while(!pilavacia(&pilaDatos)){

        if(mayor<tope(&pilaDatos)){
            mayor = desapilar(&pilaDatos);
        } else if(mayor == tope(&pilaDatos)){
            diasMax++;
            desapilar(&pilaDatos);

        } else{
            desapilar(&pilaDatos);
        }
    }
    printf("La mayor precipitacion fue de %i mm y se reptio %i dias/s. \n", mayor, diasMax);

}
//EJ 4:
int buscaMaxima(int vectorLluvias[DIAS], int validosVLL){
    int posMax  = 0;

    for(int i=0;i<validosVLL;i++){
        if(vectorLluvias[i] > vectorLluvias[posMax]){
            posMax = i;
        }
    }

    return posMax;
}
int buscaMinima(Pila pilaLluvias){
    int min = desapilar(&pilaLluvias);

    while(!pilavacia(&pilaLluvias)){
        int aux = desapilar(&pilaLluvias);
        if(min>aux){
            min = aux;
        }
    }

    return min;
}
void informaMaxMin(Pila pilaLLuvias, int vectorLluvias[DIAS], int validosVLL) {
    int valorMin = buscaMinima(pilaLLuvias);
    int posMax = buscaMaxima(vectorLluvias, validosVLL);
    int valorMax = vectorLluvias[posMax];

    printf("La precipitacion minima es %i mm\n", valorMin);
    printf("La precipitacion maxima es %i mm y su posicion es %i\n", valorMax, posMax + 1);
}
//EJ 5:
void extraVocales(char stringEj5[], Pila *pilaVocales) {
    int lenth = strlen(stringEj5);

    for(int i=0;i<lenth;i++){
        if(stringEj5[i] == 'a' || stringEj5[i] == 'e' ||stringEj5[i] == 'i' || stringEj5[i] == 'o' || stringEj5[i] == 'u'){
            char aux = stringEj5[i];
            apilar(pilaVocales, aux);
        }
    }
    printf("Las vocales que se incluyen en '%s' son: \n", stringEj5);
    while(!pilavacia(pilaVocales)){
        char vocal = (char)desapilar(pilaVocales);
        printf(" %c, ", vocal);
    }
    printf("\n");
}
//EJ 6:
void armaFrase(char matrizLetras[FILAS][COLUMNAS]){
    char stringEj6[LONGSTR];
    int k = 0;

    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            int aux = matrizLetras[i][j];
            stringEj6[k] = aux;
            k++;
        }
    }

    printf("La matriz en formato string es: %s\n", stringEj6);
}
//PRACTICAS PROPIAS
void cadenaCopiada(char stringEj5[LONGSTR]){
    char string1[LONGSTR] = "abc";
    char string2[LONGSTR] = "b";
    char string3[LONGSTR];

    //strcpy(string1, string2);
    //char *puntero = strstr(string1, string2);
    /*for (int i = 0; string1[i] != '\0'; i++) {
            string1[i] = toupper(string1[i]);
    }*/
    printf("Ingrese un string: \n");
    gets(string3);
    puts(string3);
}














