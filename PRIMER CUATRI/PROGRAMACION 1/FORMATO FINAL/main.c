#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../pila.h"

typedef struct
{
    int id;
    int codigo;
    int rubro; // 1 – Televisores / 2 – Lavarropas / 3 – Cocinas / 4 - Calefactores
    char marca[30];
    char modelo[30];
    float precio;
} stArticulo;

//EJ 1
stArticulo* arch2Arre(int validos, int rubro,  char archivoArticulos[]);
void cantPorRubro(char archivoArticulos[], int* validosTV, int* validosLav, int* validosCoc, int* validosCalef);
//EJ 2
void muestraArreArti(stArticulo arreglo[], int validos);
void mostrarArticulo(stArticulo articulo);
//EJ 3
int buscarArticuloPorIDRecursivo(stArticulo arreglo[], int validos, int i, int buscado);
//EJ 4
int cantArticulos(char archivoArticulos[]);
//EJ 5
void muestraElArti(char archivoArticulos[], int posicion);
//EJ 6
void clasificaArti(stArticulo arreglo[], int validos, char archivoArticulosEco[], char archivoArticulosCost[], float parametro);

int main()
{
    char archivoArticulos[] = "articulos.bin";
    int validosTV = 0;
    int validosLav= 0;
    int validosCoc= 0;
    int validosCalef= 0;

    cantPorRubro(archivoArticulos, &validosTV, &validosLav, &validosCoc, &validosCalef);

    stArticulo* arregloTV = arch2Arre(validosTV, 1, archivoArticulos);
    stArticulo* arregloLav = arch2Arre(validosLav, 2, archivoArticulos);
    stArticulo* arregloCoc = arch2Arre(validosCoc, 3, archivoArticulos);
    stArticulo* arregloCalef = arch2Arre(validosCalef, 4, archivoArticulos);

    //EJ 3
    int encontrado = buscarArticuloPorIDRecursivo(arregloTV, validosTV, 0, 105);
    if(encontrado)
    {
        printf("Búsqueda exitosa.\n");
    }
    else
    {
        printf("No se encontró el artículo.\n");
    }

    //EJ 4
    cantArticulos(archivoArticulos);

    //EJ 5
    int posicion = 3;
    muestraElArti(archivoArticulos, posicion);

    //EJ 6
     char archivoArticulosEco[] = "articulosEconomicos.bin";
     char archivoArticulosCost[] = "articulosCostosos.bin";
     float parametro = 20.0;

     clasificaArti(arregloTV, validosTV, archivoArticulosEco, archivoArticulosCost, parametro);


    return 0;
}

//EJ 1
stArticulo* arch2Arre(int validos, int rubro,  char archivoArticulos[])
{
    FILE *archi = fopen(archivoArticulos, "rb");
    stArticulo articuloAux;
    int i = 0;

    stArticulo* arreglo = (stArticulo*)malloc(validos*sizeof(stArticulo));

     if(archi!=NULL)
    {
        while(fread(&articuloAux,sizeof(stArticulo),1,archi)>0)
        {
            if(articuloAux.rubro == rubro && i < validos)
            {
                arreglo[i] = articuloAux;
                i++;
            }
        }
        return arreglo;
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }
}


void cantPorRubro(char archivoArticulos[], int* validosTV, int* validosLav, int* validosCoc, int* validosCalef)
{
    FILE *archi = fopen(archivoArticulos, "rb");
    stArticulo articuloAux;

    if(archi!=NULL)
    {
        while(fread(&articuloAux,sizeof(stArticulo),1,archi))
        {
            if(articuloAux.rubro == 1)
            {
                (*validosTV)++;
            }
            else if(articuloAux.rubro == 2)
            {
                (*validosLav)++;
            }
            else if(articuloAux.rubro == 3)
            {
                (*validosCoc)++;
            }
            else
            {
                (*validosCalef)++;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

//EJ 2
void muestraArreArti(stArticulo arreglo[], int validos)
{
    for(int i=0;i<validos;i++)
    {
        mostrarArticulo(arreglo[i]);
    }
}

void mostrarArticulo(stArticulo articulo)
{
    printf("-------------------------\n");
    printf("ID: %i\n", articulo.id);
    printf("Código: %i\n", articulo.codigo);
    printf("Rubro: %i\n", articulo.rubro);
    printf("Marca: %s\n", articulo.marca);
    printf("Modelo: %s\n", articulo.modelo);
    printf("Precio: %.2f\n", articulo.precio);
    printf("-------------------------\n");
}
//EJ 3
int buscarArticuloPorIDRecursivo(stArticulo arreglo[], int validos, int i, int buscado)
{
    if(i == validos)
    {
        printf("Articulo no encontrado.\n");
        return 0;
    }
    if(arreglo[i].id==buscado)
    {
        mostrarArticulo(arreglo[i]);
        return 1;
    }
    else
    {
        return buscarArticuloPorIDRecursivo(arreglo, validos, i+1, buscado);
    }
}
//EJ 4
int cantArticulos(char archivoArticulos[])
{
    FILE* archi=fopen(archivoArticulos, "rb");

    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        long total = ftell(archi)/sizeof(stArticulo);
        printf("La cantidad de ariculos que tiene el archivo es %i\n", total);

        fclose(archi);
        return total;
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }
}
//EJ 5
void muestraElArti(char archivoArticulos[], int posicion)
{
    int totalRegistros = cantArticulos(archivoArticulos);

    if (posicion < 0 || posicion >= totalRegistros)
    {
        printf("Posición ingresada fuera de rango.\n");
        return;
    }

    FILE* archi=fopen(archivoArticulos, "rb");
    stArticulo articuloAux;

    if(archi!=NULL)
    {
        fseek(archi,posicion*sizeof(stArticulo),SEEK_SET);
        fread(&articuloAux,sizeof(stArticulo),1,archi);
        mostrarArticulo(articuloAux);

        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

//EJ 6
void clasificaArti(stArticulo arreglo[], int validos, char archivoArticulosEco[], char archivoArticulosCost[], float parametro)
{
    FILE* archiE=fopen(archivoArticulosEco, "rb");
    FILE* archiC=fopen(archivoArticulosCost, "rb");

    if(archiC != NULL && archiE != NULL)
    {
        for(int i=0;i<validos;i++)
        {
            if(arreglo[i].precio < parametro)
            {
                fwrite(&arreglo[i],sizeof(stArticulo),1,archiE);
            }
            else
            {
                fwrite(&arreglo[i],sizeof(stArticulo),1,archiC);
            }
            fclose(archiC);
            fclose(archiE);
        }
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

void muestraArchi(char archivoArticulos[])
{
    FILE* archi=fopen(archivoArticulos, "rb");
    stArticulo articuloAux;

    if(archi!=NULL)
    {
        while(fread(&articuloAux,sizeof(stArticulo),1,archi)>0)
        {
            mostrarArticulo(articuloAux);
        }
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}


