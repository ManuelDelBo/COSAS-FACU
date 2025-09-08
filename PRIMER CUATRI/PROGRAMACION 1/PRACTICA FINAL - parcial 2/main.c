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
//EJ 1
Auto* cargarArregloAutos(char nombreArchivo[], int dimension);
int calculoDimension(char nombreArchivo[]);
void mostrarAuto(Auto autoAux);
//EJ 2
Piloto* cargarArregloPilotos(char nombreArchivoPilotos[], int* validos);
void mostrarPiloto(Piloto auxPiloto);
//EJ 3
int menorTiempo0a100(Auto* arreglo, int dimension);
//EJ 4
Auto asignarPiloto(Piloto* arregloPilotos, int validos, Auto* arregloAutos, int dimension, int autoMenorTiempo0a100);
//EJ 5
void modificarAutoEnArchivo(char nombreArchivo[], Auto autoConPilotoModificado);
//EJ 6
float calcularVelocidadPromedio(Auto* arregloAutos, int dimension, int sumatoria, int i);
//EJ 7
void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char archivoDebajoPromedio[], Auto* arregloAutos, int dimension, float promedio)


int main()
{
    //EJ 1
    char nombreArchivo[] = "autos.bin";
    int dimension = calculoDimension(nombreArchivo);


    Auto* arregloAutos = cargarArregloAutos(nombreArchivo, dimension);

    //EJ 2
    char nombreArchivoPilotos[] = "pilotos.bin";
    int validos = 0;
    Piloto* arregloPilotos = cargarArregloPilotos(nombreArchivoPilotos, &validos);

    //EJ 3
    int autoMenorTiempo0a100 = menorTiempo0a100(arregloAutos, dimension);

    //EJ 4
    Auto autoConPilotoModificado = asignarPiloto(arregloPilotos,validos,arregloAutos,dimension,autoMenorTiempo0a100);

    //EJ 5
    modificarAutoEnArchivo(nombreArchivo, autoConPilotoModificado);

    //EJ 6
    float promedio = calcularVelocidadPromedio(arregloAutos, dimension, 0, 0);
    printf("La sumatoria es: %.2f", promedio);

    //EJ 7
    char archivoSobrePromedio[] = "sobrePromedio.bin";
    char archivoDebajoPromedio[] = "bajoPromedio.bin";

    escribirArchivosPorVelocidad(archivoSobrePromedio, archivoDebajoPromedio, arregloAutos, dimension, promedio);







    return 0;
}

//EJ 1
Auto* cargarArregloAutos(char nombreArchivo[], int dimension)
{
    FILE *archi = fopen(nombreArchivo, "rb");
    Auto* arregloAutosAux = (Auto*)malloc(dimension*sizeof(Auto));
    Auto autoAux;
    int i = 0;

    if(archi!=NULL)
    {
        while(fread(&autoAux,sizeof(Auto),1,archi)>0)
        {
            if(autoAux.idPiloto == -1)
            {
                arregloAutosAux[i] = autoAux;
                mostrarAuto(arregloAutosAux[i]);
                i++;
            }
        }

        fclose(archi);
        return arregloAutosAux;
    }
    else
    {
        printf("No se pudo abrir el archivo");
        return NULL;
    }


}

int calculoDimension(char nombreArchivo[])
{
    FILE *archi = fopen(nombreArchivo, "rb");
    Auto autoAux;
    int dimension = 0;

    if(archi!=NULL)
    {
        while(fread(&autoAux,sizeof(Auto),1,archi)>0)
        {
            if(autoAux.idPiloto == -1)
            {
                dimension++;
            }
        }

        fclose(archi);
        return dimension;
    }
    else
    {
        printf("No se pudo abrir el archivo");
        return NULL;
    }


}

void mostrarAuto(Auto autoAux)
{
    printf("---------------------\n");
    printf("AUTO ID: %i\n\n", autoAux.idAuto);
    printf("ID Piloto: %i\n", autoAux.idPiloto);
    printf("Equipo:");
    puts(autoAux.equipo);
    printf("Velocidad maxima: %i\n", autoAux.velocidadMaxima);
    printf("Tiempo de 0 a 100: %.2f\n", autoAux.tiempo0a100);
}

//EJ 2

