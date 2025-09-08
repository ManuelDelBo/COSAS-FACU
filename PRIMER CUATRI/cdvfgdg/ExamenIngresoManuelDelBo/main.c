#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"
#include <time.h>

int main()
{
    //1. Ingreso de datos de temperatura: Crear dos pilas: MESES y TEMPERATURAS.
    Pila meses, temperaturas, basura, auxTemp, primerSemestre, segundoSemestre, auxSemestreUno, auxSemestreDos;
    inicpila(&meses);
    inicpila(&temperaturas);
    inicpila(&basura);
    inicpila(&auxTemp);
    inicpila(&primerSemestre);
    inicpila(&segundoSemestre);
    inicpila(&auxSemestreUno);
    inicpila(&auxSemestreDos);

    //MESES: debe almacenar los números del 1 al 12, representando cada mes del año.
    //Los meses deben ser cargados sin intervención del usuario.
    for(int i=1; i <=12; i++)
    {
        apilar(&meses,i);
    }
    printf("Meses:");
    mostrar(&meses);

    //TEMPERATURAS debe almacenar las temperaturas promedio de cada mes (nros. enteros),
    //las cuales deben ser números enteros entre -30 y 50 grados Celsius. Si se ingresa una
    //temperatura promedio fuera de este rango, el programa debe mostrar un mensaje de error y
    //volver a solicitarla
    int continuar = 0;
    int acumulador = 0;

    do
    {
        printf("Inserte la temperatura del mes entre -30 y 50: \n");
        scanf("%i", &acumulador);
        apilar(&temperaturas, acumulador);
        continuar = continuar + 1;
        if(acumulador < -30 || acumulador > 50)
        {
            printf("EL valor no esta en el reango permitido.\n");
            apilar(&basura, desapilar(&temperaturas));
            continuar = continuar - 1;

        }

    }
    while(continuar < 12);

    mostrar(&temperaturas);
    //2. Temperaturas más alta y baja del año:
    //Encontrar y mostrar las temperaturas más alta y baja, indicando en qué mes se dieron.


    int tempXMes = 0;
    int mayor = tope(&temperaturas);
    int menor = tope(&temperaturas);

    while(!pilavacia(&temperaturas))
    {
        apilar(&auxTemp, desapilar(&temperaturas));
        tempXMes = tope(&auxTemp);

        if(mayor<tempXMes)
        {
            mayor = tempXMes;
        }

        if(menor>tempXMes)
        {
            menor = tempXMes;
        }

    }

    printf("La temperatura mayor es: %i\n", mayor);
    printf("La temperatura menor es: %i\n", menor);

     while (!pilavacia(&auxTemp)) {
        apilar(&temperaturas, desapilar(&auxTemp));
    }

    //3. Clasificar las temperaturas según el semestre del año en 2 pilas, 1erSemestre y 2doSemestre.

    for(int i=0;i<6;i++){
        apilar(&primerSemestre, desapilar(&temperaturas));
    }
    for(int i=0;i<6;i++){
        apilar(&segundoSemestre, desapilar(&temperaturas));
    }
    printf("Temperaturas primer semenestre: \n");
    mostrar(&primerSemestre);

    printf("Temperaturas segundo semenestre: \n");
    mostrar(&segundoSemestre);

    while (!pilavacia(&segundoSemestre)) {
        apilar(&temperaturas, desapilar(&segundoSemestre));
    }
    while (!pilavacia(&primerSemestre)) {
        apilar(&temperaturas, desapilar(&primerSemestre));
    }

    //4. Búsqueda y actualización de un promedio de temperatura:
    //Solicitar al usuario que ingrese un mes (número entre 1 y 12) y un promedio de temperatura
    //para ese mes. Luego reemplazar el promedio actual de temperaturas de ese mes, por el
    //nuevo promedio ingresado. Mostrar la pila antes y después del reemplazo (para poder verificar).

    int mesUsuario = 0;
    int promedioUsuario = 0;

    printf("Ingrese el mes que quiera modificar la temperatura del 1 al 12: \n");
    scanf("%i", &mesUsuario);
    if (mesUsuario < 1 || mesUsuario > 12) {
        printf("Mes inválido.\n");
        return 1;
    }

    printf("Ahora ingrese que promedio de temperatura quiere ingresar a ese mes: \n");
    scanf("%i", &promedioUsuario);

    for (int i = 12; i >= 1; i--) {
        int tempActual = desapilar(&temperaturas);
        if (i == mesUsuario) {
            apilar(&auxTemp, promedioUsuario);
        } else {
            apilar(&auxTemp, tempActual);
        }
    }
    while(!pilavacia(&auxTemp)){
        apilar(&temperaturas, desapilar(&auxTemp));
    }

    printf("Temperatura de mes %i modificada correctametne: \n", mesUsuario);
    mostrar(&temperaturas);

    //5. Cálculo del promedio por semestre:
    //Calcular y mostrar el promedio de las temperaturas de los dos semestres del año (enero a junio y julio a diciembre).

    int contadorPrimerSemenste = 0;
    int contadorSegundoSemenste = 0;
    float promedioSemestreUno = 0.0;
    float promedioSemestreDos = 0.0;


    for(int i=0;i<6;i++){
        apilar(&segundoSemestre, desapilar(&temperaturas));
    }
    while(!pilavacia(&segundoSemestre)){
        contadorSegundoSemenste += tope(&segundoSemestre);
        apilar(&auxSemestreDos, desapilar(&segundoSemestre));
    }

    promedioSemestreDos = (float)contadorSegundoSemenste/6;




    for(int i=0;i<6;i++){
        apilar(&primerSemestre, desapilar(&temperaturas));
    }

    while(!pilavacia(&primerSemestre)){
        contadorPrimerSemenste += tope(&primerSemestre);;
        apilar(&auxSemestreUno, desapilar(&primerSemestre));
    }

    promedioSemestreUno = (float)contadorPrimerSemenste/6;


    printf("El promedio del primer semestre es de: %.2f\n\n", promedioSemestreUno);
    printf("El promedio del segundo semestre es de: %.2f\n\n", promedioSemestreDos);




    return 0;
}
