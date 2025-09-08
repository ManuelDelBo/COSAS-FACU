#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20

typedef struct {
int matricula;
char nombre[30];
char genero;
} stAlumno;

//EJ 1:
int cargarAlumno(stAlumno alumnos[DIM]);
stAlumno cargarUnAlumno();
//EJ 2:
void mostrarAlumnos(stAlumno alumnos[DIM], int validos);
void mostrarUnAlumno(stAlumno alumnos[DIM], int validos, int i);
//EJ 3:
void mostrarAlumnoXMatricula(stAlumno alumnos[DIM], int validos);
//EJ 4:
void ordenarXMatricula(stAlumno alumnos[DIM], int validos);
//EJ 5:
void estudianteXGenero(stAlumno alumnos[DIM], int validos, char generoMain);
//EJ 6:
void insertarNuevoAlumno(stAlumno alumnos[DIM], int *validos);
//EJ 7:
void ordenarPorNombre(stAlumno alumnos[DIM], int validos);
//EJ 8:
int alumnosXGenero(stAlumno alumnos[DIM], int validos, char generoMain);


int main()
{
    stAlumno alumnos[DIM];
    int validos = 0;
    char generoMain;
    int opcion;

    do{
        printf("\n======= MENU DE OPCIONES =======\n");
        printf("1. Cargar alumnos\n");
        printf("2. Mostrar todos los alumnos\n");
        printf("3. Buscar alumno por matrícula\n");
        printf("4. Ordenar alumnos por matrícula\n");
        printf("5. Buscar estudiantes de un genero\n");
        printf("6. Insertar un nuevo alumno ordenandolo por matricula\n");
        printf("7. Ordenar pon nombre\n");
        printf("8. Mostrar cantidad de alumnos por genero\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                //EJ 1:
                validos = cargarAlumno(alumnos);
                break;
            case 2:
                //EJ 2:
                mostrarAlumnos(alumnos, validos);
                break;
            case 3:
                //EJ 3:
                mostrarAlumnoXMatricula(alumnos, validos);
                break;
            case 4:
                //EJ 4:
                ordenarXMatricula(alumnos, validos);
                mostrarAlumnos(alumnos, validos);
                break;
            case 5:
                //EJ 5:
                printf("Ingrese el genero a buscar (m/f/o): ");
                scanf(" %c", &generoMain);
                estudianteXGenero(alumnos, validos, generoMain);
                break;
            case 6:
                //EJ 6:
                insertarNuevoAlumno(alumnos, &validos);
                mostrarAlumnos(alumnos, validos);
                break;
            case 7:
                //EJ 7:
                ordenarPorNombre(alumnos, validos);
                mostrarAlumnos(alumnos, validos);
                break;
            case 8:
                //EJ 8:
                printf("Ingrese el genero a contar (m/f/o): ");
                scanf(" %c", &generoMain);
                alumnosXGenero(alumnos, validos, generoMain);
                break;
        }
    }while(opcion != 0);


    return 0;
}

//EJ 1:
int cargarAlumno(stAlumno alumnos[DIM]){
    char cargar = 's';
    int i = 0;

    do{
        printf("Desea cargar un alumno? Ingrese 's' para continuar: \n");
        scanf(" %c", &cargar);

        if(cargar == 's'){
            printf("------------------------\n");
            printf("Alumno nro %i\n", i+1);
            alumnos[i] = cargarUnAlumno();
            printf("------------------------\n");

            i++;
        } else{
            printf("Entendido, no se cargaran mas alumnos.\n");
        }

    }while(cargar == 's');

    return i;
}

