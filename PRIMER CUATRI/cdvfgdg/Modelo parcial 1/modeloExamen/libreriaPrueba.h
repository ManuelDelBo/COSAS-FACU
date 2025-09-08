#ifndef LIBRERIAPRUEBA_H_INCLUDED
#define LIBRERIAPRUEBA_H_INCLUDED

#define DIM 8
#define APYNOM 30
#define CARACTERES 40

//EJ 1:
void cargaArreglos(char tiposMuestras[DIM], char concentracionesMuestras[DIM], int muestras);
void cargaManual(char tiposMuestras[DIM], char concentracionesMuestras[DIM], int muestras);
void cargaRandom(char tiposMuestras[DIM], char concentracionesMuestras[DIM], int muestras);
//EJ 2:
void clasificaConcentraciones(char tiposMuestras[DIM], char concentracionesMuestras[DIM], int muestras, Pila *pilaSeguras, Pila *pilaCriticas, Pila *pilaTipo1);
//EJ 3:
//3a
float promedioConcentraciones(char concentracionesMuestras[DIM], int muestras);
//3b
float porcBajoUmbral(Pila pilaSeguras, int umbral);
//3c
void informaPromPorc(char concentracionesMuestras[DIM], int muestras, Pila pilaSeguras, int umbral);
//EJ 4:
//4a
int cargaApeyNom(char matPersonas[APYNOM][CARACTERES]);
//4b
int buscaApe(char matPersonas[APYNOM][CARACTERES], int cantPersonas, int posiciones[cantPersonas]);
//4c
void cargaBuscados(char matEncontrados[APYNOM][CARACTERES], char matPersonas[APYNOM][CARACTERES], int posiciones[], int cantidad);


#endif // LIBRERIAPRUEBA_H_INCLUDED
