#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
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
    list l = malloc(sizeof(struct _list));
    l->size = 0;
    return l;
}

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l) {
    // assert(l != NULL); // valido el nodo
    int i = l->size;
    // hago espacio en la lsita
    while (i > 0) {
        l->elems[i] = l->elems[i - 1];
        i--;
    }
    l->elems[0] = e;
    l->size++;
    return l;
}

//
// Operations
//

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l) {
        // assert(l != NULL); // valido el nodo

    return l->size == 0 ? true : false;
}

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l) {
    return l->elems[0];
}

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l) {
    for (int i = 1; i < l->size; i++) {
        l->elems[i-1] = l->elems[i];
    }
    l->size--;
    return l;
}

/**
 * @brief Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e) {
    // assert(l != NULL); // valido el nodo
    l->elems[l->size] = e;
    l->size++;
    return l;
}

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l) {
    return l->size;
}

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0) {
    // casos base
    if (l->size + l0->size > MAX_LENGTH) {
        return l; // no se puede concat
    }
    // actualizo tamaño de la lista
    l->size += l0->size;

    int i = 0;
    while( i < l->size) {
        l->elems[l->size += i] = l0->elems[i];
        i++;
    }
    return l;
}

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n) {
    assert(n >= 0 && n < l->size);

    int i = 0;
    while ( i < l->size) {
        // printf("\nelemento de l %d", l->elems[i]);
        i++;
    }
    return l->elems[n];
}

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n) {
        if (n >= length(l)) {
        return l;
    }
    l->size = n;
    return l;
}

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n) {
    // assert(l != NULL); // valida nodo

    //casos base
    if (n > l->size) {
        destroy_list(l);
        return NULL;
    }

    if (l->size < n) {
        return l;
    }

    int index = 0;

    // recorre hasta el elemento N
    while (index < n-1) {
        l->elems[index - n] = l->elems[index];
        index++;
    }
    l->size -= n;
    return l;
}

/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l) {
    if (l == NULL) return NULL;
    list copy_list = l;

    return copy_list;
}

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l) {
    free(l);
}



/*

gcc -Wall -Wextra -std=c99 list.c tests.c -o tests
gcc -Wall -Werror -Wextra -pedantic -std=c99 list.o tests.o -o tests
./tests
*/