#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define CAPIC 5

//EJ 1:
int factorial(int num);
//EJ 2:
int potencia(int base, int exponente);
//EJ 3
void mostrarArray(int array[MAX], int validos);
//EJ 4:
void mostrarArrayInvertido(int array[MAX], int validos, int i);
//EJ 5
char capicua(int arrayCapicua[CAPIC], int validos, int i);
//EJ 6
int sumaArreglo(int array[MAX], int validos, int i);
//EJ 7
int menorArreglo(int array[MAX], int validos, int i);
//EJ 8
void cargarNumeros(char nombreArchivo[]);
int menorDeArchivo(char nombreArchivo[]);
int menorRecursion(FILE *archi, int menor);
//EJ 9
void invertirArray (int array[MAX], int validos, int i);
void rotar (FILE *archi, int pos, int fin);
void invertirArchivo(char nombreArchivo[]);
//EJ 10
void mostarElementosInvertidosArchivo(char nombreArchivo[]);
void mostrarInvertidoArchi(FILE *archi, int pos);


int main()
{
    int num = 0;
    int array[MAX] = {1,2,3,4,5};
    int validos = MAX;
    int i = 0;
    int arrayCapicua[CAPIC] = {1,2,3,2,1};
    int validosCapicua = CAPIC;
    int iEj5 = 0;
    int iEj6 = 0;
    int iEj7 = 0;
    char nombreArchivo[] = "archivo.bin";

    /*EJ 1:


    printf("Ingrese un numero para caluclar su factorial: \n");
    scanf("%i", &num);

    int rtaFactorial = factorial(num);
    printf("El factorial de %i es %i\n", num, rtaFactorial);


    //EJ 2:
    int base;
    int exponente;

    printf("Ingrese la base: \n");
    scanf("%i", &base);
    printf("Ingrese el exponente: \n");
    scanf("%i", &exponente);

    int resultadoEj2 = potencia(base, exponente);
    printf("El resultado de base %i y exponente %i es %i\n", base, exponente, resultadoEj2);

    //EJ 3:
    mostrarArray(array, validos);
    printf("\n");

    //EJ 4:
    mostrarArrayInvertido(array, validos, i);
    printf("\n");

    //EJ 5
    char rtaEj5 = capicua(arrayCapicua, validosCapicua, iEj5);
    if(rtaEj5 == 's')
    {
        printf("El arreglo es capicua.\n");
    }
    else
    {
        printf("El arreglo no es capicua.\n");
    }

    //EJ 6
    int totalSuma = sumaArreglo(array, validos, iEj6);
    printf("La suma del array es %i", totalSuma);

    //EJ 7
    int menor = menorArreglo(array, validos, i);
    printf("El menor del arreglo es %i", menor);
    */

    //EJ 8
    cargarNumeros(nombreArchivo);
    int menor = menorDeArchivo(nombreArchivo);
    printf("El menor es %i\n", menor);

    //EJ 9
    invertirArray (array, validos, i);

    invertirArchivo(nombreArchivo);

    //EJ 10
    mostarElementosInvertidosArchivo(nombreArchivo);






    return 0;
}

//EJ 1:
int factorial(int num)
{
    int rta;
    if(num==0)
    {
        rta=1;
    }
    else
    {
        rta = num * factorial(num-1);
    }

    return rta;
}

//EJ 2:
int potencia(int base, int exponente)
{
    int rta;
    if(exponente == 0 )
        {
            rta = 1;
        }
    else
    {
        rta = base * potencia(base, exponente-1);
    }

    return rta;
}

//EJ 3
void mostrarArray(int array[MAX], int validos)
{
    if(validos == 1)
    {
        printf("%i, ", array[0]);
    }
    else
    {
        mostrarArray(array, validos-1);
        printf("%i, ", array[validos-1]);
    }
}

//EJ 4:
void mostrarArrayInvertido(int array[MAX], int validos, int i)
{
    if(i == validos-1)
    {
        printf("%i,", array[i]);
    }
    else
    {
        mostrarArrayInvertido(array, validos, i+1);
        printf("%i, ", array[i]);
    }
}

