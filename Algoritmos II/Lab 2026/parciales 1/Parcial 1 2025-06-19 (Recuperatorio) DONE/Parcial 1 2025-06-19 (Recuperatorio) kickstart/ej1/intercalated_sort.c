#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "intercalated_sort.h"
void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "Largo de arreglo: %u\n", length);
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%i", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
}

void swap(int a[], int i, int j) {
    //printf("\n -- swap -- \n");
    //printf("i: %d, a[i]: %d \n",i, a[i]);
    //printf("j: %d, a[j]: %d \n", j, a[j]);
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    //printf("-- swapped -- \n");
    // printf("a[i]: %d \n", a[i]);
    // printf("a[j]: %d \n", a[j]);
}

void intercalated(int a[], unsigned int i, unsigned int length) {
    unsigned int j = i;
    while (j >= 2 && a[j] < a[j-2]) {
        swap(a, j-2, j);
        j -= 2;
    }
}

/**
 * @brief Ordena las posiciones pares del arreglo (0-based)
 * usando el algoritmo de ordenación por inserción.
 */
void intercalated_sort(int a[], unsigned int length) {
    for (unsigned int i = 2; i < length; i += 2) {
        intercalated(a, i, length);
    }
}


/*
gcc -Wall -Wextra -std=c99 tests.c intercalated_sort.c -o tests 
./tests 
*/