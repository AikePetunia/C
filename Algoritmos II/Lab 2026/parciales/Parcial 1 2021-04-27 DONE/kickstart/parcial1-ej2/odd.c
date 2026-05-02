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
    bool isOddSorted = true;
    unsigned int i = 0;
    unsigned int j = 0;

    while (i < length) {
        if (is_odd(i)) {
            while(j < length) {
                /*
                si array = [5,1,8,2,3,4]
                bien, al inicio voy a tener
                   1 < 2 {
                    isOddSorted = true
                   }
                    2 < 4 {
                    isOddSorted = true;
                    }

                    */
                if (is_odd(j) && (array[i] > array[j])) {
                    printf("entre al if \n");
                    isOddSorted = false;
                } 
                j++;
            }
        }
        i++;
    }

    printf("is oddSorted?: %d \n", isOddSorted);
    return isOddSorted;
}

int main() {
    printf("testing sz kfoil \n");
    int array[6] = {6,1};
    unsigned int length = 2;
    is_odd_sorted(array, length);
}