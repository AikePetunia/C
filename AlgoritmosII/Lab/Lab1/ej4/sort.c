#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i, unsigned int length) { // unsigned int length SE AGREGO PQ SI NO, NO FUNCA NADA
    int j = i;// so we can compare from the beggining, we start at the left.
    
    if (!array_is_sorted(a, length)) { // inv ? 
    while (j > 0 && !goes_before(a[j-1], a[j])) {
        swap(a, j, j-1);
        j = j - 1;
    }

    }
}

void insertion_sort(int a[], unsigned int length) {
        for (unsigned int i = 1; i < length ; i++) {
        assert(array_is_sorted(a, i)); // inv ? 
        insert(a, i, length);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    int pivot = a[((izq + der) / 2)];
    
    swap(a, ((izq + der) / 2), der);
    
    unsigned int i = izq;
    
    for (unsigned int j = izq; j < der; j++) {
        if (a[j] <= pivot) {
            swap(a, i, j);
            i++;
        }
    }
    
    swap(a, i, der);
    
    printf("Partition: izq=%d, der=%d, pivot_pos=%d, pivot=%d\n", 
           izq, der, i, a[i]);
    
    return i;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    // caso base:
    // los arreglos que tienen 0 o 1 elemento, no hay izq o der:
    // a = {}, a = {0}
    if (izq >= der) {
        return;
    }

    // caso recursivo, donde vuelvo a llamar a la misma funcion.
    // arreglos de tamaño n 
    // a = {1, 2, 3}, a = {3,5}, a = {4,5,6,7,1}

    // llamado recursivo
    unsigned int pivot = partition(a, izq, der); 
    if (pivot > 0 && pivot-1 >= izq) {
        quick_sort_rec(a, izq, pivot-1);  
    }
    quick_sort_rec(a, pivot+1, der);  

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
