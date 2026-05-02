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
    bool isLeftSideCorrect = true;
    bool isRightSideCorrect = true;

    assert(piv < length);

    unsigned int izq = 0;
    unsigned int der = 0;
    while (izq < piv) {
        if (array[izq] > array[piv]) {
            isLeftSideCorrect = false;
        }
        izq++;
    }

    while (der < piv) {
        if (array[der] <= array[piv]) {
            isRightSideCorrect = false;
        }
        der++;
    }

    return (isLeftSideCorrect && isRightSideCorrect);
}

/*
gcc -Werror -Wextra -pedantic -std=c99 pivot.c -o pivot
*/