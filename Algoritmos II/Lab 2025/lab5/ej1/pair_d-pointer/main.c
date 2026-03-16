#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

// added this for compilation
struct s_pair_t {
    int fst;
    int snd;
};

void show_pair(pair_t p) {
    printf("(%d, %d)\n", p->fst, p->snd);
}

int main(void) { 
    pair_t p, q;

    // Nuevo par p
    p = pair_new(3, 4);

    // Se muestra el par por pantalla
    printf("p = ");
    show_pair(p);

    // Nuevo para q con elementos de p intercambiados
    q = pair_swapped(p);

    // Se vuelve a mostrar p
    printf("p = ");
    show_pair(p);

    // Se muestra q
    printf("q = ");
    show_pair(q);

    // Se destruyen p y q
    pair_destroy(p);
    pair_destroy(q);

    return EXIT_SUCCESS;
}

// sí esta bien que falle por falta del struct que está definido en pair.h
// sí logra el encapsulamiento debido a que el struct se define en main y no en el TAD.