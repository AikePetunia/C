#include <stdbool.h>
#include "k_esimo.h"
#include "assert.h"
// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], int length, int k) {
    /**
    Escrib´ı un algoritmo que dado un arreglo a : [1..n] of int y un n´umero natural k ≤ n devuelve
    el elemento de a que quedar´ıa en la celda a[k] si a estuviera ordenado. Est´a permitido realizar
    intercambios en a, pero no ordenarlo totalmente. La idea es explotar el hecho de que el procedimiento
    partition del quick sort deja al pivot en su lugar correcto
    */
        
    // debo de usar partition: "la idea es explotar el hecho de que el procedimiento de partition del quiccksor..."
    // "numero natural k <= n"
    unsigned int pivot = partition(a, 0, (length == 0) ? 0 : length - 1);
    assert(k <= a[length - 1]); // added by me, para q retorne lo q quiero
    if (k <= a[length - 1]) {
        swap(a, a[pivot], a[k]);
        // no deberia de estar array_is_sorted? por que dice SI ESTUVIERA ordenado, deberia de asumirlo
    }
    return a[k];
    // return 0; <-- old
}

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
