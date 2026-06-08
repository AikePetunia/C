#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

pair_t pair_new(int x, int y) {
    pair_t p;
    p.fst = x;
    p.snd = y;
    return p;
}

// retorna el primer p
int pair_first(pair_t p) {
     return p.fst;  
}

// retorna el segundo p
int pair_second(pair_t p) {
    return p.snd;
}

// para fst por second
pair_t pair_swapped(pair_t p) {
    int tmp = p.fst;
    p.fst = p.snd;
    p.snd = tmp;
    return p;
}

void pair_destroy(pair_t p) {
    // free(p);
}
