#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"
/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
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


// added by me "la funcion no existe"
bool tiene_cima(int a[], int length) {


    /* old code that doens't work and i surrender */
    bool hasCima;
    bool increases = true;
    bool decreaces = true;
    int izq = 0;
    int der = length - 1; 
    // 1 < 2 < 3 < 4 < 5 < 6 (caso 1)
    // 5 > 4 > 3 > 2 > 1 < 2 < 3 < 4 < 5 < 6 (Caso 2)
    //  puede manejar arreglos desordenados de solo 2 elementos, no de más
    for (int i = 0; i < length; i++) {
        if (a[i] > a[i+1] && increases) {
            while (a[izq] > a[izq+1]) {
                printf("Comparacion %d > %d \n", a[izq], a[izq+1]);
                izq++;
            }
            increases = a[i] > a[i+1] ? true : false;
        }
    }
    // dejo de ir de >, entonces se cambia "la orientacion de ocmparacion" empezando donde se dejo. 
    for (int i = 0; i < length; i++) {
        if (a[i] < a[i+1] && decreaces) {
            int izq1 = izq;
            while(a[izq1] < a[izq1+1]) {
                printf("Comparacion %d < %d \n", a[izq1], a[izq1+1]);
                izq1++;
            }
            // tiene cima si llegamos al final
            decreaces = a[i] < a[i+1] ? true : false;
            hasCima = izq1 == der;
        } 
    } 
        
    return hasCima;  
}

int cima_log(int a[], int length) {
    // utilizando la idea de busqueda binaria
    int izq = 0;
    int der = length;
    int cima, res;
    // si found no está, el while se hace un bucle
    bool found = false;
    
    // al saber que tiene cima, ya sabemos que los elementos a la izquierda, son menores al mid
    // y los de la derecha, son mayores. Entonces nuestra cima es mid.
    // caso base (requerido por DyV)
    printf("Largo del arreglo: %d \n", length);
    printf("Posicion izquierda: %d \n", izq);
    printf("Posicion derecha: %d \n", der);
    if (length == 1 || length == 0 || izq >= der  ) {
        res = 1;
    } else {
        if (tiene_cima(a, length)) {
            while (izq < der && found != true ) {
            int mid = (izq + der) / 2;
            // la cima es mid por que ya se asume que tiene cima (pre)
            cima = a[mid];

            if (a[mid - 1] < cima && cima > a[mid + 1]) { // si esta entre un mayor y un menor en los lados, está bien 
                res = mid + 1;
                found = true;
            }
            else if (cima <= a[mid+1]) { // si la cima es menor a lo q esta a su der, toda la izq se descarta
                izq = mid + 1; 
            }
            else { 

                der = mid;
            }
        }
        } else {
            res = -1;
        }
        
    }   

    return res;
}
