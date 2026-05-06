#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0) {
        y = x;
    } else {
        y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    absolute(a, res);
    printf("res %d", res);
    return EXIT_SUCCESS;
}

// gcc -Wall -Wextra -pedantic -std=c99 abs1.c -o abs