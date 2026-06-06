#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
    int tmp = p->fst;
    p->snd = p->fst;
    p->snd = tmp;
    return p;
}

/*
 * DESC: Free memory if its necessary
 *
 */
void pair_destroy(pair_t p) {
   // assert(p != NULL);
   // free(p);
}
