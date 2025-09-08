#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#define FILAS 3
#define COLUMNAS 3
#define CHARSSTRING 31
#define CHARSSTRINGFILA 6
#define FILASDETER 2
#define COLUMNDETER 2


int nuevoNumMatriz(int matriz[FILAS][COLUMNAS]);
void mostrarMatriz (int matriz [FILAS][COLUMNAS]);
void matrizRand (int matriz [FILAS][COLUMNAS]);
int sumaMatriz (int matriz1[FILAS][COLUMNAS]);
float promedioMatriz(int matriz1[FILAS][COLUMNAS], int validos);
void buscarNum(int matriz1[FILAS][COLUMNAS]);
int cargarString(char string1[]);
void mostrarString (char string1[]);
int encontrarPalabra (char arrayDeString[FILAS][CHARSSTRING], int cantStrings, char buscado[]);
int encontrarAlf(char arrayDeStringAlf[CHARSSTRINGFILA][CHARSSTRING], int cantStringsAlf, char buscadoAlf[]);
int posMenor (char desordenados[CHARSSTRINGFILA][CHARSSTRING], int pos);
void ordenamiendoSeleecion (char desordenados[CHARSSTRINGFILA][CHARSSTRING]);
int determinante(int matrizDeterminante[FILASDETER][COLUMNDETER]);
void inversa(int nroDeterminante);


