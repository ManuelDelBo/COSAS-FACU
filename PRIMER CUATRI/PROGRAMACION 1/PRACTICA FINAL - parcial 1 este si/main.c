#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../pila.h"

#include "miLibreria.h"

#define DIMENSION 20

//EJ 1
void cargarDatos(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][15]);
void mostrarLibros(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][15]);
//EJ 2
void clasificarPorGenero(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][15], Pila* policial, Pila* romance, Pila* terror, int *cantPolicial, int *cantRomance, int *cantTerror);
//EJ 3
void muestraInversa(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][15], int valorLimite);
//EJ 4
void generarMatrizRandom(int matrizRandom[10][10]);
void imprimirMatrizRandom (int matrizRandom[10][10]);
//EJ 5
void cantidadesPorCodigo(int codigosISBN[DIMENSION], int matrizRandom[10][10]);
int cantidadApariciones(int numero, int matrizRandom[10][10]);
//EJ 6
void informaPorPal(char misPalabras[10][30], char letra);



int main()
{
    //EJ 1
    int codigosISBN[DIMENSION];
    char generosLibros[DIMENSION][15];

    cargarDatos(codigosISBN, generosLibros);
    mostrarLibros(codigosISBN, generosLibros);

    //EJ 2
    Pila policial, romance, terror;
    inicpila(&policial);
    inicpila(&romance);
    inicpila(&terror);
    int cantPolicial = 0;
    int cantRomance = 0;
    int cantTerror = 0;

    clasificarPorGenero(codigosISBN, generosLibros, &policial, &romance, &terror, &cantPolicial, &cantRomance, &cantTerror);

    //EJ 3
    burbujeo(codigosISBN, DIMENSION);
    burbujeo(generosLibros, DIMENSION);
    int valorLimite= 0;
    printf("Ingrese el valor limite (menor a 20)\n");
    scanf("%i", &valorLimite);

    if (valorLimite > 20) {
        valorLimite = 20;
    }
    muestraInversa(codigosISBN, generosLibros, valorLimite);

    //EJ 4
    int matrizRandom[10][10];

    generarMatrizRandom(matrizRandom);
    imprimirMatrizRandom(matrizRandom);

    //EJ 5
    cantidadesPorCodigo(codigosISBN, matrizRandom);

    //EJ 6
    char misPalabras[10][30] = {"Jorge", "Ulises", "Mario", "Nerea", "Carlos", "Cristian", "Gisela", "Norma", "Gladys", "Sofia"};
    char letra;
    printf("Ingrese una letra:\n");
    scanf(" %c", &letra);

    informaPorPal(misPalabras, letra);

    return 0;
}

//EJ 1
void cargarDatos(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][15])
{
    int genero = 0;
    srand(time(NULL));
    for(int i=0;i<DIMENSION;i++)
    {
        int aux = rand()%100+1;
        codigosISBN[i] = aux;
    }

    for(int j=0;j<DIMENSION;j++)
    {
        printf("Para el libro en la posicion %i, que genero desea seleccionar? 1 Policial, 2 Romance, 3 Terror", j);
        scanf("%i", &genero);
        if(genero == 1)
        {
            strcpy(generosLibros[j], "Policial");
        }
        else if(genero == 2)
        {
            strcpy(generosLibros[j], "Romance");
        }
        else if(genero == 3)
        {
            strcpy(generosLibros[j], "Terror");
        }
        else
        {
            printf("Ingreso fuera de rango, vuelva a ingresarlo.\n");
            j--;
        }
    }
}

void mostrarLibros(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][15])
{
    for(int i=0;i<DIMENSION;i++)
    {
        printf("---------------------\n");
        printf("Codigo ISBN: %i\n", codigosISBN[i]);
        printf("Genero: %s\n", generosLibros[i]);
    }
}

//EJ 2
void clasificarPorGenero(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][15], Pila* policial, Pila* romance, Pila* terror, int *cantPolicial, int *cantRomance, int *cantTerror)
{
    for(int i=0;i<DIMENSION;i++)
    {
        if(strcmp(generosLibros[i], "Policial") == 0)
        {
            apilar(policial, codigosISBN[i]);
            (*cantPolicial)++;
        }
        if(strcmp(generosLibros[i], "Romance") == 0)
        {
            apilar(romance, codigosISBN[i]);
            (*cantRomance)++;
        }
        if(strcmp(generosLibros[i], "Terror") == 0)
        {
            apilar(terror, codigosISBN[i]);
            (*cantTerror)++;
        }
    }

    printf("La cantidad de libros policiales es %i\n", *cantPolicial);
    mostrar(policial);

    printf("La cantidad de libros de romance es %i\n", *cantRomance);
    mostrar(romance);

    printf("La cantidad de libros de terror es %i\n", *cantTerror);
    mostrar(terror);
}

//EJ 3
void muestraInversa(int codigosISBN[DIMENSION], char generosLibros[DIMENSION][15], int valorLimite)
{
    printf("MUESTRA INVERSA\n");
    for(int i=DIMENSION-1;i>=valorLimite;i--)
    {
        printf("---------------------\n");
        printf("Codigo ISBN: %i\n", codigosISBN[i]);
        printf("Genero: %s\n", generosLibros[i]);
    }
}

//EJ 4
void generarMatrizRandom(int matrizRandom[10][10])
{
    srand(time(NULL));
    for(int i = 0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            matrizRandom[i][j] = rand()%101;
        }
    }
}

void imprimirMatrizRandom (int matrizRandom[10][10])
{
    srand(time(NULL));
    for(int i = 0;i<10;i++)
    {
        printf("{");
        for(int j=0;j<10;j++)
        {
            printf("%i, ",  matrizRandom[i][j]);
        }
        printf("}\n");
    }
}


//EJ 5
void cantidadesPorCodigo(int codigosISBN[DIMENSION], int matrizRandom[10][10])
{
    for(int i=0;i<DIMENSION;i++)
    {
        int cant = cantidadApariciones(codigosISBN[i], matrizRandom);
        printf("El codigo %i aparece %i veces.\n", codigosISBN[i], cant);

    }
}

int cantidadApariciones(int numero, int matrizRandom[10][10])
{
    int coincidencias = 0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(numero == matrizRandom[i][j])
            {
                coincidencias++;
            }
        }
    }
    return coincidencias;

}

//EJ 6

void informaPorPal(char misPalabras[10][30], char letra)
{
    tolower(letra);
    int cantidad = 0;

    for(int i=0;i<10;i++)
    {
       int largo = strlen(misPalabras[i]);
       char primer = tolower(misPalabras[i][0]);
       char ultima = tolower(misPalabras[i][largo-1]);

       if(primer == letra || ultima == letra)
       {
           printf("La palabra en la posiciòn %i contiente la letra %c : %s\n", i, letra, misPalabras[i]);
           cantidad++;
       }
    }
    return cantidad;
}

