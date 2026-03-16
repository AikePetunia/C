#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

// NO ES VOID, RETORNA VALORES
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* PRECONDITION: 
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */

    /*

    * el quick sort, agarra un pivote, ya sea en el inicio, medio o final, 
    * y lo usa para comparar un elemento del anterior (si es que no es <): 
    * "Permutes elements of a[izq..der] and returns pivot such that: - izq <= pivot <= der"
    *\

    * goes before lo usamos una vez dividido el arreglo en izq y derecho.
    *\

    * swap, para intercambiar los valores si es q es goes_before da true.
    *\ 

    * quick_sort nos da el arreglo, la parte izquierda, y la parte derecha
    * primero hacemos partition, luego is sorted, goes_before, swap, y asi.
    *\
    
    */ 

    int i, j, pivot;
    pivot = izq;
    i = izq + 1;
    j = der;
    while (i < j) {
        if (a[i] <= a[izq]) {
            i++;
        } else if (a[j] >= a[pivot]) {
            j++;
        } else if (a[i] > a[pivot] && a[j] < a[pivot]) {
            swap(a,i,j);
            i++;
            j++;
        }
    }
    swap(a, pivot, j);
    pivot = j;
    return i; 
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (izq >= der) {
        return;
    }

    unsigned int pivot = partition(a, izq, der); 
    if (pivot > 0 && pivot-1 >= izq) {
        quick_sort_rec(a, izq, pivot-1);   
    }
    quick_sort_rec(a, pivot+1, der);  

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

