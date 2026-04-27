#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    // assert(0<=izq);
    // assert(der<lenght);
    int piv = izq;
    int i = izq+1;
    int j = der;

    while (i<=j) {
        if (a[i] <= a[piv]) {
            i = i+1;
        } else if (a[j] >= a[piv]) {
            j = j-1;
        } else if (a[i] > a[piv] && a[j] < a[piv]) {
            swap(a, i,j);
            i = i + 1;
            j = j + 1;
        }
    }
    swap (a, piv, j);
    piv = j;
    
    return piv;
    /* PRECONDITION: 
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (der > izq) {
    // primer paso: hacer que el pivote quede en medio (tq, lft<piv<rgt)
    int pvt = partition(a, izq, der);
        quick_sort_rec(a,izq,pvt-1);
        quick_sort_rec(a,pvt+1,der);
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie array_helpers.o sort.o sort_helpers.o main.o -o sorter
./sorter ../input/example-unsorted.in
*/