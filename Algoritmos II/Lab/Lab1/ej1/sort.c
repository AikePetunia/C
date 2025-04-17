#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void insert(int a[], unsigned int i, unsigned int length) {
    /*
    *  se ordeno segun el uso. 
    *  goes_before(x, y); -> x <= y, checkea si es menor o igual para luego:
    *  swap(a, i, j); -> temp (valor guardado) sería el a[] a cambiar, i y j las posciones a intercambiar.
    *  array_is_sorted(array, length) -> checkea y cuenta, si esta ordenado usando goes_before(); con las posiciones de cada elemento en el arreglo. 
    *\
    *  -> length declarado en el main, dice el largo del arreglo.
    *  -> en esta funcion, a es el arreglo, i y length son para el bucle
    *  -> insertion_sort() (funcion d abajo) tmb se debe
    */

    int j = i;// so we can compare from the beggining, we start at the left.
    
    if (!array_is_sorted(a, length)) { // inv ? 
    while (j > 0 && !goes_before(a[j-1], a[j])) {
        swap(a, j, j-1);
        j = j - 1;
    }

    }
    
    // es void, no debe retornar nada
    // TE LO JURO POR MI VIDA QUE ESTUVE 2 HORAS, Y LO QUE ESTABA MAL ERA POR QUE ESTABA PONIENDO MAL LA CARPETA MAÑANA ME  ALK.FJ2QOUIRDHJ1!!
}

void insertion_sort(int a[], unsigned int length) {
    // assert();
    for (unsigned int i = 1; i < length ; i++) {
        assert(array_is_sorted(a, i)); // inv ? 
        insert(a, i, length);
    }
}