int main()
{
    int matriz1[FILAS][COLUMNAS];
    int random[FILAS][COLUMNAS];
    char string1[CHARSSTRING];
    char arrayDeString[FILAS][CHARSSTRING] = {"Jorge", "Maria", "Claudio",};
    char buscado[] = {"Maria"};
    char arrayDeStringAlf[CHARSSTRINGFILA][CHARSSTRING] = {"Ana", "Bety", "Claudio", "Dario", "Enrique", "Fernanda"};
    char buscadoAlf[] = {"Dario"};
    char desordenados[CHARSSTRINGFILA][CHARSSTRING] = {"Claudio", "Fernanda", "Dario", "Bety", "Enrique", "Ana"};
    int matrizDeterminante[FILASDETER][COLUMNDETER] = {{8, 2},{3, 5}};

    int validos = 0;
    int cantStrings = 3;
    int cantStringsAlf = 6;


    srand(time(NULL));

    /*validos = nuevoNumMatriz(matriz1);
    mostrarMatriz(matriz1);
    float promedio = promedioMatriz(matriz1, validos);
    buscarNum(matriz1);
    matrizRand(random);
    mostrarMatriz (random);
    int cantPalabras = cargarString(string1);
    mostrarString(string1);
    int encontrada = encontrarPalabra(arrayDeString, cantStrings, buscado);
    encontrarAlf(arrayDeStringAlf, cantStringsAlf, buscadoAlf);
    ordenamiendoSeleecion(desordenados);*/
    int nroDeterminante = determinante(matrizDeterminante);
    inversa(matrizDeterminante);


    return 0;
}
//EJ 1:
int nuevoNumMatriz(int matriz[FILAS][COLUMNAS]) {
    char continuar = 0;
    int i = 0;
    int j = 0;
    int validos = 0;

    printf("Desea añadir un nuevo numero a la matriz? Ingrese s/n");
    fflush(stdin);
    scanf(" %c", &continuar);

    if (continuar == 's'){
            for(i=0;i<FILAS;i++){
                for(j=0;j<COLUMNAS;j++){
                        printf("Ingrese un nuevo valor a la matriz. fila %i y columna %i: \n", i+1, j+1);
                        fflush(stdin);
                        scanf("%i", &matriz[i][j]);
                        validos ++;
                }
            }

    } else{
        printf("Entendido, no agregamos elementos a la matriz.\n");

    }

    return validos;


}
//EJ 2:
void mostrarMatriz (int matriz [FILAS][COLUMNAS]) {
    int i = 0;
    int j = 0;

    for(i=0;i<FILAS;i++){
            for(j=0;j<COLUMNAS;j++){
                printf("|%02d| ", matriz[i][j]);
            }printf("\n");
    }

}
//EJ 3:
void matrizRand (int matriz [FILAS][COLUMNAS]){
    int i = 0;
    int j = 0;
    char continuar;

    printf("Desea cargar datos aleatorios en una matriz? s\n");
    fflush(stdin);
    scanf(" %c", &continuar);

    if(continuar == 's'){
        for(i=0;i<FILAS;i++){
            for(j=0;j<COLUMNAS;j++){
                    fflush(stdin);
                    matriz[i][j] = rand()%9+1;
                    }
        }
    } else {printf("No se creo una matriz con valores randoms.\n");}


}
//Ej 4:
int sumaMatriz (int matriz1[FILAS][COLUMNAS]) {
    printf("Suma del contenido de la matriz\n");
    int suma = 0;
    int i = 0;
    int j = 0;

    for(i=0;i<FILAS;i++){
        for(j=0;j<COLUMNAS;j++){
            suma += matriz1[i][j];
        }
    }
    printf("%i\n", suma);


    return suma;

}
//EJ 5:
float promedioMatriz(int matriz1[FILAS][COLUMNAS], int validos){
    float promedio = 0.0;
    int suma = sumaMatriz(matriz1);

    promedio = (float)suma / validos;

    printf("El promedio de los %i numeros de la matriz es %.1f\n", validos, promedio);

    return promedio;
}
//EJ 6:
void buscarNum(int matriz1[FILAS][COLUMNAS]) {
    int i = 0;
    int j = 0;
    int encontrado = 0;
    int num = 0;

    printf("Que numero desea buscar en la matriz: \n");
    fflush(stdin);
    scanf("%i", &num);



    for(i=0;i<FILAS;i++){
        for(j=0;j<COLUMNAS;j++){
            if (num == matriz1[i][j]){
                encontrado = matriz1[i][j];
            }
        }

    }
    if(encontrado == num){
            printf("El numero %i se encuentra en la matriz.\n", num);
        } else {
            printf("El numero %i NO se encuentra en la matriz.\n", num);
        }
}
//EJ 7:
int cargarString(char string1[]) {
    printf("Inteduzca su nombre completo ( hasta 30 caracteres ): \n");
    gets(string1);

    int validos = strlen(string1);
    int palabras = 1;

    for(int i=0;i<validos;i++){
        if(string1[i] == ' '){
            palabras ++;
        }
    }
    printf("El String cargado tiene %i palabras\n", palabras);
    return palabras;
}
//EJ 8:
void mostrarString (char string1[]){
    printf("String: ");
    puts(string1);

    return 0;
}
//EJ 9:
int encontrarPalabra (char arrayDeString[FILAS][CHARSSTRING], int cantStrings, char buscado[]){
    printf("\n\n Array de strings: \n\n");
    for (int i = 0; i < cantStrings; i++) {
            mostrarString(arrayDeString[i]);
    }

    for(int i=0;i<cantStrings;i++){
        if(strstr(arrayDeString[i], buscado) != NULL){
            printf("La palabra %s esta dentro del array en %i\n", buscado, i);
            return i;
        }
    }
    return -1;
}
//EJ 10: ( BUSQUEDA BINARIA )
int encontrarAlf(char arrayDeStringAlf[CHARSSTRINGFILA][CHARSSTRING], int cantStringsAlf, char buscadoAlf[]) {
    printf("Arreglo de Strings\n");
    for(int i = 0; i<cantStringsAlf;i++){
        printf("%d: ",i);
        puts(arrayDeStringAlf[i]);
        printf("\n");
    }

    int inicio = 0;
    int fin = cantStringsAlf - 1;

    while(inicio <= fin){
        int medio = (inicio + fin) / 2;
        int comparacion = strcmp(buscadoAlf, arrayDeStringAlf[medio]);

        if(comparacion == 0) {
            printf("'%s' se encuentra en la posicion %d.\n", buscadoAlf, medio);
            return medio;
        } else if (comparacion < 0) {
            fin = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }
    printf("'%s' no fue encontrada.\n", buscadoAlf);
    return -1;
}
//EJ 11: ( ORDENAMIENTO POR SELECCION )
int posMenor (char desordenados[CHARSSTRINGFILA][CHARSSTRING], int pos) {
    int posmenor = pos;

    for (int i = pos + 1; i < CHARSSTRINGFILA; i++) {
        if (strcmp(desordenados[i], desordenados[posmenor]) < 0) {
            posmenor = i;
        }
    }

    return posmenor;
}

void ordenamiendoSeleecion (char desordenados[CHARSSTRINGFILA][CHARSSTRING]) {
    printf("\n\nArreglo desordenado:\n\n");
    for (int i = 0; i < CHARSSTRINGFILA; i++) {
        printf("%d: ",i);
        puts(desordenados[i]);
        printf("\n");
    }


    char aux[CHARSSTRING];

    for (int i = 0; i < CHARSSTRINGFILA - 1; i++){
        int posmenor = posMenor(desordenados, i);

        if (posmenor != i) {
            strcpy(aux, desordenados[i]);
            strcpy(desordenados[i], desordenados[posmenor]);
            strcpy(desordenados[posmenor], aux);
        }
    }

    printf("\nArreglo ordenado:\n\n");
    for (int j = 0; j < CHARSSTRINGFILA; j++) {
        printf("%d: ",j);
        puts(desordenados[j]);
        printf("\n");
    }
}
//EJ 12:
int determinante(int matrizDeterminante[FILASDETER][COLUMNDETER]){
    for(int i=0;i<FILASDETER;i++){
        for(int j=0;j<COLUMNDETER;j++){
            printf("|%02d| ", matrizDeterminante[i][j]);
        } printf("\n");
    }


    int nroDeter = (matrizDeterminante[0][0]*matrizDeterminante[1][1])-(matrizDeterminante[0][1]*matrizDeterminante[1][0]);
    printf("El determinante de la matriz es: %i\n", nroDeter);

    return nroDeter;
}
//EJ 13:
void inversa(int nroDeterminante){
    if(nroDeterminante != 0){
        printf("Como el determinante es distinto de 0, la matriz si tiene inversa.");
    } else {
        printf("Como el determinante es 0, la matriz NO tiene inversa.\n");
    }
}

