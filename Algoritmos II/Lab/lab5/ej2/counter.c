#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    // printf("counter_init llamado");
    counter c = malloc(sizeof(struct _counter));
    assert(c != NULL);
    c->count = 0;
    return c;
}

void counter_inc(counter c) {
    // printf("counter_inc llamado");
    c->count+= 1;
}

/* operations*/
bool counter_is_init(counter c) {
    assert(c != NULL);
    return c->count == 0; 
}

void counter_dec(counter c) {
    // printf("counter_dec llamado");
    c->count-= 1;
}


counter counter_copy(counter c) {
    // printf("counter_copy llamado");
    assert(c != NULL);
    counter d = malloc(sizeof(struct _counter)); 
    d->count = c->count;
    return d;   
}

void counter_destroy(counter c) {
    // printf("counter_destroy llamado");
    free(c);
}
