#include "reverse.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Devuelve en UNA NUEVA lista el resultado de invertir
 * el orden de los elementos de `l`
 */

struct _list {
    elem data;
    struct _list* next;
};

// se que tengo un l->next y un l->data
list reverse(list l) {
    list newList = empty(); // apunta al nodo que quedo atras (inicialmente no hay nada atras)

    list aux = l;

    while (aux != NULL) {
        // añado por izquierda el ultimo elemento
        newList = addl(aux->data, newList);

        aux = aux->next;
    }

    return newList;
}
