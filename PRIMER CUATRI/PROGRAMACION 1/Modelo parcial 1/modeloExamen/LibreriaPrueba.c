#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "../../pila.h"
#include "libreriaPrueba.h"

#define DIM 8
#define APYNOM 30
#define CARACTERES 40

void cargaArreglos(char tiposMuestras[DIM], char concentracionesMuestras[DIM], int muestras){
    char carga;

    printf("Desea cargar los datos de las muestras manualmente o aleatoriemanete: (m/a)\n");
    scanf(" %c", &carga);

    if(carga == 'm'){
        cargaManual(tiposMuestras, concentracionesMuestras, muestras);
    } if(carga == 'a'){
        cargaRandom(tiposMuestras, concentracionesMuestras, muestras);
    }
}
void cargaManual(char tiposMuestras[DIM], char concentracionesMuestras[DIM], int muestras){
    printf("Ingrese el tipo de muestra y la consentracion: \n");
    int tipo = 0;
    int concentracion = 0;
    for(int i=0;i<muestras;i++){
        printf("Tipo de muestra posición %i: (0, 1 o 3)\n ", i+1);
        scanf("%i", &tipo);
        tiposMuestras[i]= tipo;

        printf("Concentracion de muestra posición %i: (0 a 100)\n ", i+1);
        scanf("%i", &concentracion);
        concentracionesMuestras[i]= concentracion;

    }

    for(int j=0;j<muestras;j++){
        printf("Muestra %i / Tipo: %i / Concentracion: %i\n", j+1, tiposMuestras[j], concentracionesMuestras[j]);
    }
}
void cargaRandom(char tiposMuestras[DIM], char concentracionesMuestras[DIM], int muestras) {
    printf("CARGA ALEATORIA\n");
    int tipo = 0;
    int concentracion = 0;

    srand(time(NULL));

    for(int i=0;i<muestras;i++){
        tipo = rand()%3;
        tiposMuestras[i]= tipo;

        concentracion = rand()%101;
        concentracionesMuestras[i]= concentracion;
    }
    for(int j=0;j<muestras;j++){
        printf("Muestra %i / Tipo: %i / Concentracion: %i\n", j+1, tiposMuestras[j], concentracionesMuestras[j]);
    }
}
//EJ 2:
void clasificaConcentraciones(char tiposMuestras[DIM], char concentracionesMuestras[DIM], int muestras, Pila *pilaSeguras, Pila *pilaCriticas, Pila *pilaTipo1) {

    for(int i = 0; i< muestras;i++){
        if(tiposMuestras[i] == 1){
            int aux = concentracionesMuestras[i];
            apilar(pilaTipo1, aux);
        } else if (concentracionesMuestras[i] >= 30 && concentracionesMuestras[i] <= 60) {
            int aux = concentracionesMuestras[i];
            apilar(pilaSeguras, aux);
        } else {
            int aux = concentracionesMuestras[i];
            apilar(pilaCriticas, aux);
        }
    }

    printf("Pila Tipo 1: \n");
    mostrar(pilaTipo1);
    printf("Pila Seguras: \n");
    mostrar(pilaSeguras);
    printf("Pila Criticas: \n");
    mostrar(pilaCriticas);


}
//EJ 3:
float promedioConcentraciones(char concentracionesMuestras[DIM], int muestras) {
    int suma = 0;
    int aux = 0;
    int cantidad = 0;
    float promedio = 0.00;


    for(int i=0;i<muestras;i++){
        aux = concentracionesMuestras[i];
        suma += aux;
        cantidad++;
    }

    promedio = (float)suma/cantidad;

    return promedio;
}
float porcBajoUmbral(Pila pilaSeguras, int umbral){
    int bajoUmbral = 0;
    int total = 0;
    while(!pilavacia(&pilaSeguras)) {
        int aux = desapilar(&pilaSeguras);
        if(aux < umbral){
            bajoUmbral++;
            total++;

        } else {
            total++;
        }
    }
    float porcentaje = (float)bajoUmbral*100/total;


    return porcentaje;
}
void informaPromPorc(char concentracionesMuestras[DIM], int muestras, Pila pilaSeguras, int umbral) {
    float promedio = promedioConcentraciones(concentracionesMuestras, muestras);
    float porcentaje = porcBajoUmbral(pilaSeguras, umbral);

    printf("El promedio es de %.2f\n", promedio);
    printf("El porcentaje de los que se encuentran por debajo del umbral es de %.2f\n", porcentaje);

}
//EJ 4:
int cargaApeyNom(char matPersonas[APYNOM][CARACTERES]){
    int cantPersonas = 0;
    printf("Cuantas personas quiere cargar? (menor a 30) \n");
    fflush(stdin);
    scanf("%i", &cantPersonas);
    getchar();

    if(cantPersonas <= 30){
            for(int i=0;i<cantPersonas;i++){
                printf("Ingrese el apeliido y nombre en la posición %i", i + 1);
                gets(matPersonas[i]);
                }
            printf("Personas cargadas: \n");
            for(int k=0;k<cantPersonas;k++){
                printf("%d. %s\n", k + 1, matPersonas[k]);
            }
    }
    else {
        printf("Error, la cantidad de personas debe ser menor a 30.\n");

    }

    return cantPersonas;

}
int buscaApe(char matPersonas[APYNOM][CARACTERES], int cantPersonas, int posiciones[cantPersonas]){
    char prefijo[CARACTERES];
    int cantidad = 0;

    printf("Ingrese el prefijo por el cual tienen que comenzar los apellidos: (dos caracteres) \n");
    gets(prefijo);

    printf("EL prefijo es: ");
    puts(prefijo);
    printf("\n");



    for (int i = 0; i < cantPersonas; i++) {
            if (strncasecmp(matPersonas[i], prefijo, strlen(prefijo)) == 0) {
            posiciones[cantidad] = i;
            cantidad ++;
        }
    }

    for(int j=0;j<cantidad;j++){
            printf("Hay conicindecia en las posicion: %i\n", posiciones[j]);
    }

    return cantidad;

}
void cargaBuscados(char matEncontrados[APYNOM][CARACTERES], char matPersonas[APYNOM][CARACTERES], int posiciones[], int cantidad) {
    for(int i = 0;i<cantidad;i++){
        strcpy(matEncontrados[i], matPersonas[posiciones[i]]);
    }

    for(int j=0;j<cantidad;j++){
        printf("Personas copiadas en la matEncontrados: %i %s\n ", posiciones[j], matEncontrados[j]);
    }
}

