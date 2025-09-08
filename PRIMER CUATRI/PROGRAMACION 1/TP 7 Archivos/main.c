#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;
} stAlumno;

//EJ 1:
void escribirArchivo(char nombreArchivo[10]);
//EJ 2:
void mostrarArchivo(char nombreArchivo[]);
//EJ 3:
void contarCantidad(char nombreArchivo[]);
//EJ 4:
void cargarAlumno(char nombreArchivoAlumnos[]);
//EJ 5:
void mostrarAlumnos(char nombreArchivoAlumnos[]);
//EJ 6:
void aniadirAlumno(char nombreArchivoAlumnos[]);
//EJ 7:
void cargarPilaLegajo(Pila pilaLegajos, char nombreArchivoAlumnos[]);
//EJ 8:
int ingresasEdad();
void cantAlumnXParametro(char nombreArchivoAlumnos[], int edadUsuario);

//EJ 11
int alumnosXAnio(char nombreArchivoAlumnos[], int anioUsuario);
int pedirAnio();

int main()
{
    char nombreArchivo[] = "archivo.bin";

    //EJ 1:
    escribirArchivo(nombreArchivo);

    //EJ 2:
    mostrarArchivo(nombreArchivo);

    //EJ 3:
    contarCantidad(nombreArchivo);

    //EJ 4:
    char nombreArchivoAlumnos[] = "archivoAlumnos.bin";

    cargarAlumno(nombreArchivoAlumnos);

    //EJ 5:
    mostrarAlumnos(nombreArchivoAlumnos);

    //EJ 6:
    aniadirAlumno(nombreArchivoAlumnos);

    //EJ 7:
    Pila pilaLegajos;
    inicpila(&pilaLegajos);

    cargarPilaLegajo(pilaLegajos, nombreArchivoAlumnos);

    //EJ 8:
    int edadUsuario = ingresasEdad();
    cantAlumnXParametro(nombreArchivoAlumnos, edadUsuario);

    //EJ 11

    int anioUsuario = pedirAnio();
    int cantidadAlumnos = alumnosXAnio(nombreArchivoAlumnos, anioUsuario);



    return 0;
}

//EJ 1: Hacer una función que agregue un elemento al final de un archivo.
void escribirArchivo(char nombreArchivo[]){
    int aux = 0;

    FILE *archi = fopen(nombreArchivo, "ab");

    if(archi!=NULL){
        char continuar;
        do{
            printf("Desea ingresar un numero? ingrese 's' para hacerlo\n");
            scanf(" %c", &continuar);
            if(continuar == 's') {
                printf("Ingrese el numero:\n");
                scanf("%i", &aux);

                fwrite(&aux,sizeof(aux),1,archi);
            }
        } while(continuar == 's');

    } else {
        printf("No se pudo abrir el archivo.\n");
    }
    fclose(archi);
}

//EJ 2: Hacer una función que muestre por pantalla el contenido de un archivo.
void mostrarArchivo(char nombreArchivo[]) {
    FILE *archi = fopen(nombreArchivo, "rb");
    int aux = 0;

    if(archi != NULL){
        while(fread(&aux, sizeof(aux),1,archi) > 0){
        printf("%d\n", aux);
    }
    fclose(archi);
    } else {
        printf("No se pudo abrir el archivo.\n");
    }
}

//EJ 3: Hacer una función que retorne la cantidad de registros que contiene un archivo.
void contarCantidad(char nombreArchivo[]) {
    FILE *archi = fopen(nombreArchivo, "rb");

    int aux = 0;
    int contador = 0;

    if(archi != NULL){
        while(fread(&aux, sizeof(aux),1,archi)){
            contador++;
        }
        printf("La cantidad de datos en el archivo es: %i\n", contador);
        fclose(archi);
    }
}

