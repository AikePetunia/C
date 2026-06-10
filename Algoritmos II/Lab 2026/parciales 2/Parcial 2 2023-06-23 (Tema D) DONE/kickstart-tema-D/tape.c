#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "tape.h"


struct _s_tape {
    unsigned int size;
    struct _s_node *cursor;  // Puntero al elemento actual
    struct _s_node *start;   // Puntero al primer nodo de la cinta
};


typedef struct _s_node * node_t;

struct _s_node {
    tape_elem elem;
    struct _s_node *next;
};

static bool invrep(tape_t tape) {
    struct _s_node *elem = tape->start;
    bool inv = false;
    unsigned int size = 0;

    // recorro todos los elementos de tape.
    while (elem != NULL) {
        size++;
        elem = elem->next;
    }

    // si tienen el mismo tamaño, entonces, esta bien dado el dato.
    if (tape->size == size) {
        inv = true;
    }

    return inv;
}

static node_t create_node(tape_elem e) {
    struct _s_node *newNode = malloc(sizeof(struct _s_node));
    newNode->elem = e;
    newNode->next = NULL;
    return newNode;
}

static node_t destroy_node(node_t node) {
    free(node);
    return NULL;
}

tape_t tape_create(void) {
    tape_t tape= malloc(sizeof(struct _s_tape));
    tape->start = NULL;
    tape->cursor = NULL;
    tape->size = 0;
    assert(invrep(tape) && tape_is_empty(tape) && tape_at_start(tape));
    return tape;
}

tape_t tape_rewind(tape_t tape) {
    // Set the cursor on the first element of the tape
    assert(invrep(tape));
    tape->cursor = tape->start;
    assert(tape_at_start(tape));
    return tape;
}

bool tape_at_start(tape_t tape) {
    // se que estoy al inicio, si se que el segundo elemento es null.
    return (tape->start == tape->cursor);
}

bool tape_at_stop(tape_t tape) {
   return (tape->cursor == NULL);
}

bool tape_is_empty(tape_t tape) {
    return (tape->size == 0);
}

unsigned int tape_length(tape_t tape) {
    return tape->size;
}

tape_t tape_step(tape_t tape) {
    assert(invrep(tape) && !tape_at_stop(tape));

    tape->cursor = tape->cursor->next;
    return tape;
}

tape_t tape_insertl(tape_t tape, tape_elem e) {
    assert(invrep(tape));
    node_t new_node = create_node(e); // tengo el nuevo elemento, y este nuevo apunta a null.
    
    // caso 1: La cinta está vacia.
    if (tape->start == NULL) {
        tape->start = new_node;
        tape->cursor = new_node;
    }    // caso 2:el cursor está en el mismo lugar del comienzo.
    else if (tape->cursor == tape->start) {
        new_node->next = tape->cursor;
        tape->start = new_node;
        tape->cursor = new_node;
    } else {
        // creo un explorador.
        /*
        prev, tiene la funcion de buscar el nodo anterior que se tiene
        que modificar. Entonces, cuando inserte el nodo, el anterior apunta al
        nuevo nodo, y el nuevo nodo al que le seguia del viejo nodo. 
        */

        node_t prev = tape->start;

        // voy hasta el cursor a cambiar
        while(prev->next != tape->cursor) {
            prev = prev->next;
        }

        new_node->next = tape->cursor;
        prev->next = new_node; // el anterior al cursor, apunta al nuevo nodo
        tape->cursor = new_node;
        }

        tape->size++;
    assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape) && e == tape_read(tape));
    return tape;
}

tape_t tape_insertr(tape_t tape, tape_elem e) {
    assert(invrep(tape) && (!tape_at_stop(tape) || tape_is_empty(tape)));
    node_t new_node=create_node(e);
    if (tape->start!= NULL) {
        new_node->next = tape->cursor->next;
        tape->cursor->next = new_node;
        tape->cursor = new_node;
    } else {
        tape->start = new_node;
        tape->cursor = new_node;
    }
    tape->size++;
    assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape) && e == tape_read(tape));
    return tape;
}

tape_t tape_erase(tape_t tape) {
    // borra una cinta
    assert(!tape_is_empty(tape) && !tape_at_stop(tape));
    node_t tapeErase = tape->cursor;

    // 1. el primer elemento está el cursor y start. sea 1 o 1000
    if (tape->cursor == tape->start) {
        tape->start = tapeErase->next;
        tape->cursor = tapeErase->next;
    } else { // el cursor esta por ahi
        
        // me dirijo hasta el cursor
        node_t prev = tape->start;
        while (prev->next != tape->cursor) {
            prev = prev->next;
        }
        // prev ya esta en la posicion anterior al cursor.
        // hago un "puente"
        prev->next = tapeErase->next;
        tape->cursor = tapeErase->next;
    }
    // borra el nodo de la memoria y saca el tamaño
    free(tapeErase);
    tape->size--;
    return tape;
}

tape_elem tape_read(tape_t tape) {
    assert(!tape_is_empty(tape) && !tape_at_stop(tape));
    return (tape->cursor->elem);
}

void tape_dump(tape_t tape) {
    assert(invrep(tape));
    node_t node=tape->start;
    printf("#");
    while (node != NULL) {
        if (node != tape->cursor) {
            printf("-%c-", node->elem);
        } else {
            printf("-[%c]-", node->elem);
        }
        node = node->next;
    }
    if (tape->cursor==NULL) {
        printf("-[]-");
    }
    printf("#\n");
}

tape_t tape_copy(tape_t tape) {
    assert(invrep(tape));
    tape_t copyTape = tape_create();

    node_t old_node = tape->start;
    node_t last_added = NULL; 

    // copia limpia
    while (old_node != NULL) {
        node_t new_node =create_node(old_node->elem);

        // le doy un inicio a la copia
        if (copyTape->start == NULL) {
            copyTape->start = new_node;  // Lo engancho a la locomotora
        } else {
            // Ya hay vagones. Lo engancho al último que agregué.
            last_added->next = new_node; 
        }

        last_added = new_node;

        if (old_node == tape->cursor) {
            copyTape->cursor = new_node;
        }


        old_node = old_node->next;
    }

    copyTape->size = tape->size;

    assert(invrep(copyTape));

    return copyTape;
}

tape_t tape_destroy(tape_t tape) {
    node_t curr = tape->start;
    while (curr != NULL) {
        node_t killme = curr;    // 1. Marco al condenado
        curr = curr->next;       // 2. Salto a un lugar seguro (el siguiente vagón)
        destroy_node(killme);    // 3. mato al condenado
    }
    free(tape);
    return NULL;
}
