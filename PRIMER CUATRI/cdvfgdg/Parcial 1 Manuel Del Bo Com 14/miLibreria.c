#include <stdio.h>

void burbujeo(int arreglo[], int validos)
{
    for (int i = 0; i < validos - 1; i++)
    {
        for (int j = 0; j < validos - i - 1; j++)
        {
            if (arreglo[j] > arreglo[j + 1])
            {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}
