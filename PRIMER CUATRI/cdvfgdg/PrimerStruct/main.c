#include <stdio.h>
#include <stdlib.h>

#define CANTALUMN 2

typedef struct{
    int matricula;
    char nombre[20];
    char sexo;
} Alumno;

int cargarStruct (Alumno arregloAlumnos[CANTALUMN]);
void cargarUnAlumno(Alumno *aux);
void mostrarArreglo(Alumno arregloAlumnos[CANTALUMN], int validos);
void mostrarUnAlumno(Alumno unAlumno);


int main()
{
    Alumno arregloAlumnos[CANTALUMN];

    int validosArreglo = cargarStruct(arregloAlumnos);
    mostrarArreglo(arregloAlumnos, validosArreglo);
    return 0;
}

int cargarStruct (Alumno arregloAlumnos[CANTALUMN]) {
    int i = 0;

    while(i < CANTALUMN){
        printf("Ingrese el %i alumno: \n", i+1);
        /*printf("matricula: \n");
        scanf("%i", &arregloAlumnos[i].matricula);
        getchar();
        printf("nombre: \n");
        gets(&arregloAlumnos[i].nombre);
        printf("sexo: (m o f): \n");
        scanf(" %c", &arregloAlumnos[i].sexo);*/

        cargarUnAlumno(&arregloAlumnos[i]);

        i++;
    }

    return i;
}
void cargarUnAlumno(Alumno *aux){

    printf("matricula: \n");
    scanf("%i", &aux->matricula);
    getchar();
    printf("nombre: \n");
    gets(&aux->nombre);
    printf("sexo: (m o f): \n");
    scanf(" %c", &aux->sexo);
}

void mostrarArreglo(Alumno arregloAlumnos[CANTALUMN], int validos){
    printf("Arrelo de alumnos: \n");

    for(int i =0;i<validos;i++){
            printf("%i:\n", i+1);
        mostrarUnAlumno(arregloAlumnos[i]);
    }
}

void mostrarUnAlumno(Alumno unAlumno){
    printf("Matricula: %i\n", unAlumno.matricula);
    printf("Nombre: %s\n", unAlumno.nombre);
    printf("Matricula: %c\n", unAlumno.sexo);
}
