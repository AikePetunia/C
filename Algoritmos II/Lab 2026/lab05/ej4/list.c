#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

/**
 * @brief Creates a new empty list.
 */
list empty() {
    list l = malloc(sizeof(struct _list));
    l->size = 0;
    l->start = 0;
    return l;
}

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l) {
    l->start = ((l->start- 1 + MAX_LENGTH) % MAX_LENGTH);
    l->a[l->start] = e;
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
    return l->size == 0 ? true : false;
}

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l) {
    assert(!is_empty(l));
    return l->a[l->start];
}

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l) {
    assert(!is_empty(l));
    l->start = (l->start +1) % MAX_LENGTH;
    l->size--;
    return l;
}

/**
 * @brief Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e) {
    // la ultima posicion del elemento es:
    int pos = (l->start + l->size) % MAX_LENGTH;
    l->a[pos] = e;
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
        l->a[l->size += i] = l0->a[i];
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
    return l->a[(l->start + n) % MAX_LENGTH];
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
        l->a[index - n] = l->a[index];
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