//EJ 5
char capicua(int arrayCapicua[CAPIC], int validos, int i)
{
    if(i >= validos / 2)
    {
        return 's';
    }
    if(arrayCapicua[i] != arrayCapicua[validos-1-i])
    {
        return 'n';
    }

    return capicua(arrayCapicua, validos,i+1);
}

//EJ 6
int sumaArreglo(int array[MAX], int validos, int i)
{
    if(i == validos)
    {
        return 0;
    }
    else
    {
        return array[i] + sumaArreglo(array, validos, i + 1);
    }
}

//EJ 7
int menorArreglo(int array[MAX], int validos, int i)
{
    int menor = 0;
    if(i == validos-1)
    {
        return array[i];
    }
    else
    {
        menor = menorArreglo(array, validos, i+1);
    }
    if(array[i] < menor)
    {
        return array[i];
    }
    else
    {
        return menor;
    }
}

//EJ 8

void cargarNumeros(char nombreArchivo[])
{
    int aux = 0;
    FILE *archi = fopen(nombreArchivo, "ab");


    if(archi!=NULL)
    {
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

    }
    else
    {
        printf("No se pudo acceder al archivo.\n");
    }
}

int menorDeArchivo(char nombreArchivo[])
{
    FILE * archi= fopen(nombreArchivo, "rb");

    int menor;
    int aux;


    if(archi!=NULL)
    {
        if(fread(&aux,sizeof(int),1,archi) == 1)
        {
           int menor = menorRecursion(archi, aux);
           fclose(archi);
           return menor;
        }
    }
    else
    {
        printf("No se pudo acceder al archivo.\n");
        return 0;
    }

}

int menorRecursion(FILE *archi, int menor)
{
    int aux;

    if (fread(&aux, sizeof(int), 1, archi) == 1)
    {
        if (aux < menor)
        {
            menor = aux;
        }
        return menorRecursion(archi, menor);
    }
    else
    {
        return menor;
    }
}

//EJ 9
void invertirArray (int array[MAX], int validos, int i)
{
    if(i >= validos / 2)
    {
        int aux = array[i];
        array[i] = array[validos-1-i];
        array[validos-1-i] = aux;

        invertirArray(array, validos, i);
    }
    mostrarArray(array, validos);
}

void invertirArchivo(char nombreArchivo[])
{
    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi!=NULL)
    {
        fseek(archi, 0, SEEK_END);
        int fin = ftell(archi) / sizeof(int);

        rotar(archi, 0, fin);
        fclose(archi);

    }
    else
    {
        printf("Nose pudo abrir el archivo\n");
    }
}

void rotar (FILE *archi, int pos, int fin)
{
    if(pos>=fin/2) return;

    int izq, der;

    fseek(archi, pos*sizeof(int),SEEK_SET);
    fread(&izq,sizeof(int),1,archi);

    fseek(archi, (fin-pos-1)*sizeof(int),SEEK_SET);
    fread(&der,sizeof(int),1,archi);


    fseek(archi, (fin-pos-1),SEEK_SET);
    fwrite(&izq,sizeof(int),1,archi);

    fseek(archi, pos*sizeof(int),SEEK_SET);
    fwrite(&der,sizeof(int),1,archi);

    rotar(archi, pos+1,fin);
}

void mostarElementosInvertidosArchivo(char nombreArchivo[])
{
    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        int total = ftell(archi) /sizeof(int);

        mostrarInvertidoArchi(archi, total-1);
        fclose(archi);
    }
    else
    {
        printf("Nose pudo abrir el archivo\n");
    }
}

void mostrarInvertidoArchi(FILE *archi, int pos)
{
    int aux=0;
    if(pos<0){
        return;
    }
    else
    {
        fseek(archi,pos*sizeof(int),SEEK_SET);
        fread(&aux,sizeof(int),1,archi);
        printf("%d ", aux);

        mostrarInvertidoArchi(archi,pos-1);
    }
}














