#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void swap(fixstring a[], unsigned int i, unsigned int j) {
    fixstring tmp;
    fstring_set(tmp, a[i]); // tmp = a[i]
    fstring_set(a[i], a[j]); // a[i] = a[j]
    fstring_set(a[j], tmp); // a[j] = tmp

}

bool goes_before(fixstring x, fixstring y) {
    printf("\n goes before... with X: %s, and Y: %s", x, y);
    return fstring_less_eq(x, y);
}

bool array_is_sorted(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    printf("array is sorted \n");
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}

