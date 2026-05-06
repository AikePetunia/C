#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (der > izq) {
        unsigned int piv = partition(a, izq, der);
        if (!(izq <= piv) && (piv <= der)) {
            printf("algo salio mal con el piv");
        }
        quick_sort_rec(a, izq, piv - 1);
        quick_sort_rec(a, piv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c main.c 
gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie array_helpers.o sort.o sort_helpers.o main.o -o sorter
*/