//EJ 4: Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función
void cargarAlumno(char nombreArchivoAlumnos[]){
    FILE *archi = fopen(nombreArchivoAlumnos, "ab");



    if(archi!=NULL){
        char continuar;
        stAlumno alumnoAux;
        int i = 0;


        fseek(archi, 0, SEEK_END);
        long tamanio = ftell(archi);

        if(tamanio > 0){
                printf("El archivo no esta vacio");


        } else {
            for(i=0;i< 5;i++){

                printf("ALUMNO %i/5: \n", i+1);

                printf("Ingrese el nro de legajo: \n");
                scanf("%i", &alumnoAux.legajo);

                getchar();

                printf("Ingrese el nombre y apellido: \n");
                fgets(alumnoAux.nombreYapellido, 30, stdin);

                printf("Ingrese la edad: \n");
                scanf("%i", &alumnoAux.edad);

                printf("Ingrese el año: \n");
                scanf("%i", &alumnoAux.anio);

                fwrite(&alumnoAux,sizeof(alumnoAux),1,archi);
            }

        }

        fclose(archi);
    }

    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

//EJ 5: Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.
void mostrarAlumnos(char nombreArchivoAlumnos[]){
    FILE *archi = fopen(nombreArchivoAlumnos, "rb");

    stAlumno alumnoAux;
    int i = 0;

    if(archi!=NULL){

            while(fread(&alumnoAux,sizeof(alumnoAux),1,archi) > 0){
                printf("\n------------------\n");
                printf("\nALUMNO %i\n", i+1);
                printf("Legajo: %i\n", alumnoAux.legajo);

                printf("Nombre y Apellido: ");
                puts(alumnoAux.nombreYapellido);

                printf("Edad: %i\n", alumnoAux.edad);

                printf("Anio: %i\n\n", alumnoAux.anio);
                i++;
            }
            fclose(archi);
    }
    else {
        printf("No se pudo abrir el archivo.\n");
    }
}
//EJ 6: Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.
void aniadirAlumno(char nombreArchivoAlumnos[]){
    FILE *archi = fopen(nombreArchivoAlumnos, "ab");

    stAlumno alumnoAux;
    char continuar = 's';

    if(archi!=NULL){

        while(continuar == 's'){
            printf("Desea añadir un nuevo alumno: ingrese 's' para continuar.\n");
            scanf(" %c", &continuar);

            if(continuar == 's'){
                printf("Ingrese el nro de legajo: \n");
                scanf("%i", &alumnoAux.legajo);

                getchar();

                printf("Ingrese el nombre y apellido: \n");
                fgets(alumnoAux.nombreYapellido, 30, stdin);

                printf("Ingrese la edad: \n");
                scanf("%i", &alumnoAux.edad);

                printf("Ingrese el año: \n");
                scanf("%i", &alumnoAux.anio);

                fwrite(&alumnoAux,sizeof(alumnoAux),1,archi);
            }
        }
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
    fclose(archi);
}
//EJ 7: Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.
void cargarPilaLegajo(Pila pilaLegajos, char nombreArchivoAlumnos[]) {
    FILE *archi = fopen(nombreArchivoAlumnos, "rb");

    stAlumno alumno;

    if(archi!=NULL){
        while(fread(&alumno,sizeof(alumno),1,archi) > 0){
            if(alumno.edad>=18){
                apilar(&pilaLegajos, alumno.legajo);
            }
        }
        printf("Legajos de alumnos mayores de edad: \n");
        mostrar(&pilaLegajos);
    }
    else{
        printf("No se encontro el archivo");
    }
}

//EJ 8: Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.
void cantAlumnXParametro(char nombreArchivoAlumnos[], int edadUsuario) {
    FILE *archi = fopen(nombreArchivoAlumnos, "rb");

    stAlumno alumno;
    int mayores18 = 0;
    int cantidadAlumnos=0;

    if(archi!=NULL){
        while(fread(&alumno,sizeof(alumno),1,archi) > 0){
            if(alumno.edad>edadUsuario){
                cantidadAlumnos++;
            }
        }
        printf("La cantidad de alumnos mayores a %i es %i\n", edadUsuario, cantidadAlumnos);
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }

}
int ingresasEdad(){
    int edadIngresada = 0;
    printf("Ingrese una edad: \n");
    scanf("%i", &edadIngresada);

    return edadIngresada;
}

///EJ 11: Crear una función que retorne la cantidad de alumnos que cursan un
///       determinado año. El año buscado se pasa por parámetro.
int alumnosXAnio(char nombreArchivoAlumnos[], int anioUsuario){
    FILE *archi = fopen(nombreArchivoAlumnos, "rb");

    stAlumno alumno;
    int cantidadAlumnos = 0;


    if(archi!=NULL){
        while(fread(&alumno,sizeof(alumno),1,archi) > 0)
            {
            if(anioUsuario == alumno.anio)
            {
                cantidadAlumnos++;
            }
        }
        printf("La cantidad de alumnos que cursan el anio %i es %i\n", anioUsuario, cantidadAlumnos);
        fclose(archi);
        return cantidadAlumnos;
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }

}

int pedirAnio(){
    int anio;
    printf("Ingrese un año: \n");
    scanf("%i", &anio);

    return anio;
}