stAlumno cargarUnAlumno(){
    stAlumno auxAlumno;

    printf("Cargue el nro de matricula del alumno: \n");
    scanf("%i", &auxAlumno.matricula);
    getchar();

    printf("Cargue el nombre del alumno: \n");
    fgets(auxAlumno.nombre, 30, stdin);

    printf("Cargue el genero del alumno (m o f): \n");
    scanf(" %c", &auxAlumno.genero);

    return auxAlumno;
}
//EJ 2:
void mostrarAlumnos(stAlumno alumnos[DIM], int validos){
    printf("\n\nALUMNOS\n\n");
    for(int i = 0;i<validos;i++){
        mostrarUnAlumno(alumnos, validos, i);
    }
}
void mostrarUnAlumno(stAlumno alumnos[DIM], int validos, int i){
    printf("________________________\n");
    printf("Alumno %i:\n", i+1);
    printf("Matricula: %i\n", alumnos[i].matricula);
    printf("Nombre: ");
    puts(alumnos[i].nombre);
    printf("Genero: %c\n", alumnos[i].genero);
    printf("________________________\n");
}
//EJ 3:
void mostrarAlumnoXMatricula(stAlumno alumnos[DIM], int validos){
    int matriculaAux = 0;
    int encontrado = 0;
    printf("Ingrese la matricula del alumno que quiera buscar: \n");
    scanf("%i", &matriculaAux);

    if(matriculaAux != 0){
        for(int i = 0; i<validos;i++){
            if(matriculaAux == alumnos[i].matricula){
                printf("ALUMNO ENCONTRADO: \n");
                mostrarUnAlumno(alumnos, validos, i);
                encontrado++;
                break;
            }
        }
        if(encontrado == 0){
            printf("Alumno no encontrado, matricula erronea.\n");
        }
    }
}

//EJ 4:
void ordenarXMatricula(stAlumno alumnos[DIM], int validos){
    int i, j, posMenor;
    stAlumno aux;

    printf("\nALUMNOS ORDENADOS POR MATRÍCULA:\n");

    for(i = 0; i < validos - 1; i++){
        posMenor = i;
        for(j = i + 1; j < validos; j++){
            if(alumnos[j].matricula < alumnos[posMenor].matricula){
                posMenor = j;
            }
        }

        if(posMenor != i){
            aux = alumnos[i];
            alumnos[i] = alumnos[posMenor];
            alumnos[posMenor] = aux;
        }
    }
}

//EJ 5:
void estudianteXGenero(stAlumno alumnos[DIM], int validos, char generoMain){
    printf("\n\nALUMNOS DEL GENERO %c\n\n", generoMain);

    for(int i=0;i<validos;i++){
        if(alumnos[i].genero == generoMain){
            mostrarUnAlumno(alumnos, validos, i);
        }
    }
}

//EJ 6:
void insertarNuevoAlumno(stAlumno alumnos[DIM], int *validos){
    if(*validos >= DIM) {
    printf("No se pueden cargar más alumnos. Arreglo lleno.\n");
    return;}

    stAlumno auxAlumno;
    printf("Ingrese un nuevo alumno el cual serà insertado segun su matriucla: \n");
    auxAlumno = cargarUnAlumno();

    int i = 0;

    while(i < *validos && auxAlumno.matricula > alumnos[i].matricula){
        i++;
    }

    for(int j=*validos;j>i;j--){
        alumnos[j] = alumnos[j - 1];
    }

    alumnos[i] = auxAlumno;

    (*validos)++;

}

//EJ 7:
void ordenarPorNombre(stAlumno alumnos[DIM], int validos) {
    int i, j;
    stAlumno aux;

    for(i = 1; i < validos; i++) {
        aux = alumnos[i];
        j = i - 1;

        while(j >= 0 && strcmp(aux.nombre, alumnos[j].nombre) < 0) {
            alumnos[j + 1] = alumnos[j];
            j--;
        }

        alumnos[j + 1] = aux;
    }
}

//EJ 8:
int alumnosXGenero(stAlumno alumnos[DIM], int validos, char generoMain){
    int generoSeleccionado = 0;

    for(int i=0;i<validos;i++){
        if(alumnos[i].genero == generoMain){
            generoSeleccionado++;
        }
    }

    if(generoSeleccionado == 0){
        printf("No hay alumnos del genero %c\n", generoMain);
    } else{
        printf("La cantidad de alumnos del genero %c es: %i\n", generoMain, generoSeleccionado);
    }

    return generoSeleccionado;
}
