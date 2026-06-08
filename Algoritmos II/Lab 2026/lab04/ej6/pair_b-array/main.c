#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    // uso de funciones en vez de campos internos
    printf("(%d, %d)\n", pair_first(p), pair_second(p));
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

/*
gcc -std=c99 -pedantic -Werror -Wall main.c pair.c -o main

intenta acceder a campos nuevos inexistentes, que cambiaron en el tad que teniamos. 
Anteriormente su representacion era distinta, estaba como: 
p.fst, p.snd, que cambiamos en el .h a p.values[1], p.values[2].

No logra el encapsulamiento por que se puede ver el funcionamiento interno de las tad's, ademas de poder hacer
uso de campos internos como p.values[i]
En C, los archivos .h (headers) son el contrato, los botones. Los archivos .c son los engranajes. Si vos ponés los engranajes a la vista en el .h, rompés el encapsulamiento.
*/