#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */
    int i = izq+1;
    int piv = izq;
    int j = der;
    while (i<=j) {
        if (a[i] <= a[piv]) {
            i++;
        } else if (a[j] >= a[piv]){
            j++;
        } else if (a[i] > a[piv] && a[j]<a[piv]) {
            swap(a, i, j);
            i++;
            j++;
        }
    }
    swap(a, piv, j);
    j = piv;

    /* PRECONDITION:
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

