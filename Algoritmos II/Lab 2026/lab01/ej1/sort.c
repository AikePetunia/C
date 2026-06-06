#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    int j = i;
    while ((j>0 && a[j] < a[j-1]))  {
        swap(a, j-1, j);
        j=j-1;
    } 
    
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        printf("--- array iteration: %d --- \n", i);
        printf("Initial array: \n");
        array_dump(a, length);
        printf("Array number taken:\na[%d] (%d) swaps with a[%d] (%d) \n", i, a[i], i-1, a[i-1]);
        printf("swapping...\n");
        insert(a, i, length);
        printf("swapped, result: \n");
        array_dump(a, length);
        printf("--- array interation %d finish --- \n\n", i);
        assert(array_is_sorted(a, i));
    }
}


/*
gcc -Wall -Wextra -pedantic -std=c99 -c array_helpers.c sort.c sort_helpers.c main.c
gcc -Wall -Wextra -pedantic -std=c99 array_helpers.o sort.o sort_helpers.o main.o -o sorter 
./sorter ../input/example-unsorted.in
*/