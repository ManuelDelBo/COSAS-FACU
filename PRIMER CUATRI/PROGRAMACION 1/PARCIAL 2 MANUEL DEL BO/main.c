#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int idPiloto;
char apellido[30];
char equipo[30];
float estatura;
float peso;
int tieneAuto; //1 o 0
} Piloto;

typedef struct
{
int idAuto;
int idPiloto;
char equipo[30];
int velocidadMaxima;
double tiempo0a100;
float peso;
} Auto;

///PROTOTIPADO

//EJ 1:
int autosSinPiloto(char nombreArchivoAutos[]);
void cargarArregloAutos(char nombreArchivoAutos[], int validosAutos, Auto* arregloAutos);
//EJ 2:
void cargarArregloPilotos(char nombreArchivoPilotos[], int validosPilotos, Piloto* arregloPilotos);
int pilotoSinAuto(char nombreArchivoPilotos[]);
//EJ 3:
int menorTiempo0a100(Auto* arregloAutos, int validosAutos);
//EJ 4:
Auto asignarPiloto(Piloto* arregloPilotos, int validosPilotos, Auto* arregloAutos, int validosAutos, int idAutoBuscado);
//EJ 5:
void modificarAutoEnArchivo(char nombreArchivoAutos[], Auto autoModificado);
//EJ 6:
float calcularVelocidadPromedio(Auto* arregloAutos, int validosAutos, int sumatoria, int i);
//EJ 7:
void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char archivoDebajoPromedio[], Auto* arregloAutos, int validosAutos, float promedio);



int main()
{
    //EJ 1:
    char nombreArchivoAutos[] = "autos.bin";
    int validosAutos = autosSinPiloto(nombreArchivoAutos);

    Auto* arregloAutos = (Auto*)malloc(validosAutos*sizeof(Auto));

    cargarArregloAutos(nombreArchivoAutos, validosAutos, arregloAutos);

    //EJ 2:
    char nombreArchivoPilotos[] = "pilotos.bin";
    int validosPilotos = pilotoSinAuto(nombreArchivoPilotos);

    Piloto* arregloPilotos = (Piloto*)malloc(validosPilotos*sizeof(Piloto));

    cargarArregloPilotos(nombreArchivoPilotos, validosPilotos, arregloPilotos);

    //EJ 3
    int idAutoBuscado = menorTiempo0a100(arregloAutos, validosAutos);

    //EJ 4
    Auto autoModificado = asignarPiloto(arregloPilotos, validosPilotos, arregloAutos, validosAutos, idAutoBuscado);

    //EJ 5
    modificarAutoEnArchivo(nombreArchivoAutos, autoModificado);

    //EJ 6:
    float promedio = calcularVelocidadPromedio(arregloAutos, validosAutos, 0, 0);

    //EJ 7:
    char archivoSobrePromedio[] = "sobrePromedio.bin";
    char archivoDebajoPromedio[] = "debajoPromedio.bin";

    escribirArchivosPorVelocidad(archivoSobrePromedio, archivoDebajoPromedio, arregloAutos, validosAutos, promedio);









    return 0;
}

///1. Pasar a un arreglo dinámico de tamaño justo todos los autos sin piloto asignado
///(idPiloto==-1) y mostrarlo por pantalla. Modularizar el cálculo de la dimensión.
///Auto* cargarArregloAutos(char nombreArchivo[], int dimension)

int autosSinPiloto(char nombreArchivoAutos[])
{
    FILE *archi = fopen(nombreArchivoAutos, "rb");

    Auto auxAuto;
    int contador = 0;

    if(archi!=NULL)
    {
        while(fread(&auxAuto,sizeof(Auto),1,archi)>0)
        {
            if(auxAuto.idPiloto == -1)
            {
                contador++;
            }
        }
        fclose(archi);
        return contador;
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }
}

