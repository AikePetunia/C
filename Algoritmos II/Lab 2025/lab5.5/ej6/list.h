#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int elem;
typedef struct _list *list;

//
// Constructors
//

/**
 * @brief Creates a new empty list.
 */
list empty();

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l);

//
// Operations
//

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l);

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l);

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l);

/**
 * @brief  Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e);

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l);

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0);

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n);

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n);

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n);

/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l);

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l);

#endif
