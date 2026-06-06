#include "pair.h"
#include <stdlib.h>
#include <stdio.h>

pair_t pair_new(int x, int y) {
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;
    return p;
}

// retorna el primer p
int pair_first(pair_t p) {
    return p.values[0];
}

// retorna el segundo p
int pair_second(pair_t p) {
    return p.values[1];
}

// para values[0] por second
pair_t pair_swapped(pair_t p) {
    int tmp = p.values[0];
    p.values[0] = p.values[1];
    p.values[1] = tmp;
    return p;
}

void pair_destroy(pair_t p) {
    // free(p);
}