void cargarArregloAutos(char nombreArchivoAutos[], int validosAutos, Auto* arregloAutos)
{
  FILE *archi = fopen(nombreArchivoAutos, "rb");

    Auto auxAuto;
    int i = 0;

    if(archi!=NULL)
    {
        while(fread(&auxAuto,sizeof(Auto),1,archi)>0)
        {
            if(auxAuto.idPiloto == -1)
            {
                arregloAutos[i] = auxAuto;
                i++;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

///2. Pasar a un arreglo dinámico todos los pilotos sin auto asignado y mostrarlo por
///pantalla. El arreglo debe redimensionarse cuando sea necesario. De no poder
///resolver el ejercicio usando realloc, se podrá crear un arreglo de tamaño justo, pero
///el ejercicio tendrá la mitad del puntaje.
///Piloto* cargarArregloPilotos(char nombreArchivo[], int* validos)

void cargarArregloPilotos(char nombreArchivoPilotos[], int validosPilotos, Piloto* arregloPilotos)
{
    FILE *archi = fopen(nombreArchivoPilotos, "rb");

    Piloto auxPiloto;
    int i = 0;

    if(archi!=NULL)
    {
        while(fread(&auxPiloto,sizeof(Piloto),1,archi)>0)
        {
            if(auxPiloto.tieneAuto == -1)
            {
                arregloPilotos[i] = auxPiloto;
                i++;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

int pilotoSinAuto(char nombreArchivoPilotos[])
{
    FILE *archi = fopen(nombreArchivoPilotos, "rb");

    Piloto auxPiloto;
    int contador = 0;

    if(archi!=NULL)
    {
        while(fread(&auxPiloto,sizeof(Piloto),1,archi)>0)
        {
            if(auxPiloto.tieneAuto == -1)
            {
                contador++;
            }
        }
        fclose(archi);
        return contador;
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }
}

///3. Buscar el ID del auto con menor tiempo 0 a 100 en el arreglo y retornarlo.
///int menorTiempo0a100(Auto* arreglo, int dimension)


int menorTiempo0a100(Auto* arregloAutos, int validosAutos)
{
    int menorTiempo = arregloAutos[0].tiempo0a100;
    int idMenor = 0;

    for(int i=1;i<validosAutos;i++)
    {
        if(arregloAutos[i].tiempo0a100<menorTiempo)
        {
            menorTiempo = arregloAutos[i].tiempo0a100;
            idMenor = arregloAutos[i].idAuto;
        }
    }
    printf("El auto con el menor tiempo 0 a 100 es el ID %i", arregloAutos[idMenor].idAuto);
    return idMenor;
}

///4. Asignar un piloto al auto obtenido en el ejercicio anterior. Tanto el auto como el
///piloto deben pertenecer al mismo equipo.
///Auto asignarPiloto(Piloto* arrPilotos, int dimPilotos, Auto* arrAutos, int dimAutos, int idAutoBuscado)


Auto asignarPiloto(Piloto* arregloPilotos, int validosPilotos, Auto* arregloAutos, int validosAutos, int idAutoBuscado)
{
    for(int i=0;i<validosPilotos;i++)
    {
        if(arregloPilotos[i].equipo == arregloAutos[idAutoBuscado].equipo)
        {
            arregloAutos[idAutoBuscado].idPiloto == arregloPilotos[i].idPiloto;
            break;
        }
    }

    Auto auxAuto = arregloAutos[idAutoBuscado];
    return auxAuto;
}

///5. Modificar el registro del auto del punto anterior en el archivo.
///void modificarAutoEnArchivo(char nombreArchivo[], Auto autoModificado)


void modificarAutoEnArchivo(char nombreArchivoAutos[], Auto autoModificado)
{
    FILE *archi=fopen(nombreArchivoAutos, "r+b");

    Auto auxAuto;
    int contador=0;

    if(archi!=NULL)
    {
        while(fread(&auxAuto,sizeof(Auto),1,archi))
        {
            if(auxAuto.idAuto != autoModificado.idAuto)
            {
                contador++;
            }
            else
            {
                break;
            }
        }
        fseek(archi,(contador-1)*sizeof(Auto),SEEK_SET);
        fwrite(&autoModificado,sizeof(Auto),1,archi);

        fclose(archi);
    }
    else
    {
        printf("No se pudieron abrir los archivos.\n");
    }
}


///6. Hacer una función recursiva que calcule la velocidad promedio del arreglo de
///autos (campo velocidadMaxima).
///float calcularVelocidadPromedio(Auto* arreglo, int dimension, int sumatoria, int i)

float calcularVelocidadPromedio(Auto* arregloAutos, int validosAutos, int sumatoria, int i)
{
    if(i == validosAutos)
    {
        return arregloAutos[i].velocidadMaxima;
    }
    else
    {

        sumatoria += arregloAutos[i].velocidadMaxima + calcularVelocidadPromedio(arregloAutos,validosAutos,sumatoria,i+1);
    }
    if(i==0)
    {
        return (float)sumatoria/validosAutos;
    }
    else
    {
        return sumatoria;
    }

}

/// 7. Pasar los autos del arreglo a dos archivos según el resultado de la función
///anterior (velocidad mayor al promedio y menor al promedio).
///void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char archivoDebajoPromedio[], Auto* arreglo, int dimension, float promedio)

void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char archivoDebajoPromedio[], Auto* arregloAutos, int validosAutos, float promedio)
{
    FILE *archiSobre=fopen(archivoSobrePromedio, "wb");
    FILE *archiDebajo=fopen(archivoDebajoPromedio, "wb");

    if(archiSobre !=NULL && archiDebajo != NULL)
    {
        for(int i=0;i<validosAutos;i++)
        {
            if(arregloAutos[i].velocidadMaxima<promedio)
            {
                fwrite(&arregloAutos[i],sizeof(Auto),1,archiDebajo);
            }
            else
            {
                fwrite(&arregloAutos[i],sizeof(Auto),1,archiSobre);
            }
        }
       fclose(archiDebajo);
       fclose(archiSobre);
    }
    else
    {
        printf("No se pudieron abrir los archivos.\n");
    }
}



