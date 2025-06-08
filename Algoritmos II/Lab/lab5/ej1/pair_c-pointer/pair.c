#include <stdlib.h>
#include <assert.h>

typedef struct s_pair_t * pair_t; 

struct s_pair_t {
    int fst; 
    int snd; 
}; 

pair_t pair_new(int x, int y){ 
    pair_t p = malloc(sizeof(struct s_pair_t));
    assert(p != NULL);  
    p->fst = x;
    p->snd = y;
    return p;
}
/*
 * DESC: Creates a new pair with components (x, y)
 */

int pair_first(pair_t p){ 
    assert(p != NULL);
    return p->fst;
} 
/*
 * DESC: Returns the first component of p
 */

int pair_second(pair_t p){ 
    assert(p !=NULL);
    return p->snd;
} 
/*
 * DESC: Returns the second component of p
 */

pair_t pair_swapped(pair_t p){ 
    pair_t q = malloc(sizeof(struct s_pair_t));
    q->fst = p->fst; 
    q->snd = p->snd;
    int temp;
    temp = q->fst; // temp = 1
    q->fst = q->snd; // 1 = 2 
    q->snd = temp; // 2 = 1
    return q;
} 
/*
 * DESC: Return a NEW pair with the components of p reversed
 */

void pair_destroy(pair_t p){ 
    assert(p !=NULL);
    free(p);
} 
/*
 * DESC: Free memory if its necessary
 */

