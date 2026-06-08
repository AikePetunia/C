#include "sorteddeck.h"
#include "card.h"
#include "card_helpers.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <assert.h>

struct s_sdeck {
    /*
     * Completar
     *
     */
    struct s_node *first;
};

struct s_node {
    card c;
    cardcolor_t color;
    struct s_node *next;
};


typedef struct s_node * node_t;

static node_t create_node(card c) {
    /*
     * Completar
     *
     */
}

static node_t destroy_node(node_t node) {
    /*
     * Completar
     *
     */
}


static bool invrep(sdeck deck) {
    bool valid=false;
    /*
     * Completar
     *
     */
    return valid;
}


sdeck sorteddeck_create(void) {
    /*
     * Completar
     *
     */
 }

sdeck sorteddeck_destroy(sdeck deck) {
    /*
     * Completar
     *
     */
}

sdeck sorteddeck_add(sdeck deck, card c) {
    assert(invrep(deck));
    node_t new_node = create_node(c);
    /*
     * Completar
     *
     */
 
    assert(invrep(deck) && !sorteddeck_is_empty(deck));
    return deck;
}

sdeck sorteddeck_remove(sdeck deck, card c) {
    assert(invrep(deck));
    /*
     * Completar
     *
     */
    assert(invrep(deck));
    return deck;
}

sdeck sorteddeck_popfirst(sdeck deck) {
    /*
     * Completar
     *
     */
 }

card sorteddeck_first(sdeck deck) {
    /*
     * Completar
     *
     */
}

unsigned int sorteddeck_size(sdeck deck) {
    /*
     * Completar
     *
     */
}

unsigned int sorteddeck_redcount(sdeck deck) {
    /*
     * Completar
     *
     */
}

unsigned int sorteddeck_blackcount(sdeck deck) {
    /*
     * Completar
     *
     */
}

bool sorteddeck_is_empty(sdeck deck) {
    /*
     * Completar
     *
     */
}


card* sorteddeck_to_array(sdeck deck) {
    /*
     * Completar
     *
     */
}

void sorteddeck_dump(sdeck deck) {
    assert(invrep(deck));
    node_t node = deck->first;
    if (node != NULL) {
        card_dump(node->c);
        while (node->next != NULL) {
            printf(" -> ");
            node = node->next;
            card_dump(node->c);
        }
        printf("\n");
    } else {
        printf("<>\n");
    }
}

