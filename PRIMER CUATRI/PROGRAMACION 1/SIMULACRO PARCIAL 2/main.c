#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDAD 7

typedef struct
{
    int idViaje;
    char origen[50];
    char destino[50];
    int cantidadPasajeros;
} Viaje;

typedef struct
{
    int idPasajero;
    int idViaje;
    char nombre[50];
    char dni[10];
    int despacheEquipaje;
} Pasajero;


//PROTOTIPADO
//EJ 1
int contarRegistrosArchivo( char nombrArchivo[], int tamanioRegistro);
//EJ 2
void cargarArregloPasajeros(char nombrArchivoPasajeros[], int validosPasajeros,  Pasajero* arregloPasajeros);
void mostrarPasajero(int validosPasajeros,  Pasajero* arregloPasajeros);
//EJ 3
int contarPasajerosPorViaje(Pasajero* arregloPasajeros, int idViaje, int validosPasajeros);



int main()
{
    char nombrArchivoViajes[] = "viajes.bin";
    char nombrArchivoPasajeros[] = "pasajeros.bin";

    //EJ 1
    int validosViajes = contarRegistrosArchivo(nombrArchivoViajes, sizeof(Viaje));
    int validosPasajeros = contarRegistrosArchivo(nombrArchivoPasajeros, sizeof(Pasajero));

    //EJ 2:
    Pasajero* arregloPasajeros = (Pasajero*)malloc(validosPasajeros*sizeof(Pasajero));

    cargarArregloPasajeros(nombrArchivoPasajeros, validosPasajeros, arregloPasajeros);
    mostrarPasajero(validosPasajeros, arregloPasajeros);

    //EJ 3
    contarPasajerosPorViaje(arregloPasajeros, idViaje, validosPasajeros);

    return 0;
}


int contarRegistrosArchivo( char nombrArchivo[], int tamanioRegistro)
{
    FILE *archi=fopen(nombrArchivo, "rb");

    int cant = 0;

    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        cant = ftell(archi)/tamanioRegistro;

        fclose(archi);
        printf("La cantidad de registros que tiene el archivo es de %i\n", cant);
        return cant;
    }
    else
    {
        printf("No se pudo abrir el archivo;\n");
        return 0;
    }

}

//EJ 2
void cargarArregloPasajeros(char nombrArchivoPasajeros[], int validosPasajeros,  Pasajero* arregloPasajeros)
{
    FILE *archi=fopen(nombrArchivoPasajeros, "rb");

    Pasajero pasajeroAux;
    int i = 0;

    if(archi!=NULL)
    {
        while(fread(&pasajeroAux,sizeof(pasajeroAux),1,archi)>0)
        {
            arregloPasajeros[i] = pasajeroAux;
            i++;
        }

        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo;\n");
        return 0;
    }
}

void mostrarPasajero(int validosPasajeros,  Pasajero* arregloPasajeros)
{
    int idAux = 0;
    printf("Ingrese el ID del pasajero que desea buscar: \n");
    scanf("%i", &idAux);

    int encontrado = 0;

    for(int i=0;i<validosPasajeros;i++)
    {
        if(arregloPasajeros[i].idPasajero == idAux)
        {
            printf("\n\nPASAJERO ENCONTRADO: \n\n");
            printf("ID: %i\n", arregloPasajeros[i].idPasajero);
            printf("VIAJE: %i\n", arregloPasajeros[i].idViaje);
            getchar();
            printf("NOMBRE: \n");
            puts(arregloPasajeros[i].nombre);
            printf("DNI: \n");
            puts(arregloPasajeros[i].dni);
            printf("EQUIPAJE: %i\n", arregloPasajeros[i].despacheEquipaje);

            encontrado = 1;
        }
    }
    if(encontrado==0)
    {
        printf("EL pasajero ID %i no se ha encontrado.\n", idAux);
    }
}

//EJ 3
int contarPasajerosPorViaje(Pasajero* arregloPasajeros, int idViaje, int validosPasajeros)
{
    int contador = 0;
    for(int i =0;i<validosPasajeros;i++)
    {
        if(arregloPasajeros[i].idViaje == idViaje)
            contador++;
    }

    printf("La cantidad de pasajeros del viaje %i es %i", idViaje, contador);
    return contador;
}


//EJ 4
