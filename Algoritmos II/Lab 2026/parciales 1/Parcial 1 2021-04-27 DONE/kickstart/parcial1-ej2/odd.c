#include <stdbool.h>
#include <stdio.h>
#include "odd.h"

bool is_odd(int number) {
    return(number % 2 == 1);
}

/**
 * @brief checks if odd positions are sorted
 * @param array - Array
 * @param length - Length of array
 * @returns if the odd positions are really sorted
 */
bool is_odd_sorted(int array[], unsigned int length) {
    bool first = true;
    int previous_value = 0;

    for (unsigned int i = 1; i < length; i += 2) {
        if (first) {
            previous_value = array[i];
            first = false;
        } else {
            if (previous_value > array[i]) {
                return false;
            }
            previous_value = array[i];
        }
    }

    return true;
}

int main() {
    printf("testing sz kfoil \n");
    int array[6] = {6,1};
    unsigned int length = 2;
    is_odd_sorted(array, length);
}