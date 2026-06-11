#include "list.h"

struct _list {
    elem data;
    struct list *Next;
};

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l) {
    return length(l) == 0;
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
    
    list temp = l; // primer nodo
    list head = l->Next; // segundo nodo

    free(temp); // borro el primer nodo
    temp = NULL; // borro s ref
    return head;
}

/**
 * @brief Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e) {

}

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l) {
    int length = 0;
    // avanzo todos los elementos de la lista
    while (l != NULL) {
        length++;
        l = l->Next;
    }
    return length;
}

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0) {
    // tengo que validar las listas.
    if (l == NULL ) {
        return l;
    }
    if (l0 == NULL) {
        return l0;
    }

    list aux = l;
    // avanzo al ultimo nodo
    while (aux->Next != NULL) {
        aux = aux->Next;
    }

    aux->Next = l0;
    return l;
}

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n) {

}

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n) {

}

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n) {

}

/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l) {
    // copy in-depth
    if (l == NULL)
        return l;

    list new_copy = malloc(sizeof(struct _list));
    list aux = l;
    
    // copio el primer elemento
    new_copy->data = l->data;
    new_copy->Next = NULL;

    while (aux != NULL) {
        new_copy->data = aux->data;
        new_copy->Next = aux;
        aux = aux->Next;
    }

    new_copy->Next = NULL;
    return new_copy;
}

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l) {
    free(l);
    return NULL;
}
