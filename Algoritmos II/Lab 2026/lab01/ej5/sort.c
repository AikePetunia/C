#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    // assert(0<=izq);
    // assert(der<lenght);
    int piv = izq;
    int i = izq+1;
    int j = der;
    printf("---- patition --- \n");
    printf("piv: %d \n", piv);
    printf("i: %d \n", i);
    printf("j: %d \n", j);
    printf("izq: %d \n", izq);
    printf("der: %d \n", der);

    while (i<=j) {
        if (goes_before(a[i], a[piv])) {
            i = i+1;
        } else if (goes_before(a[piv], a[j])) {
            j = j-1;
        } else if (a[i] > a[piv] && a[j] < a[piv]) {
            swap(a, i,j);
            i = i + 1;
            j = j + 1;
        }
    }
    swap (a, piv, j);
    piv = j;
    printf("partition \n");
    return piv;
    /* PRECONDITION: 
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    
    printf("--- quick sort rec --- \n");
    printf("izq %d \n", izq);
    printf("der %d \n", der);
    if (der > izq ) {
    int pvt = partition(a, izq, der);

    if (pvt > 0) {
        quick_sort_rec(a,izq,pvt-1);

    }
        quick_sort_rec(a,pvt+1,der);
    }}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


