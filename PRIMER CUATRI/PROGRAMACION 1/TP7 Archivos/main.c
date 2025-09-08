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
void mostrarUnAlumno (char nombreArchivoAlumnos[], stAlumno alumnoAux);
//EJ 6:
void aniadirAlumno(char nombreArchivoAlumnos[]);
//EJ 7:
void cargarPilaLegajo(Pila pilaLegajos, char nombreArchivoAlumnos[]);
//EJ 8:
int ingresasEdad();
void cantAlumnXParametro(char nombreArchivoAlumnos[], int edadUsuario);
//EJ 9:
int checkeoEdades(int *edad1, int *edad2);
void nomXEdades(char nombreArchivoAlumnos[], int edad1, int edad2);
//EJ 10:
void mayorAlumno (char nombreArchivoAlumnos[]);
//EJ 11
int alumnosXAnio(char nombreArchivoAlumnos[], int anioUsuario);
int pedirAnio();
//EJ 12
void mostrarArchiAlumnosXAnio(char nombreArchivoAlumnos[], stAlumno arregloAlumnos[20], char nombreArchivoXEdad[]);
int arregloAArchivoXAnio(stAlumno arregloAlumnos[20], int validos, char nombreArchivoXEdad[]);
int deArchiAArray (char nombreArchivoAlumnos[], stAlumno arregloAlumnos[20]);
//EJ 13:
int cantRegistros (char nombreArchivo[]);
//EJ 14
int ingresarNroRegistro();
void mostrarAlumnoEnRango(char nombreArchivoEj14[], int registro);
//EJ 15:
stAlumno modificarUnRegistro(stAlumno alumnoAux, int registro);
void modificarRegistro(char nombreArchivoEj14[], int registro);
//EJ 16:
void voltearArchivo(char nombreArchivoEj14[]);




