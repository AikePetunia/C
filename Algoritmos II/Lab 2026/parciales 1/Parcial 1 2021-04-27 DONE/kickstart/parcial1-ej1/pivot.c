#include <stdbool.h>

#include "pivot.h"
#include "assert.h"

/** 
 *  @brief returns the correct position of a pivot on a array
 *  @param a[] - Array
 *  @param length - Length of array
 *  @param piv - index of piv to check
 */
bool is_pivot(int array[], unsigned int length, unsigned int piv) {
    assert(piv < length);

    for (unsigned int i = 0; i < piv; ++i) {
        if (array[i] > array[piv]) {
            return false;
        }
    }

    for (unsigned int i = piv + 1; i < length; ++i) {
        if (array[i] <= array[piv]) {
            return false;
        }
    }

    return true;
}

/*
gcc -Werror -Wextra -pedantic -std=c99 pivot.c -o pivot
*/