#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

int iteration = 0;

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 /* needs implementation */
    // primer paso: hacer que el pivote quede en medio (tq, lft<piv<rgt)
    if (der > izq) {
    int pvt = partition(a, izq, der);
        quick_sort_rec(a,izq,pvt-1);
        quick_sort_rec(a,pvt+1,der);
    }
}


void quick_sort(int a[], unsigned int length) {
    int startIdx = 0;
    int endIdx = length - 1;
    bool alreadySorted = false;
    // caso base, por que harias sort en algo chikito
    if (endIdx <= startIdx) {
        alreadySorted = true;
    }

    if (!alreadySorted) {
        quick_sort_rec(a, 0, (length == 0) ? startIdx : endIdx);
    }
}

/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie array_helpers.o sort.o sort_helpers.o main.o -o sorter
./sorter ../input/example-unsorted.in
*/