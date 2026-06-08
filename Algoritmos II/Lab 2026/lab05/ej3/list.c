#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};
//
// Constructors
//

/**
 * @brief Creates a new empty list.
 */
list empty() {
    list l = NULL;
    return l;
}

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l) {
    // assert(l != NULL); // valido el nodo
    // en realidad deberia de crear una lista enlazada?
    // poner como primer elemento eso, y luego concatenarlo
    list newList = malloc(sizeof(struct _list));
    newList->data = e;
    newList->next = l;
    return newList;
}

//
// Operations
//

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l) {
        // assert(l != NULL); // valido el nodo

    return length(l) == 0 ? true : false;
}

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l) {
    
    return l->data;
}

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l) {
    // assert(!is_empty(l));
    // assert(l != NULL); // valido el nodo

    list first = l; // primer element de l
    list new_head = l->next;
    
    // borra y limpia
    free(first); 
    first = NULL;
    return new_head;
}

/**
 * @brief Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e) {
    // assert(l != NULL); // valido el nodo
    list newList = malloc(sizeof(struct _list));
    
    // si está vacia, solo pego el elemento q me llego
    newList->data = e;
    newList->next = NULL;
    if (is_empty(l)) {
        return newList;
    }

    list aux = l;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = newList;
    return l;
}

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l) {
    int lenght = 0;
    while(l != NULL) {
        l = l->next;
        lenght++;
    }
    return lenght;
}

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0) {
    // casos base
    if (l == NULL) {
        return l0;
    }
    if (l0 == NULL) {
        return l;
    }

    // como ninguna lista es vacia, tenog que ir hasta el final de l
    list aux = l; // realizo una copia para no perder refs
    while (aux->next != NULL) {
        aux = aux->next;
    }

    // ya en el final attacheo esto
    aux->next = l0;

    return l;
}

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n) {
    // assert(n < length(l));

    list aux = l;
    int index = 0;

    while(index != n) {
        aux = aux->next; // mueve donde apunta
        index++;
    }

    return aux->data;
}

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n) {
    // assert(l != NULL); // valido nodo

    if (n == 0) {
        destroy_list(l);
        return NULL;
    }
    
    if (length(l) < n) {
        return l;
    }

    list aux = l; // creo aux

    int index = 0;
    // recorre hasta el elemento N
    while (index < n-1) {
        aux = aux->next;
        index++;
    }

    list to_remove = aux->next;
    aux->next = NULL;

    destroy_list(to_remove);
    return l;
}

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n) {
    // assert(l != NULL); // valida nodo

    //casos base
    if (n > length(l)) {
        destroy_list(l);
        return NULL;
    }

    if (length(l) < n) {
        return l;
    }

    list aux = l; // ref
    list aux2 = NULL; // ref2 por q si no borro y pierdo datos de recorrido

    // va dropeando o liberando entre iteraciones?
    while(n > 0 && aux != NULL) {
        aux2 = aux; // guardo el nodo actual para que se borre.
        aux = aux->next;
        free(aux2);
        n--;
    }

    return aux;
}

/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l) {
    if (l == NULL) return NULL;
    list copy_list = l;
    copy_list->data = l->data; // copio el primer elemment
    copy_list->next = NULL;

    // aux recorrido
    list current_orig = l->next;
    list current_copy = copy_list;
    while (current_copy != NULL) {

        list new_node = malloc(sizeof(struct _list));
        new_node->data = current_orig->data;
        new_node->next = NULL;

        // enganchamos el nodo nuevo a la copia
        current_copy->next = new_node;

        current_copy = current_copy->next;
        current_orig = current_orig->next;
    }

    return copy_list;
}

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l) {
    free(l);
}


