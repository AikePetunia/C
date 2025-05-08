#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {

    if (x >= 0) {
        y = x;
    } else if (y >= 0 ) {
        y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;
    res = 0;
    absolute(a, res);
    printf("a: %d, res: %d", a, res);
    return EXIT_SUCCESS;
}

/*
gcc -Wall -Werror -pedantic -std=c99 abs1.c -o abs1
*/