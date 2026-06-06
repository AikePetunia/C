#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"

static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int piv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;

    while (i <= j) {
        if (goes_before(a[i], a[piv])) {
            i = i + 1;
        } else if (goes_before(a[piv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
            i = i + 1;
            j = j - 1;
        }
    }

    swap(a, piv, j);
    return j;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    if (der > izq) {
        unsigned int pvt = partition(a, izq, der);
        if (pvt > izq) {
            quick_sort_rec(a, izq, pvt - 1);
        }
        quick_sort_rec(a, pvt + 1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    if (length > 0) {
        quick_sort_rec(a, 0, length - 1);
    }
}