Piloto* cargarArregloPilotos(char nombreArchivoPilotos[], int* validos)
{
    FILE *archi = fopen(nombreArchivoPilotos, "rb");

    int incremento = 2;
    *validos = 0;
    Piloto* arregloPilotosAux = (Piloto*)malloc(incremento*sizeof(Piloto));
    Piloto auxPiloto;


    if(archi!=NULL)
    {
        while(fread(&auxPiloto,sizeof(Piloto),1,archi)>0)
        {
            if(auxPiloto.tieneAuto == -1)
            {
                if (*validos >= incremento)
                {
                    incremento*=2;
                    Piloto* temp = (Piloto*)realloc(arregloPilotosAux, sizeof(Piloto)*incremento);
                    if (temp == NULL)
                    {
                        printf("Error al realocar memoria.\n");
                        free(arregloPilotosAux);
                        fclose(archi);
                        return NULL;
                    }
                    arregloPilotosAux = temp;
                }
                arregloPilotosAux[*validos] = auxPiloto;
                mostrarPiloto(arregloPilotosAux[*validos]);
                (*validos)++;
            }
        }
        fclose(archi);
        return arregloPilotosAux;
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

}
void mostrarPiloto(Piloto auxPiloto)
{
    printf("---------------------\n");
    printf("PILOTO ID: %i\n\n", auxPiloto.idPiloto);
    printf("Apellido: \n");
    puts(auxPiloto.apellido);
    printf("Equipo:");
    puts(auxPiloto.equipo);
    printf("Estatura: %f\n", auxPiloto.estatura);
    printf("Peso: %f\n", auxPiloto.peso);
    printf("Tiene auto: %i\n\n", auxPiloto.tieneAuto);
}

//EJ 3
int menorTiempo0a100(Auto* arreglo, int dimension)
{
    int IDautoMenorTiempo = arreglo[0].idAuto;
    double menorTiempo = arreglo[0].tiempo0a100;

    for(int i = 1;i<dimension;i++)
        {
            if(menorTiempo > arreglo[i].tiempo0a100)
            {
                menorTiempo = arreglo[i].tiempo0a100;
                IDautoMenorTiempo = arreglo[i].idAuto;
            }
        }
        printf("MENOR TIEMPO ID: %i\n", IDautoMenorTiempo);
        return IDautoMenorTiempo;
}

//EJ 4
Auto asignarPiloto(Piloto* arregloPilotos, int validos, Auto* arregloAutos, int dimension, int autoMenorTiempo0a100)
{
    char equipoAutoRapido[30];
    int posicionAuto = 0;

    for(int i = 0;i<dimension;i++)
    {
        if(arregloAutos[i].idAuto == autoMenorTiempo0a100)
        {
            strcpy(equipoAutoRapido, arregloAutos[i].equipo);
            posicionAuto = i;
        }
    }
    printf("Equipo auto mas rapido: \n");
    puts(equipoAutoRapido);
    for(int j = 0;j<validos;j++)
    {
        if(strcmp(arregloPilotos[j].equipo, equipoAutoRapido) == 0)
        {
            arregloAutos[posicionAuto].idPiloto = arregloPilotos[j].idPiloto; printf("Piloto ID %d asignado al auto ID %d\n", arregloPilotos[j].idPiloto, arregloAutos[posicionAuto].idAuto);
            return arregloAutos[posicionAuto];
        }
    }

    if(arregloAutos[posicionAuto].idPiloto == -1)
    {
        printf("No se encontró piloto para el auto ID %d\n", autoMenorTiempo0a100);
        return arregloAutos[posicionAuto];
    }

}
//EJ 5
void modificarAutoEnArchivo(char nombreArchivo[], Auto autoConPilotoModificado)
{
    FILE *archi = fopen(nombreArchivo, "r+b");
    Auto autoAux;
    int contador = 0;

    if(archi!=NULL)
    {
        while(fread(&autoAux,sizeof(Auto),1,archi)>0)
        {
            if(autoAux.idAuto != autoConPilotoModificado.idAuto)
            {
                contador++;
            }
            else
            {
                break;
            }
        }
        fseek(archi,sizeof(Auto)*contador-1,SEEK_SET);
        fwrite(&autoConPilotoModificado,sizeof(Auto),1,archi);

        printf("Auto modificado cargado en el archivo.\n");
        mostrarAuto(autoConPilotoModificado);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

float calcularVelocidadPromedio(Auto* arregloAutos, int dimension, int sumatoria, int i)
{
    if(i==dimension)
    {
        return arregloAutos[i].velocidadMaxima;
    }
    else
    {
        sumatoria += arregloAutos[i].velocidadMaxima + calcularVelocidadPromedio(arregloAutos, dimension, sumatoria, i+1);
    }
    if(i==0)
    {
        float resultado = (float)sumatoria/dimension;
        return resultado;
    }
    else
    {
        return sumatoria;
    }
}

//EJ 7
void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char archivoDebajoPromedio[], Auto* arregloAutos, int dimension, float promedio)
{
    FILE *archiS = fopen(archivoSobrePromedio, "wb");
    FILE *archiD = fopen(archivoDebajoPromedio, "wb");

    if(archiS != NULL && archiD != NULL)
    {
        for(int i = 0;i<dimension;i++)
        {
            if(arregloAutos[i].velocidadMaxima < promedio)
            {
                fwrite(&arregloAutos[i],sizeof(Auto),1,archiD);
            }
            else
            {
                fwrite(&arregloAutos[i],sizeof(Auto),1,archiS);
            }
        }
        fclose(archiD);
        fclose(archiS);
    }
    else
    {
        printf("No se pudieron abrir los archivos.\n");
    }
}











