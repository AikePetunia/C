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
/*
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
*/

list reverse(list l) {
    /*
    Lista original:
    [1]->[2]->[3]->[4]->[5]->NULL
    Lista reversa:
    NULL<-[1]<-[2]<-[3]<-[4]<-[5]
    */
    list prev = NULL;
    list curr = l; // arranco en cabeza.
    list next_node = NULL; 

    // recorro todos los elementos.
    while (curr != NULL) {
        next_node = curr->next; // guardo la lista
        curr->next = prev; // el siguiente elemento, apunta al null (InviertO la flecha)

        prev = curr; // el anterior ahora va a ser curr
        curr = next_node; // avanzo al nodo al cual cambiar la flecha
    }

    return prev;
}