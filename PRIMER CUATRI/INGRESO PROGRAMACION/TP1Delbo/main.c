#include <stdio.h>
#include <stdlib.h>

int main()
{
    int camisas;
    float precioCamisa = 100.0; // Se usa float en caso de cálculos decimales
    float precioConDescuento, total;

    printf("¿Cuántas camisas va a comprar? ");
    scanf("%d", &camisas);

    total = camisas * precioCamisa;

    if (camisas >= 3) {
        precioConDescuento = total * 0.80; // Descuento del 20%
    } else {
        precioConDescuento = total * 0.90; // Descuento del 10%
    }

    printf("El total a pagar con descuento es de: $%.2f\n", precioConDescuento);

    return 0;
}
