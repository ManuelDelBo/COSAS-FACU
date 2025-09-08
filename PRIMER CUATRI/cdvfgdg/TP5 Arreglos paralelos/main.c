#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//PROTOTIPADO

//EJ 1:
int cargarLegajo();
void cargarNombre(char nombre[]);
int cargarAnio();
int cargarAlumno (int legajos[20], char nombres[20][30], int anios[20]);
//EJ 2:
void mostrarAlumnos(int legajos[20], char nombres[20][30], int anios[20], int validos);
//EJ 3:
int legajoEncontrado (int legajos[20], int validos);
//EJ 4:
void nombreEncontradoXLegajo (int legajos[20], char nombres[20][30], int validos);
//EJ 5:
void ordenarXNombre(int legajos[20], char nombres[20][30], int anios[20], int validos);
int posicionMenor(char nombres[20][30], int validos, int u);
void intercambiarStrings(char nombres[20][30],int i, int j);
void intercambioEntero(int numero[ ], int i, int j);



int main()
{
    int legajos[20];
    char nombres[20][30];
    int anios[20];

    //EJ 1:
    int validos = cargarAlumno(legajos, nombres, anios);

    //EJ 2:
    mostrarAlumnos(legajos, nombres, anios, validos);

    //EJ 3:
    int encontrado = legajoEncontrado(legajos, validos);

    if(encontrado == 0){
        printf("No se encontro el legajo");
    } else {
        printf("El legajo buscado se encuentra en la posicion %i\n", encontrado);
    }

    //EJ 4:
    nombreEncontradoXLegajo (legajos, nombres, validos);

    //EJ 5:
    ordenarXNombre(legajos, nombres, anios, validos);
    mostrarAlumnos(legajos, nombres, anios, validos);


    return 0;
}


//EJ 1:
int cargarAlumno (int legajos[20], char nombres[20][30], int anios[20]){
    char continuar = 's';
    int i = 0;

    do{
        printf("Desea cargar un alumno en la posicion %i? Ingrese 's' para continuar \n", i+1);
        scanf(" %c", &continuar);

        if(continuar == 's'){
            legajos[i] = cargarLegajo();
            getchar();
            cargarNombre(nombres[i]);
            anios[i] = cargarAnio();

            i++;
        } else{
            printf("Entendido, no se cargara un nuevo alumno.\n\n\n");

        }

    }while(continuar == 's' && i < 20);

    return i;
}

int cargarLegajo(){
    int legajo = 0;
    printf("Cargue el nro de legajo: \n");
    scanf("%i", &legajo);

    return legajo;
}

void cargarNombre(char nombre[]){
    printf("Cargue el Nombre del alumno: \n");
    fgets(nombre, 30, stdin);
}

int cargarAnio(){
    int anio = 0;
    printf("Cargue el anio del alumno: \n");
    scanf("%i", &anio);

    return anio;
}

//EJ 2:
void mostrarAlumnos(int legajos[20], char nombres[20][30], int anios[20], int validos){
    int i = 0;

    while(i < validos){
        printf("\n\nALUMNO NRO %i\n", i+1);

        printf("\nLegajo %i\n", legajos[i]);

        printf("\nNombre: ");
        puts(nombres[i]);

        printf("\nAnio %i\n", anios[i]);

        i++;

    }
}

//EJ 3:
int legajoEncontrado (int legajos[20], int validos){
    int aux = 0;

    printf("Ingrese el nor de legajo para mostrar la posicion (mayor a 0): \n");
    scanf("%i", &aux);

    int encontrado = buscarLegajo(legajos, validos, aux);



    return encontrado;
}

int buscarLegajo (int legajos[20], int validos, int aux) {
    int encontrado = 0;

    for(int i=0; i<validos; i++){
        if(legajos[i] == aux){
            encontrado = i+1;
        }
    }

    return encontrado;
}

//EJ 4:

void nombreEncontradoXLegajo (int legajos[20], char nombres[20][30], int validos) {
    int aux = 0;
    int posicionLegajo = 0;
    printf("Ingrese legajo para mostrar el nombre del alumno (mayor a 0): \n");
    scanf("%i", &aux);

    posicionLegajo = buscarLegajo(legajos, validos, aux);

    printf("El nombre del alumno de la posicion %i es \n", posicionLegajo);
    puts(nombres[posicionLegajo-1]);
}

//EJ 5:

void ordenarXNombre(int legajos[20], char nombres[20][30], int anios[20], int validos){
    int posMenor = 0;
    int i=0;

    while(i<validos - 1){
        posMenor = posicionMenor(nombres, validos, i);
        intercambiarStrings(nombres, posMenor, i);
        intercambioEntero(legajos, posMenor, i);
        intercambioEntero(anios, posMenor, i);

        i++;
    }
}

int posicionMenor(char nombres[20][30], int validos, int u){
    int posMenor = u;
    for(int i = u+1; i<validos;i++){
        if(strcmp(nombres[i], nombres[posMenor]) < 0) {
            posMenor = i;
        }
    }

    return posMenor;
}

void intercambiarStrings(char nombres[20][30],int i, int j){
 char aux[30];
 strcpy(aux, nombres[i]);
 strcpy(nombres[i], nombres[j]);
 strcpy(nombres[j], aux);
}

void intercambioEntero(int numero[ ], int i, int j){
 int aux = numero[i];
 numero[i] = numero[j];
 numero[j] = aux;
}



