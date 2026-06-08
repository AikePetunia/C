#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct s_pair_t {
    int fst;
    int snd;
};

/*
 * DESC: Creates a new pair with components (x, y)
 *
 */
pair_t pair_new(int x, int y) {
    pair_t p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

/*
 * DESC: Returns the first component of p
 *
 */
int pair_first(pair_t p) {
    return p->fst;
}

/*
 * DESC: Returns the second component of p
 *
 */
int pair_second(pair_t p) {
    return p->snd;
}

/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 */
pair_t pair_swapped(pair_t p) {
    return pair_new(p->snd, p->fst);    
}

/*
 * DESC: Free memory if its necessary
 *
 */
void pair_destroy(pair_t p) {
   free(p);
}

