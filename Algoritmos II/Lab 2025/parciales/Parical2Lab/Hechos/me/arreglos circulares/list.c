#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int start;
    int size;
};

/*
Ejemplo de arreglo circular:
MAX_ELEMS = 10          // capacidad del arreglo
start = 7               // empieza en la posición 7
size = 5                // 5 elementos ocupados de 10

Representación visual:
Índices:  0   1   2   3   4   5   6   7   8   9   
Elementos:[34][4][ ][ ][ ][ ][ ][8][1][2]
                                ^inicio

Los elementos lógicos son: [8, 1, 2, 34, 4]

Fórmulas para arreglos circulares:
- Para calcular posiciones reales: (start + i) % MAX_ELEMS
- Para avanzar: (start + n) % MAX_ELEMS  
- Para retroceder: (start - n + MAX_ELEMS) % MAX_ELEMS

Ejemplos del operador módulo (%):
7 % 10 = 7      // 7 dividido entre 10 = 0, resto 7
9 % 10 = 9      // 9 dividido entre 10 = 0, resto 9  
10 % 10 = 0     // 10 dividido entre 10 = 1, resto 0
12 % 10 = 2     // 12 dividido entre 10 = 1, resto 2
-1 % 10 = -1    // En C, el módulo de negativos mantiene el signo negativo

IMPORTANTE: Para evitar módulos negativos al retroceder, 
siempre sumamos MAX_ELEMS antes de aplicar el módulo:
(posicion - n + MAX_ELEMS) % MAX_ELEMS
*/

/**
 * @brief Creates a new empty list.
 */
list empty() {
  list l = malloc(sizeof(struct _list));
  l->size = 0;
    l->start = 0;
  return l;
};

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l) {
  // falta caso base
  l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH;
  l->elems[l->start] = e;  
  l->size++;              
  return l;
};

//
// Operations
//

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l) {
  return l->size == 0;
};

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l) {
  return l->elems[l->start];
};

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l) {
  assert(!is_empty(l));
  l->start = (l->start + 1) % MAX_LENGTH;
  l->size--;
  return l;
};

/**
 * @brief  Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e) {
  l->elems[(l->size + 1) % MAX_LENGTH] = e; 
  l->size++;
  return l;
};

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l) {
  return l->size;
};

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0) {
  // la ultima posicion de l es la de l->size
  // entonces, debo empezar a concatenar de ahí. 
  // el size también incrementa

  // casos bases
  if (l->size == 0 && l0->size > 0) {
    return l0;
  } else {
      return l;
  }

  int i = 0;
  while (i <= l0->size) {
      // se copia en la ultima posicion (q se incrementara) el primer elem
      l->elems[l->size] = l0->elems[i];
      l->size++;
      i++;
  }
  return l;
};

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n) {
  return l->elems[(l->start +n) % MAX_LENGTH];
};

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n) {
  // "caso base"
  if (n >= length(l)) { // si lo que tomamos es más grande, entonces devolvemos todo
     return l;
  } 
  l->size = n; // si no reducimos su tamaño a n
  return l;
};

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n) {
  if (n >= length(l)) { // 'caso base'
      l->size = 0;
  } else {  
      // el comienzo del arreglo se cambia por una cuestion de que, 
      // si lo dejamos como esta y sacamos elementos, no hay donde empezar
      l->start = (l->start + n) % MAX_LENGTH; 
      l->size = l->size - n;
  }
  return l;
}

/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l) {
  list newList = malloc(sizeof(struct _list));
  newList->size = l->size;
  // normalize the order. Instead of starting at pos 3 for example, we start at 0, making it more easy.
  int i = 0;
  newList->start = 0; // ! LOOK BELOW
  while (newList->size != l->size) {
    // copia el elemento, aparit del comienzo de la otra lista
    newList->elems[i] = l->elems[(l->start + i) % MAX_LENGTH]; 
  }
   /* 
    -> original
    MAX_LENGTH = 5
    l->elems = [A, B, C, D, E]
    l->start = 3
    l->size = 4
    Element 0: l->elems[(3+0)%5] = l->elems[3] = D
    Element 1: l->elems[(3+1)%5] = l->elems[4] = E
    Element 2: l->elems[(3+2)%5] = l->elems[0] = A
    Element 3: l->elems[(3+3)%5] = l->elems[1] = B

    -> copy
    newList->start = 0
    newList->size = 4
    newList->start = 0

    Element 0: newList->elems[(0 + 0 )% 5] = newList->elems[0] = D
    Element 1: newList->elems[(0 + 1) % 5] = newList->elems[1] = E
    Element 2: newList->elems[(0 + 2) % 5] = newList->elems[2] = A
    Element 3: newList->elems[(0 + 3) % 5] = newList->elems[3] = B
    */
  return newList;
};

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l) {
    free(l);
};
