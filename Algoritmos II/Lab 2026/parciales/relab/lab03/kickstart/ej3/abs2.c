#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
void absolute(int x, int *y) {
    if (x >= 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---

    absolute(a, &res);
    printf("%d", res);
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

// gcc -Wall -Werror -Wextra -pedantic -std=c99 abs2.c -o abs2