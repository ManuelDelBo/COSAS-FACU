#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include "../pila.h"
#include <time.h>
#include <ctype.h>

#define MAX 10

//EJ 1
void cargarArreglosAutomatico(int tiposMuestras[MAX], int concentracionesMuestras[MAX], int DIM);
void mostrarArreglos(int tiposMuestras[MAX], int concentracionesMuestras[MAX], int DIM);
void cargarArreglosManual(int tiposMuestras[MAX], int concentracionesMuestras[MAX], int DIM);
//EJ 2
void clasificaConcentraciones(int tiposMuestras[MAX], int concentracionesMuestras[MAX], int DIM, Pila* pilaSeguras, Pila* pilaCriticas, Pila* pilaTipo1);
//EJ 3
float promedioConcentraciones (int concentracionesMuestras[MAX], int DIM);
float porcBajoUmbral(Pila* pilaSeguras, Pila* aux, int umbral);
void informaPromPorc(int concentracionesMuestras[MAX], int DIM, Pila* pilaSeguras, Pila* aux, int umbral);
//EJ 4;
int cargaApeyNom(char matPersonas[30][40]);

int main()
{
    int tiposMuestras[MAX];
    int concentracionesMuestras[MAX];
    int DIM = MAX;

    //EJ 1
    int rta = 0;
    printf("Cargar arreglo manualmente (ingrese 1) o automaticamente (ingrese 2)? \n");
    scanf("%i", &rta);

    if(rta == 1)
    {
        cargarArreglosManual(tiposMuestras, concentracionesMuestras, DIM);
    }
    else
    {
        cargarArreglosAutomatico(tiposMuestras, concentracionesMuestras, DIM);
    }
    mostrarArreglos(tiposMuestras, concentracionesMuestras, DIM);

    //EJ 2

    Pila pilaSeguras, pilaCriticas, pilaTipo1;
    inicpila(&pilaSeguras);
    inicpila(&pilaCriticas);
    inicpila(&pilaTipo1);

    clasificaConcentraciones(tiposMuestras, concentracionesMuestras, DIM, &pilaSeguras, &pilaCriticas, &pilaTipo1);

    //EJ 3
    Pila aux;
    inicpila(&aux);
    int umbral = 0;

    printf("Ingrese umbrall (entre 1 y 100)\n");
    scanf("%i", &umbral);

    informaPromPorc(concentracionesMuestras, DIM, &pilaSeguras, &aux, umbral);

    //EJ 4
    char matPersonas[30][40];

    int validosMatriz = cargaApeyNom(matPersonas);



    return 0;
}

//EJ 1
void cargarArreglosAutomatico(int tiposMuestras[MAX], int concentracionesMuestras[MAX], int DIM)
{
    srand(time(NULL));
    for(int i =0;i<DIM;i++)
    {

        int auxTipo = rand()%3+1;
        int auxConcentracion = rand()%100+1;

        tiposMuestras[i] = auxTipo;
        concentracionesMuestras[i] = auxConcentracion;
    }
}

void cargarArreglosManual(int tiposMuestras[MAX], int concentracionesMuestras[MAX], int DIM)
{
    int contador = 0;

    while(contador < DIM)
    {

        printf("Muestra nro %i\n", contador+1);
        printf("Cargue el tipo de muestra (1,2,3)\n");
        scanf("%i", &tiposMuestras[contador]);
        if(tiposMuestras[contador] < 0 || tiposMuestras[contador] > 3)
        {
            printf("Fuera de rango!\n");
            break;
        }

        printf("Cargue la concentracion de la muestra (1 a 100)\n");
        scanf("%i", &concentracionesMuestras[contador]);
        if(concentracionesMuestras[contador] < 1 || concentracionesMuestras[contador] > 100)
        {
            printf("Fuera de rango!\n");
            break;
        }

        contador++;
    }
}

void mostrarArreglos(int tiposMuestras[MAX], int concentracionesMuestras[MAX], int DIM)
{
    for(int i =0;i<DIM;i++)
    {
        printf("----------------\n");
        printf("Muestra %i:\n", i);
        printf("Tipo %i:\n", tiposMuestras[i]);
        printf("Concentracion %i:\n", concentracionesMuestras[i]);
    }
}

//EJ 2
void clasificaConcentraciones(int tiposMuestras[MAX], int concentracionesMuestras[MAX], int DIM, Pila* pilaSeguras, Pila* pilaCriticas, Pila* pilaTipo1)
{
    for(int i=0;i<DIM;i++)
    {
        if(tiposMuestras[i] == 1)
        {
            apilar(pilaTipo1, concentracionesMuestras[i]);
        }

        if(concentracionesMuestras[i] >= 30 && concentracionesMuestras[i] <= 60)
        {
            apilar(pilaSeguras, concentracionesMuestras[i]);
        }
        else
        {
            apilar(pilaCriticas, concentracionesMuestras[i]);
        }
    }

    printf("Pila A (pilaSeguras)\n");
    mostrar(pilaSeguras);
    printf("Pila B (pilaCríticas)\n");
    mostrar(pilaCriticas);
    printf("Pila C (pilaTipo1)\n");
    mostrar(pilaTipo1);
}

//EJ 3

float promedioConcentraciones (int concentracionesMuestras[MAX], int DIM)
{
    float promedio = 0.0;
    int suma = 0;

    for(int i=0;i<DIM;i++)
    {
        suma += concentracionesMuestras[i];
    }

    promedio = (float)suma/DIM;

    return promedio;
}

float porcBajoUmbral(Pila* pilaSeguras, Pila* aux, int umbral)
{
    int total = 0;
    int menores = 0;
    float promedio = 0.0;
    while(pilavacia(pilaSeguras) != 0)
    {
        if(tope(pilaSeguras) < umbral)
        {
            menores++;
        }
        apilar(aux, desapilar(pilaSeguras));
        total++;
    }
    if (total == 0)
    {
      return 0.0;
    }
    else
    {
        promedio = (float)menores/total;
        return promedio;
    }

}

void informaPromPorc(int concentracionesMuestras[MAX], int DIM, Pila* pilaSeguras, Pila* aux, int umbral)
{
    printf("El promedio de las concentraciones es %.2f\n", promedioConcentraciones(concentracionesMuestras, DIM));
    printf("El promedio de los valores por debajo del umbral es %.2f\n", porcBajoUmbral(pilaSeguras, &aux, umbral));
}

//EJ 4

int cargaApeyNom(char matPersonas[30][40])
{
    /*char continuar;
    int i = 0;
    do
    {
        printf("Para cargar APELLIDO NOMBRE en la posicion %i ingrese 's', para salir ingrese 'n'\n", i+1);
        scanf(" %c", &continuar);
        getchar();

        if(continuar == 's' && i < 30)
        {
            printf("Ingrese el nombre y apellido: \n");
            fgets(matPersonas[i], 40, stdin);

            i++;
        }
    } while(continuar == 's' && i < 30);

    */

    int n = 0;
    printf("Ingrese la cantidad de personas que desa agregar (max 30)\n");
    scanf("%i", &n);
    getchar();

    if (n > 30) {
        n = 30;
    }

    for(int i=0;i<n;i++)
    {
        printf("Ingrese el nombre y apellido: \n");
        fgets(matPersonas[i], 40, stdin);
    }

    return n;
}

int buscaApe(char matPersonas[30][40], int validosMatriz)
{
    char prefijo[3];
    char *ptr;
    int encontrados = 0;

    printf("Ingrese el prefijo a buscar: \n");
    getchar();
    fgets(prefijo, 4, stdin);

    for(int i=0;i<validosMatriz;i++)
    {
       ptr = strstr(matPersonas[i], prefijo);
       if(ptr != NULL && ptr == matPersonas[i])
       {
           printf("Apellido y nombre con prefijo conincidente en la posicion %i", i);
           encontrados++;
       }
    }

    if (encontrados == 0)
    {
        printf("No se encontraron coincidencias con ese prefijo.\n");
    }

    return encontrados;

}
