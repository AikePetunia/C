#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int length) {
    bool hasCima;

    int k = 0;
    int j = 0; 
    // entonces, debo de ver una parte, y luego la otra
        while (a[k] >= a[k+1]) {
            k++;
        }
    
        while(a[j] <= a[j+1]) {
            j++;
        }

    // tiene cima si llegamos al final
    hasCima = j == length - 1;
        
    return hasCima;  
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima(int a[], int length) {
    bool hasCima;

    int k = 0;
    int j = 0; 
    // entonces, debo de ver una parte, y luego la otra
        while (a[k] >= a[k+1]) {
            k++;
        }
        while(a[j] <= a[j+1]) {
            j++;
        }

    // tiene cima si llegamos al final
    hasCima = j == length - 1;
        
    if (hasCima) {
        printf("la cima es %d", a[k]);
    } else {
        printf("No tiene cima");
    }
    return 0;
}
