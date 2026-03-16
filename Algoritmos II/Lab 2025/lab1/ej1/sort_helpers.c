#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], unsigned int i, unsigned int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

bool array_is_sorted(int array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}
