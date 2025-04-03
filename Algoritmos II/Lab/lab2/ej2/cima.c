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
    // se tiene que
    // H son los mayores a K
    // N los menores a K
    //  H >= K <= N    
    bool hasCimaIzq, hasCimaDer, hasCima = false;

    int k = (length) / 2; // como determino bien bien?
    // entonces, debo de ver una parte, y luego la otra
    for (int i = 0; i < length; i++) {
        while (a[i] >= a[k]) {
            hasCimaIzq = true;
            i++;
        }
    }
    
    for (int j = k; k < length; j++) {
        while(a[j] <= a[k]) {
            hasCimaDer = true; 
            j++;
        }
    }
        
    return hasCima = hasCimaDer && hasCimaIzq;
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
    bool hasCimaIzq, hasCimaDer, hasCima = false;

    int k = (length) / 2; // como determino bien bien?
    // entonces, debo de ver una parte, y luego la otra
    for (int i = 0; i < length; i++) {
        while (a[i] >= a[k]) {
            hasCimaIzq = true;
            i++;
        }
    }
    
    for (int j = k; k < length; j++) {
        while(a[j] <= a[k]) {
            hasCimaDer = true; 
            j++;
        }
    }
    if (hasCima) {
        printf("la cima es %d", a[k]);
    } else {
        printf("No tiene cima");
    }
    return 0;
}
