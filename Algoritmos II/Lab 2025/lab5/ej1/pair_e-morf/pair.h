#ifndef _PAIR_H
#define _PAIR_H

typedef struct s_pair_t * pair_t;
typedef int elem;

pair_t pair_new(elem x, elem y);
/*
 * DESC: Creates a new pair with components (x, y)
 *
 */

elem pair_first(pair_t p);
/*
 * DESC: Returns the first component of p
 *
 */

elem pair_second(pair_t p);
/*
 * DESC: Returns the second component of p
 *
 */

pair_t pair_swapped(pair_t p);
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 */

void pair_destroy(pair_t p);
/*
 * DESC: Free memory if its necessary
 *
 */


#endif
