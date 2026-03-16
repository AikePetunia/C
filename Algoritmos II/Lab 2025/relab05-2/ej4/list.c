#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

// si definimos el struct aca es encapsulamiento
struct _list {
    elem elem;
    struct _list *next;
};

/*
Node 1          Node 2       Node 3
+--------+    +--------+    +--------+
| Data | |    |  Data  |   |   Data  |
| Next --|   ----→ Next  --|----→ Next ----→ NULL
+--------+    +--------+    +--------+
*/

//
// Constructors
//

/*
 * @brief Creates a new empty list.
*/
list empty() {
    list l = malloc(sizeof(struct _list));
    // los nodos empiezan en 0, apuntan al siguiente en null
    l->elem = 0;
    l->next = NULL;
    return l;
};  

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l) {
    // cera un nuevo nodo que lo vinculo con el primer elemento
    list newlist = malloc(sizeof(struct _list)); 
    newlist->elem = e;
    newlist->next = l;
    return newlist;
};

//
// Operations
//

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l) {
    return l == NULL;
};

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l) {
    assert(!(is_empty(l)));
    return l->elem;
};

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l) {
    assert(!is_empty(l));
    // avanza 1 sola vez y elimina el primer nodo
    list temp = l;
    l = l->next;
    free(temp);
    return l;
};

/**
 * @brief  Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e) {
    // creo un nuevo nodo que contenga el elemento
    list newNode = malloc(sizeof(struct _list));
    newNode->elem = e;
    newNode->next = NULL; // por que todos los nodos nuevos terminan en null
    if (!is_empty(l)) {
        list temp = l; // asi avanzo de nodo, y tiene el miusmo comportamiento
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // ya llegado al final, enlazo el nuevo nodo
        temp->next = newNode;
    } else { 
        l = newNode;
    }
    return l;
    // avanzo al ultimo nodo
};

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l) {
    int length = 0;
    list temp;
    while(l->next != NULL) {
        temp = l;
        l = l->next;
        length++;
    }
    return length;
};

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0) {

};

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n) {
    assert(n<length(l));
    // moverse hasta llegar al index deseado
    // por cada vez q me muevo, tengo q checkear si llegue al index
    int i = 0;
    list temp;
    while (i != n) {
        temp = temp->next;
    }
    return temp->elem;
};

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n) {
    // Solo modificamos la lista si n es menor que la longitud
    if (n < length(l)) {
        int i = 0;
        list temp = l;
        
        if (n == 0) {
            // Caso especial: tomar 0 elementos
            destroy_list(l);
            l = empty();
        } else {
            // Avanzar hasta el n-ésimo elemento
            while (i < n - 1) {
                temp = temp->next;
                i++;
            }
            // Destruir el resto y cortar la lista
            destroy_list(temp->next);
            temp->next = NULL;
        }
    }
    // En cualquier otro caso (n >= length), devolvemos la lista sin cambios
    return l;
}

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n) {

};

/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l) {
    /*
    list listCopy = empty();
    while (l != NULL) {
        list temp = l;
        temp = temp->next;
        listCopy = addl(temp->elem, listCopy);
    }
    return listCopy;
    */
};

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l) {
    while (l != NULL) {
        list temp;
        temp = l;
        l = l->next;
        free(temp);
    }
    return l;
};
