#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef struct s_pair_t pair_t;

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y) {
    pair_t p;
    p.fst = x;
    p.snd = y;
    return p;
}
/*
 * DESC: Creates a new pair with components (x, y)
 */

int pair_first(pair_t p) {
    assert(&p != NULL);
    return p.fst;
}
/*
 * DESC: Returns the first component of p
 */


int pair_second(pair_t p) {
    assert(&p != NULL);
    return p.snd;
}
/*
 * DESC: Returns the second component of p
 */

pair_t pair_swapped(pair_t p) {
    int temp;
    temp = p.fst;
    p.fst = p.snd;
    p.snd = temp;
    return p;
}
/*
 * DESC: Return a NEW pair with the components of p reversed
 */

void pair_destroy(pair_t p) {
    // free(p);
}
/*
 * DESC: Free memory if its necessary
 */
