#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"

void swap(int a[], unsigned int i, unsigned int j) {
    printf("\n-- swap--\n");
    printf("entered swap with value a[%d]: %d \n", i, a[i]);
    printf("entered swap with value a[%d]: %d \n", j, a[j]);
    printf("swapping... \n");
    int tmp = a[i];
    printf("tmp is %d \n", tmp);
    a[i] = a[j];
    a[j] = tmp;
    printf("leaved swap with value a[%d]: %d \n", i, a[i]);
    printf("leaved swap with value a[%d]: %d \n", j, a[j]);
}

bool goes_before(int x, int y) {
    return x <= y;
}

bool array_is_sorted(int array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}