int main()
{
    char nombreArchivo[] = "archivo.bin";
    char nombreArchivoAlumnos[] = "archivoAlumnos.bin";
    char nombreArchivoEj14[] = "archivoAlum10registros.bin";
    char nombreArchivoXEdad[] = "archivoAlumnosXEdad.bin";

    Pila pilaLegajos;
    inicpila(&pilaLegajos);

    int option = -1;
    int edadUsuario, edad1, edad2, checkeo, anioUsuario, cantidadAlumnos, registro, registroEj15;

    stAlumno arregloAlumnos[20];

    do {
        printf("\n--- MENU DE OPCIONES ---\n");
        printf("1 - Escribir en un archivo de enteros\n");
        printf("2 - Mostrar archivo de enteros\n");
        printf("3 - Contar cantidad de enteros en un archivo\n");
        printf("4 - Cargar un alumno en un archivo\n");
        printf("5 - Mostrar archivo de alumnos\n");
        printf("6 - Cargar de a un alumno\n");
        printf("7 - Cargar legajos en una pila\n");
        printf("8 - Ver cantidad de alumnos de una edad determinada\n");
        printf("9 - Mostrar los alumnos en un rango de edades\n");
        printf("10 - Mostrar el mejor alumno\n");
        printf("11 - Cantidad de alumnos de un año determinado\n");
        printf("12 - Filtrar los estudiantes de un año en particular\n");
        printf("13 - Contar la cantidad de registros de un archivo\n");
        printf("14 - Buscar alumno por nro de registro\n");
        printf("15 - Modificar los datos de un alumno\n");
        printf("16 - Voltear los registros\n");
        printf("0 - Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                escribirArchivo(nombreArchivo);
                break;
            case 2:
                mostrarArchivo(nombreArchivo);
                break;
            case 3:
                contarCantidad(nombreArchivo);
                break;
            case 4:
                cargarAlumno(nombreArchivoAlumnos);
                break;
            case 5:
                mostrarAlumnos(nombreArchivoAlumnos);
                break;
            case 6:
                aniadirAlumno(nombreArchivoAlumnos);
                break;
            case 7:
                cargarPilaLegajo(pilaLegajos, nombreArchivoAlumnos);
                break;
            case 8:
                edadUsuario = ingresasEdad();
                cantAlumnXParametro(nombreArchivoAlumnos, edadUsuario);
                break;
            case 9:
                checkeo = checkeoEdades(&edad1, &edad2);
                if(checkeo == 1){
                    nomXEdades(nombreArchivoAlumnos, edad1, edad2);
                }
                break;
            case 10:
                mayorAlumno(nombreArchivoAlumnos);
                break;
            case 11:
                anioUsuario = pedirAnio();
                cantidadAlumnos = alumnosXAnio(nombreArchivoAlumnos, anioUsuario);
                printf("Cantidad de alumnos del año %d: %d\n", anioUsuario, cantidadAlumnos);
                break;
            case 12:
                // Faltaría implementar esta opción si corresponde
                printf("Funcionalidad no implementada aún.\n");
                break;
            case 13:
                cantRegistros(nombreArchivo);
                break;
            case 14:
                aniadirAlumno(nombreArchivoEj14);
                registro = ingresarNroRegistro();
                mostrarAlumnos(nombreArchivoEj14);
                mostrarAlumnoEnRango(nombreArchivoEj14, registro);
                break;
            case 15:
                registroEj15 = ingresarNroRegistro();
                modificarRegistro(nombreArchivoEj14, registroEj15);
                printf("Registro modificado:\n");
                mostrarAlumnoEnRango(nombreArchivoEj14, registroEj15);
                break;
            case 16:
                voltearArchivo(nombreArchivoEj14);
                mostrarAlumnos(nombreArchivoEj14);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    } while(option != 0);

    return 0;
}

/*
int main()
{
    char nombreArchivo[] = "archivo.bin";
    char nombreArchivoAlumnos[] = "archivoAlumnos.bin";
    char nombreArchivoEj14[] = "archivoAlum10registros.bin";

    //EJ 1:
    escribirArchivo(nombreArchivo);

    //EJ 2:
    mostrarArchivo(nombreArchivo);

    //EJ 3:
    contarCantidad(nombreArchivo);

    //EJ 4:
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

    //EJ 9:
    int edad1 = 0;
    int edad2 = 0;

    int checkeo = checkeoEdades(&edad1, &edad2);
    if(checkeo == 1){
        nomXEdades(nombreArchivoAlumnos, edad1, edad2);
    }

    //EJ 10:
    mayorAlumno(nombreArchivoAlumnos);


    //EJ 11
    int anioUsuario = pedirAnio();
    int cantidadAlumnos = alumnosXAnio(nombreArchivoAlumnos, anioUsuario);

    //EJ 12
    stAlumno arregloAlumnos[20];
    char nombreArchivoXEdad[] = "archivoAlumnosXEdad.bin";

    mostrarArchiAlumnosXAnio(nombreArchivoAlumnos, arregloAlumnos, nombreArchivoXEdad);

    //EJ 13:
    cantRegistros (nombreArchivo);


    //EJ 14


    aniadirAlumno(nombreArchivoEj14);
    int registro = ingresarNroRegistro();
    //mostrarAlumnos(nombreArchivoEj14);
    mostrarAlumnoEnRango(nombreArchivoEj14, registro);

    //EJ 15:
    int registroEj15 = ingresarNroRegistro();
    modificarRegistro(nombreArchivoEj14, registroEj15);
    printf("Registro modificado: \n");
    mostrarAlumnoEnRango(nombreArchivoEj14, registroEj15);

    //EJ 16:
    voltearArchivo(nombreArchivoEj14);
    mostrarAlumnos(nombreArchivoEj14);

    return 0;
}
*/


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
        int tamanio = ftell(archi);

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

                mostrarUnAlumno(nombreArchivoAlumnos, alumnoAux);
                i++;
            }
            fclose(archi);
    }
    else {
        printf("No se pudo abrir el archivo.\n");
    }
}

