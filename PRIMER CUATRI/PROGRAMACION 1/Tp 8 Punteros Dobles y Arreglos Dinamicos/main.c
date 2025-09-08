#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct
{
    int legajo;
    char nombre[30];
    int edad;
    int anio;
} stAlumno;


//2A
int pares(int arreglo[MAX], int dinamico[]);
int contarPares(int arreglo[MAX]);
//2B
int* paresMalloc (int arreglo[MAX]);
//2C
void paresPuntDoble(int arreglo[MAX], int** destino, int *cantidad_pares);
//EJ 3:
int cantRegistros (char nombreArchivo[]) ;
void pasarAUnArreglo(char nombreArchivo[], int validos, stAlumno *arregloAlumnos[]);
void mostrarUnAlumno(stAlumno* alumno);


int main()
{
    //1
    int valor;
    int * punt = &valor;
    int ** ppunt = &punt;

    printf("Dirección de memoria de valor: %p\n", &valor);
    printf("Dirección de memoria de punt: %p\n", &punt);
    printf("Dirección de memoria de ppunt (puntero doble): %p\n\n\n", &ppunt);

    *punt = 30;
    printf("Dato guardado en 'valor' con puntero simple *punt: %i\n", valor);
    **ppunt = 50;
    printf("Dato guardado en 'valor'con puntero doble **ppunt: %i\n\n", valor);

    //2A

    int arreglo[10] = {1,2,3,4,5,6,7,8,9,10};

    int cantidad_pares = contarPares(arreglo);


    int *dinamico=(int*)malloc(cantidad_pares * (sizeof(int)));

    int cantidad_real = pares(arreglo, dinamico);
    printf("\nCantidad de pares: %d\n", cantidad_real);
    //2B
    int*arregloPares = paresMalloc(arreglo);
    //2C
    int *punteroDoble = NULL;
    int cantidad_pares2c;

    paresPuntDoble(arreglo, &punteroDoble, &cantidad_pares2c);

    printf("ARREGLO CON PUNTEROS DOBLES:\n");
    for(int i = 0; i < cantidad_pares2c; i++)
    {
        printf("%i, ", punteroDoble[i]);
    }
    //EJ 3:
    char nombreArchivo[] = "archivoAlumnos.bin";

    int validos = cantRegistros(nombreArchivo);
    stAlumno *arregloAlumnos =(stAlumno*)malloc(validos * sizeof(stAlumno));

    pasarAUnArreglo(nombreArchivo, validos, &arregloAlumnos);



    return 0;
}

int pares(int arreglo[10], int dinamico[])
{
    int j =0;

    printf("ARREGLO DINAMICO PARES: \n");
    for(int i=0;i<MAX;i++)
    {
        if(arreglo[i] % 2 == 0)
        {

            dinamico[j] = arreglo[i];
            printf("%i, ", dinamico[j]);
            j++;

        }
    }
    printf("\n");
    return j;
}

int contarPares(int arreglo[MAX])
{
    int cantidad_pares = 0;
    for (int i = 0; i < MAX; i++) {
        if (arreglo[i] % 2 == 0) {
            cantidad_pares++;
        }
    }
    return cantidad_pares;
}

int* paresMalloc (int arreglo[MAX])
{
    int cantidad_pares = contarPares(arreglo);

    int* arregloMalloc = (int*)malloc(cantidad_pares * sizeof(int));

    int j =0;

    printf("ARREGLO DINAMICO EN FUNCION: \n");
    for(int i=0;i<MAX;i++)
    {
        if(arreglo[i] % 2 == 0)
        {

            arregloMalloc[j] = arreglo[i];
            printf("%i, ", arregloMalloc[j]);
            j++;

        }
    }
    printf("\n");

    return arregloMalloc;
}

//2C
void paresPuntDoble(int arreglo[MAX], int** destino, int *cantidad_pares2c)
{
    *cantidad_pares2c = contarPares(arreglo);

    *destino=(int*)malloc(*cantidad_pares2c * sizeof(int));

    int j=0;
    for(int i=0;i<MAX;i++)
    {
        if(arreglo[i] %2 == 0)
        {
            (*destino)[j] = arreglo[i];
            j++;
        }
    }
    printf("\n");
}

//EJ 3

int cantRegistros (char nombreArchivo[])
{
    printf("............................");
    FILE *archi = fopen(nombreArchivo, "rb");

    int aux = 0;
    int total = 0;



    if(archi!=NULL){
        fseek(archi,0,SEEK_END);   // mueve puntero al final
        aux = ftell(archi);        // aux = 16 (bytes totales)
        total = aux / sizeof(int); // total = 16 / 4 = 4 (registros)

        fclose(archi);

        printf("La cantidad de registros es de: %i", total);
        return total;

    } else {
        printf("No se pudo abrir el archivo!!!!!\n");
        return 0;
    }
}
void pasarAUnArreglo(char nombreArchivo[], int validos, stAlumno *arregloAlumnos[])
{
    FILE *archi=fopen(nombreArchivo, "rb");

    stAlumno alumnoAux;
    int i=0;

    if(archi!=NULL){
        while(fread(&alumnoAux,sizeof(stAlumno),1,archi)<validos){
            *arregloAlumnos[i] = alumnoAux;
            mostrarUnAlumno(arregloAlumnos[i]);
            i++;
        }
    }
    else

    {
        printf("No se pudo abrir el archivo.\n");
    }
}

void mostrarUnAlumno(stAlumno* alumno) {
    printf("Legajo: %i\n", alumno->legajo);
    printf("Nombre y Apellido: %s\n", alumno->nombre);
    printf("Edad: %i\n", alumno->edad);
    printf("Anio: %i\n\n", alumno->anio);
}




