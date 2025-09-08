//Manuel Ignacio Del Bo - Com 14

#include <stdio.h>
#include <stdlib.h>
#include "../../pila.h"
#include "../../miLibreria.h"
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define DIMENSION 20
#define MAXCARACTERES 9
#define FILAS 10
#define COLUMNAS 10

//EJ 1:
void cargarDatos(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][MAXCARACTERES]);
//EJ 2:
void clasificarPorGenero(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][MAXCARACTERES], Pila *pilaPolicial, Pila *pilaRomace, Pila *pilaTerror, int *cantPolicial, int *cantRomance, int *cantTerror);
//EJ 3:
void muestraInversa(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][MAXCARACTERES], int validosISBN);
//EJ 4
void generaMatrizRandom(int matrizRandom[FILAS][COLUMNAS]);
void imprimirMatrizRandom(int matrizRandom[FILAS][COLUMNAS]);
//EJ 5:
void cantidadesPorCodigo(int codigosISBN[DIMENSION], int validosISBN);
int cantidadApariciones(int codigosISBN[DIMENSION], int validosISBN, int posicion);
//EJ 6:
void informaPorPal(char misPalabras[FILAS][COLUMNAS]);

int main()
{
    //EJ 1:
    int codigosISBN[DIMENSION];
    char generosLibros[DIMENSION][MAXCARACTERES];
    int validosISBN = 20;


    cargarDatos(codigosISBN, generosLibros);

    //EJ 2:
    Pila pilaPolicial, pilaRomace, pilaTerror;
    inicpila(&pilaPolicial);
    inicpila(&pilaRomace);
    inicpila(&pilaTerror);

    int *cantPolicial = 0;
    int *cantRomance = 0;
    int *cantTerror = 0;


    clasificarPorGenero(codigosISBN, generosLibros, &pilaPolicial, &pilaRomace, &pilaTerror, cantPolicial, cantRomance, cantTerror);

    //EJ 3:
    burbujeo(codigosISBN, validosISBN);
    burbujeo(generosLibros, validosISBN);
    muestraInversa(codigosISBN, generosLibros, validosISBN);

    //EJ 4:
    int matrizRandom[FILAS][COLUMNAS];

    generaMatrizRandom(matrizRandom);
    imprimirMatrizRandom(matrizRandom);

    //EJ 5:
    cantidadesPorCodigo(codigosISBN, validosISBN);

    //EJ 6:

    char misPalabras[FILAS][COLUMNAS] = {"Juan", "Nicolas", "Juan", "Nicolas", "Juan", "Nicolas", "Juan", "Nauj", "Juan", "Nauj"};


    return 0;
}

//EJ 1:
void cargarDatos(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][MAXCARACTERES]){
    printf("CARGA AUTOMATICA DE DATOS EN codigosISBN: \n");
    srand(time(NULL));

    for(int i=0;i<DIMENSION;i++){
        int aux = rand()%100+1;
        codigosISBN[i] = aux;
    }



    for(int j=0;j<DIMENSION;j++){
        int codigo = 0;

        printf("Ingrese el codigo para seleccionar el genero: 1 para Policial, 2 para Romance, 3 para Terror: \n");
        scanf("%i", &codigo);
        getchar();

        if(codigo == 1){
                generosLibros[j][MAXCARACTERES] = "Policial";
        } else if (codigo == 2) {
            generosLibros[j][MAXCARACTERES] = "Romance";

        } else if (codigo == 3){
            generosLibros[j][MAXCARACTERES] = "Terror";
        } else{
            printf("Valor incorrecto\n");
            break;
        }

    }

    printf("CODIGOS Y GENEROS: \n");
    for(int k = 0;k<DIMENSION;k++){
        printf("%i - Codigo %i - Genero %s\n", k+1, codigosISBN[k], generosLibros[k]);
    }


}
//EJ 2:
void clasificarPorGenero(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][MAXCARACTERES], Pila *pilaPolicial, Pila *pilaRomace, Pila *pilaTerror, int *cantPolicial, int *cantRomance, int *cantTerror){
    for(int i=0;i<DIMENSION;i++){
        int codigo = codigosISBN[i];
        if(generosLibros[i] == "Policial"){
            apilar(&pilaPolicial, codigo);
            *cantPolicial++;
        } else if(generosLibros[i] == "Romance") {
            apilar(&pilaRomace, codigo);
            *cantRomance++;
        } else if(generosLibros[i] == "Terror") {
            apilar(&pilaTerror, codigo);
            *cantTerror++;
        }
    }

    printf("PILA POLICIAL\n");
    mostrar(pilaPolicial);
    printf("PILA ROMANCE\n");
    mostrar(pilaRomace);
    printf("PILA TERROR\n");
    mostrar(pilaTerror);

}
//EJ 3:
void muestraInversa(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][MAXCARACTERES], int validosISBN){
    int valorLimite = 40;

    for(int j=validosISBN;j>=valorLimite;j--){
        if(codigosISBN[j] != valorLimite){
            printf("No es el valor buscado: Codigo %i, Genero %s\n", codigosISBN[j], generosLibros[j]);
        }else if(codigosISBN[j] == valorLimite){
            printf("VALOR LIMITE ENCONTRADO %i, Genero %s\n", codigosISBN[j], generosLibros[j]);
        }
    }
}
//EJ 4
void generaMatrizRandom(int matrizRandom[FILAS][COLUMNAS]){
    printf("Carga aleatora de Matriz \n");
    srand(time(NULL));

    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            matrizRandom[i][j] = rand()%100+1;
        }
    }
}
void imprimirMatrizRandom(int matrizRandom[FILAS][COLUMNAS]){
    for(int i=0;i<FILAS;i++){
        printf("{");
        for(int j=0;j<COLUMNAS;j++){
            printf("%i ,", matrizRandom[i][j]);
        }
        printf("}\n");
    }
}
//EJ 5
void cantidadesPorCodigo(int codigosISBN[DIMENSION], int validosISBN){
    int posicion = 0;

    for(int i = 0;i<validosISBN;i++){
        int resultado = cantidadApariciones(codigosISBN, validosISBN,posicion);
        posicion++;
        printf("El codigo %i aparece %i veces:\n", codigosISBN[posicion], resultado);
    }



}

int cantidadApariciones(int codigosISBN[DIMENSION], int validosISBN, int posicion){
    int coincidencia = 0;
    int buscado = codigosISBN[posicion];

    for(int i = 0;i<validosISBN;i++){
        if(buscado = codigosISBN[i]){
            coincidencia++;
        }
    }

    return coincidencia;
}
//EJ 6:

void informaPorPal(char misPalabras[FILAS][COLUMNAS]){
    char letra;
    printf("Ingrese la letra que quiere buscar: \n");
    scanf(" %c", &letra);
    getchar();

    printf("La letra ingresada es %i", letra);

    for(int i=0;i<FILAS;i++){
        int *ptr = strcmp(misPalabras, letra);
        if( ptr != NULL && ptr == misPalabras[i][0]){
        printf("La palabra %s contiene letra %c en el primer caracter\n", misPalabras[i][i], letra);
        }
    }
}


