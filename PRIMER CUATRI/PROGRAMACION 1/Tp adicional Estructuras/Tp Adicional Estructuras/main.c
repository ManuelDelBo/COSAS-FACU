#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMENSION 20
#define DIM 3
#define CANTCATEG 10

typedef struct{
    int idProducto;
    int stock;
    float precio;
    char nombre[DIMENSION];
    char categoriaProducto[DIMENSION];

} stProducto;

typedef struct{
    char categoria[DIMENSION];
    stProducto productos[DIM];
    int productosDisponibles;

} stCategorias;

void cargarProducto(stProducto productosSinCategorizar[DIM]);
void datosProducto(stProducto productosSinCategorizar[DIM], int i);
void mostrarProducto(stProducto productosSinCategorizar[DIM]);
void cargarCategorias(stProducto productosSinCategorizar[DIM], stCategorias productosCategorizados[CANTCATEG]);
void cargarProductoEnCategoria(stProducto productosSinCategorizar[DIM], stCategorias productosCategorizados[CANTCATEG]);

int main()
{
    stProducto productosSinCategorizar[DIM];

    cargarProducto(productosSinCategorizar);
    mostrarProducto(productosSinCategorizar);

    stCategorias productosCategorizados[CANTCATEG];
    cargarCategorias(productosSinCategorizar, productosCategorizados);

    return 0;
}

void cargarProducto(stProducto productosSinCategorizar[DIM]){
    char continuar;

    for(int i=0;i<DIM;i++){
        printf("Cargue el producto id %i \n", i);
        datosProducto(productosSinCategorizar, i);
    }
}

void datosProducto(stProducto productosSinCategorizar[DIM], int i){
    productosSinCategorizar[i].idProducto = i;

    printf("Ingrese el stock: \n");
    fflush(stdin);
    scanf("%i", &productosSinCategorizar[i].stock);

    printf("Ingrese el precio: \n");
    fflush(stdin);
    scanf("%f", &productosSinCategorizar[i].precio);

    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(&productosSinCategorizar[i].nombre);

    printf("Ingrese el categoria: \n");
    fflush(stdin);
    gets(&productosSinCategorizar[i].categoriaProducto);
}

void mostrarProducto(stProducto productosSinCategorizar[DIM]){
    for(int i=0;i<DIM;i++){
        printf("Procuto ID = %i\n\n", productosSinCategorizar[i].idProducto);

        printf("Nombre: ");
        puts(productosSinCategorizar[i].nombre);

        printf("Stock: %i\n", productosSinCategorizar[i].stock);

        printf("Precio: %.2f\n", productosSinCategorizar[i].precio);

        printf("Categoria: ");
        puts(productosSinCategorizar[i].categoriaProducto);
    }
}
void cargarCategorias(stProducto productosSinCategorizar[DIM], stCategorias productosCategorizados[CANTCATEG]){
    int cantidadCategorias =0;

    for(int i=0;i<DIM;i++){
        int encontrada = 0;
        for(int j=0;j<CANTCATEG;j++){
            if(strcmp(productosCategorizados[j].categoria, productosSinCategorizar[i].categoriaProducto) == 0){
                encontrada = 1;
            }
            if(encontrada ==0 && cantidadCategorias < CANTCATEG){
                strcpy(productosCategorizados[cantidadCategorias].categoria, productosSinCategorizar[i].categoriaProducto);
                cantidadCategorias++;
            }
        }
    }
}

void cargarProductoEnCategoria(stProducto productosSinCategorizar[DIM], stCategorias productosCategorizados[CANTCATEG]){
    int categoriaExistente = 0;

    for(int i=0;i<DIM;i++){
            for(int j=0;j<CANTCATEG;j++){
                if(strcmp(productosSinCategorizar[i].categoriaProducto, productosCategorizados[j].categoria) == 0){
                    categoriaExistente++;
                    strcpy(categoria, productosCategorizados[j].categoria);

                    strcpy(productosCategorizados[categoria].productos, productosSinCategorizar[i]);
                    strcpy(productosCategorizados[categoria].productosDisponibles, ++);
                }
            }

    }
}


