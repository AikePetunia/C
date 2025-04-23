#include <stdio.h>
#include <stdlib.h>
#include "k_esimo.h"

int main(void) {
    int a[] = {8, 0, 9, -2, 13};
    int length = 5;
    int k = 1;
    int result;

    result = k_esimo(a, length, k);

    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;
}
