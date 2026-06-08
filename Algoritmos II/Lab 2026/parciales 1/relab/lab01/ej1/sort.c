#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    int j = i;
    while (j > 0 && goes_before(a[j],a[j-1])) {
        printf("-- array dump (before swap) -- \n");
        printf("array before swapping: \n %d", array_dump(a, length));
        swap(a, j - 1, j);
        printf("\n--swapped--\n");
        printf("array swapped: %d \n", array_dump(a, length));
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
    }
}

/*
gcc -Werror -Wall -pedantic -std=c99 sort.c sort_helpers.c array_helpers.c main.c -o main
./main  ../input/example-sorted.in 
*/