void mostrarUnAlumno (char nombreArchivoAlumnos[], stAlumno alumnoAux){

    printf("Legajo: %i\n", alumnoAux.legajo);

    printf("Nombre y Apellido: ");
    puts(alumnoAux.nombreYapellido);

    printf("Edad: %i\n", alumnoAux.edad);

    printf("Anio: %i\n\n", alumnoAux.anio);
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

//EJ 9: Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un
//rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar
void nomXEdades(char nombreArchivoAlumnos[], int edad1, int edad2){
    FILE * archi = fopen(nombreArchivoAlumnos, "rb");

    stAlumno alumno;

    if(archi != NULL){
        while(fread(&alumno,sizeof(alumno),1,archi) > 0){
            if(alumno.edad >= edad1 && alumno.edad <= edad2){
                puts(alumno.nombreYapellido);
            }
        }
        fclose(archi);
    } else{
        printf("No se pudo abrir el archivo");
    }
}
int checkeoEdades(int *edad1, int *edad2){
    printf("Ingrese la primer edad del rango (menor): \n");
    scanf("%i", edad1);

    printf("Ingrese la segunda edad del rango (mayor): \n");
    scanf("%i", edad2);

    if(*edad1 < *edad2){
        return 1;
    } else {
        printf("Las edades ingresadas son erroneas. \n");
        return 0;
    }
}

// EJ 10: Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.
void mayorAlumno (char nombreArchivoAlumnos[]) {
    FILE *archi = fopen(nombreArchivoAlumnos, "rb");

    stAlumno alumno;
    stAlumno mayor;

    if(archi!=NULL){
        if(fread(&mayor,sizeof(mayor),1,archi) > 0){
            while(fread(&alumno, sizeof(alumno), 1, archi)){
                if(alumno.edad>mayor.edad){
                mayor = alumno;
                }
            }
            printf("El alumno mayor es: \n");
            mostrarUnAlumno(nombreArchivoAlumnos, mayor);
        }
        fclose(archi);
    } else{
        printf("No se pudo abrir el archivo.\n");
    }
}

//EJ 11: Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro.
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

//EJ 12: Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo. Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.
int deArchiAArray (char nombreArchivoAlumnos[], stAlumno arregloAlumnos[20]){
    FILE *archi = fopen(nombreArchivoAlumnos, "rb");

    stAlumno alumnoAux;
    int i = 0;

    if(archi!=NULL){
        while(fread(&alumnoAux,sizeof(alumnoAux),1,archi) > 0){
            arregloAlumnos[i] = alumnoAux;
            i++;
        }
        fclose(archi);
    } else{
        printf("No se pudo abrir el archivo!!!!!!!!\n");
    }

    return i;
}
int arregloAArchivoXAnio(stAlumno arregloAlumnos[20], int validos, char nombreArchivoXEdad[]){
    FILE *archi = fopen(nombreArchivoXEdad, "wb");

    stAlumno alumnosAux;
    int anio = pedirAnio();

    if(archi!=NULL){
        for(int i=0;i<validos;i++){
            if(arregloAlumnos[i].anio == anio){
                alumnosAux = arregloAlumnos[i];

                fwrite(&alumnosAux,sizeof(alumnosAux),1,archi);
            }
        }
        fclose(archi);
        return anio;
    } else {
        printf("No se pudo abrir el archivo!!!!!\n");
        return 0;
    }
}
void mostrarArchiAlumnosXAnio(char nombreArchivoAlumnos[], stAlumno arregloAlumnos[20], char nombreArchivoXEdad[]){
    FILE *archi = fopen(nombreArchivoXEdad, "rb");

    int validosEj12 = deArchiAArray (nombreArchivoAlumnos, arregloAlumnos);
    int anio = arregloAArchivoXAnio(arregloAlumnos, validosEj12, nombreArchivoXEdad);

    stAlumno alumnoAux;

    if(archi!=NULL){
        printf("ARCHIVO ALUMNOS ANIO %i:\n", anio);
        while(fread(&alumnoAux,sizeof(alumnoAux),1,archi) > 0){
            mostrarUnAlumno(nombreArchivoXEdad, alumnoAux);
        }
        fclose(archi);
    } else {
        printf("No se pudo abrir el archivo!!!!!\n");
    }
}

//EJ 13: Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.
int cantRegistros (char nombreArchivo[]) {
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

//EJ 14: Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro. Controlar no sobrepasar los límites del archivo
int ingresarNroRegistro(){
    int registro;
    printf("Ingrese el numero de registro (entre 0 y 9): \n");
    scanf("%i", &registro);

    if(registro<0 || registro>9) {
        printf("Error, registro ingresado fuera de rango, vuelva a ingresarlo: \n");
        return ingresarNroRegistro();
    }

    return registro;
}
void mostrarAlumnoEnRango(char nombreArchivoEj14[], int registro){
    FILE *archi = fopen(nombreArchivoEj14, "rb");

    stAlumno alumnoAux;

    if(archi!=NULL){
        fseek(archi,registro*sizeof(stAlumno),SEEK_SET);
        if(fread(&alumnoAux,sizeof(alumnoAux),1,archi) ==1){
            printf("Alumno en el registro ingresado: \n");
        mostrarUnAlumno(nombreArchivoEj14, alumnoAux);
        } else {
            printf("No se pudo leer el registro %i.\n", registro);
        }

        fclose(archi);
    } else {
        printf("No se pudo abrir el archivo!!!!!\n");
    }

}

//EJ 15:  Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos. La misma debe permitir modificar uno o todos los campos de la estructura y sobreescribir el registro existente en el archivo.
void modificarRegistro(char nombreArchivoEj14[], int registro){
    FILE *archi = fopen(nombreArchivoEj14, "rb+");

    stAlumno alumnoAux;
    if(archi!=NULL){
        fseek(archi, registro*sizeof(stAlumno),SEEK_SET);
        if(fread(&alumnoAux, sizeof(alumnoAux),1,archi)==1){
            fseek(archi, registro*sizeof(stAlumno),SEEK_SET);
            alumnoAux = modificarUnRegistro(alumnoAux, registro);
            fwrite(&alumnoAux,sizeof(alumnoAux),1,archi);
        } else {
            printf("No se pudo leer el registro %i.\n", registro);
        }
        fclose(archi);
    } else {
        printf("No se pudo abrir el archivo!!!!!\n");
    }

}
stAlumno modificarUnRegistro(stAlumno alumnoAux, int registro){
    int modif = 1;

    printf("Modificar datos de alumno en el registro nro &i\n", registro);
    printf("Que registro desea modificar? \n legajo (ingrese 1) /nombre (ingrese 2) / edad (ingrese 3) / anio (ingrese 4)\n0 para salir\n");
    scanf("%i", &modif);

    switch(modif)
    {
    case 1:
        printf("Ingrese el nuevo nro de legajo: \n");
        scanf("%i", &alumnoAux.legajo);
        break;
    case 2:
        printf("Ingrese el nuevo nombre: \n");
        while (getchar() != '\n');
        fgets(alumnoAux.nombreYapellido,30,stdin);
        break;
    case 3:
        printf("Ingrese la nueva edad: \n");
        scanf("%i", &alumnoAux.edad);
        break;
    case 4:
        printf("Ingrese el nuevo anio: \n");
        scanf("%i", &alumnoAux.anio);
        break;

    }


    char continuar;
    printf("Desea modificar otro dato del mismo registro? ingrese 's' para hacerlo\n");
    scanf(" %c", &continuar);

    if(continuar == 's'){
        return modificarUnRegistro(alumnoAux, registro);
    } else{
        return alumnoAux;
    }
}

//EJ 16: Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo. No se puede usar otro archivo auxiliar ni un arreglo auxiliar. Debe trabajar sobre el archivo. Puede utilizar variables de tipo alumno auxiliares.
void voltearArchivo(char nombreArchivoEj14[]){
    FILE *archi = fopen(nombreArchivoEj14, "rb+");

    stAlumno alumnoAuxA;
    stAlumno alumnoAuxB;

    if(archi!=NULL){
        fseek(archi, 0, SEEK_END);
        int totalRegistros = ftell(archi) / sizeof(stAlumno);

        for(int i=0;i<totalRegistros/2;i++){
            //Voy a la primera posición y lo guardo en un aux
            fseek(archi,i*sizeof(stAlumno),SEEK_SET);
            fread(&alumnoAuxA,sizeof(alumnoAuxA),1,archi);

            //Voy a la ultima posición y lo guardo en un aux
            fseek(archi,(totalRegistros -i-1)*sizeof(stAlumno),SEEK_END);
            fread(&alumnoAuxB,sizeof(alumnoAuxB),1,archi);

            //voy a la primera posicion y pego el ultimo
            fseek(archi,i*sizeof(stAlumno),SEEK_SET);
            fwrite(&alumnoAuxB,sizeof(alumnoAuxB),1,archi);

            //voy a la ultima posicion y pego el primero
            fseek(archi,i*sizeof(stAlumno),SEEK_END);
            fwrite(&alumnoAuxA,sizeof(alumnoAuxA),1,archi);

        }
        fclose(archi);
    } else {
        printf("No se pudo abrir el archivo!!!!!\n");
    }
}

//EJ 17:
