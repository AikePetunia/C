#include "flag_sort.h"
#include <stdio.h>
void swap(color_t a[], int i, int j);

/**
 * @brief Ordenar un arreglo de tres colores RED, WHITE y BLUE.
 *
 * Dado un arreglo cuyos elementos son tres colores posibles RED, WHITE y BLUE,
 * ordenarlos de manera que queden todos los RED primero, después todos los 
 * WHITE y al final todos los BLUE, formando la bandera de Córdoba.
 * 
 * @param a Arreglo de colores.
 * @param length Largo del arreglo.
 */
void flag_sort(color_t a[], int length) {
    // red == 0
    // white == 1
    // blue == 2

    // no tiene sentido ordenar algo chico (por que ya está ordenado)
    if(!(length == 0 || length == 1)) {

        int i = 0;
        int izq = 0;
        int der = length - 1;
        while (i <= der) {
            if (a[i] == 0) { // si es rojo, va a izquierda
                swap(a, izq, i);
                i++;
                izq++;
            } else if (a[i] == 1) { // si es blanco, va al medio
                i++;
            } else if (a[i] == 2) { // si es azul, va al final.
                swap(a, i, der);
                der--;
            }
         //   printf("%d en a[%d] \n", i, a[i]);
        }
    }
}

void swap(color_t a[], int i, int j) {
    color_t tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
   // printf("swapped a[%d] %d w a[%d] %d \n", i, a[i], j, a[j]);
}
/*
gcc -Wall -Wextra -pedantic -std=c99 flag_sort.c tests.c -o tests 
./tests
*/