#include <stdlib.h>
#include <assert.h>

typedef struct s_pair_t pair_t;

struct s_pair_t {
    int values[2];
};

pair_t pair_new(int x, int y) {
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;
    return p;
}
/*
 * DESC: Creates a new pair with components (x, y)
 *
 */

int pair_first(pair_t p) {
    assert(&p != NULL);
    return p.values[0];
}
/*
 * DESC: Returns the first component of p
 *
 */

int pair_second(pair_t p) {
    assert(&p != NULL);
    return p.values[1];
}
/*
 * DESC: Returns the second component of p
 *
 */

pair_t pair_swapped(pair_t p) {
    assert(&p != NULL);
    int tmp;
    tmp = p.values[0];
    p.values[0] = p.values[1];
    p.values[1] = tmp;
    return p;
}
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 */

void pair_destroy(pair_t p) {
    // free(p)
}
/*
 * DESC: Free memory if its necessary
 *
 */
