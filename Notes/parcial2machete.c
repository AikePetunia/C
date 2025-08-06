/*
-> Encapsulamiento: 
básicamente que el header tenga un puntero al structu de el tad, pudiendo no modificar nunca el struct interno del tad
con el cual se necesita operar. 
*/

// ! LISTAS
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

/*
-> list.h

#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int elem;
typedef struct _list *list;

#endif

*/
#include <stdio.h>

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH]; // arreglo de tamaño MAX_LENGTH
    int size;               // cantidad de elementos válidos
};

// liberacion de memoria
void destroy_list(list l) {
    free(l);
}

// Constructors
list empty() {
    list l = malloc(sizeof(struct _list));
    l->size = 0;
    return l;
}
bool is_empty(list l) {
    l->size = 0;
    return l; 
}

int length (list l) {
    return l->size;
}

// agrega un elemento al comienzo de la lista
list addl (elem e, list l)  {
    assert(l->size < MAX_LENGTH); // que el tamaño no pase el max_length
    // ir al incio, agregar elemento desde ahí
    for (int i = l->size; i > 0; i--) {
        l->elems[i] = l->elems[i-1];
    } 
    l->elems[0] = e;
    l->size++;
}   

list addr(list l, elem e) {
    assert(l->size < MAX_LENGTH);
    l->elems[l->size] = e;   
    l->size++;
    return l;
}
// agrega elementos al final de la lista 

/* operations */
elem head (list l) {
    // o if (xs != NULL);
    // return l->data;
    return l->elems[0];
}

//Removes in-place the first element of list `l`.
list tail(list l) {
    assert(l->size > 0);
    for (int i = 1; i < l->size; i++) {
        l->elems[i-1] = l->elems[i];
    }
    l->size--;
    return l;
}


// Devuelve el n-ésimo elemento de la lista l
elem index(list l, int n) {
    assert(n >= 0 && n < l->size);
    return l->elems[n];
}

// Copia todos los elementos de l1 en la nueva lista l2 
list copy_list(list l) {
    list newElem;
    newElem = malloc(sizeof(struct _list));
    int i = 0;
    newElem->size = l->size;
    while(i < l->size) {
        newElem->elems[i] = l->elems[i];
    }
    return newElem;
}

// Deja en l sólo los primeros n elementos, eliminando el resto
list take(list l, int n) {
    // me siento rara haciendo que no haya un assert si es más grande n q el leng
    if (n >= length(l)) {
        return l;
    }
    l->size = n; // devuelvo el arreglo en el tamaño n
    return l;
}   

// Elimina los primeros n elementos de l
list drop (list l, int n) {
    assert(n <= l->size);
    for (int i = n; i < l->size; i++) {
        l->elems[i - n] = l->elems[i];
    }
    l->size -= n;
    return l;
}

// agrega al final de todos los l todos los lemenetos de l0 en el mismo orden
list concat (list l, list l0) {
    assert(l->size <= MAX_LENGTH);
    assert(l0->size <= MAX_LENGTH);
    assert(l->size + l0->size <= MAX_LENGTH);

    int i = 0;
    while (i <= l0->size) {
        l->elems[l->size] = l0->elems[i];
        l->size++;
        i++;
    }
    return l;


  
}

// ! COLAS

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {   // principal queue
    struct s_node *front;      // inicio de la cola (puntero al primer nodo)
    unsigned int size;         // cantidad de elementos (para que sea O(1))
};

struct s_node {
    pqueue_elem elem;          // el dato que se guarda
    unsigned int priority;     // su prioridad
    struct s_node *next;       // puntero al siguiente nodo
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(*new_node)); // uso puntero por que se inicializo el tipo de struct ^ 
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->priority = priority;
    new_node->next = NULL; 
    // // assert(e==e && priority == priority); // BORRAR ESTE ASSERT
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pqueue q) {
    bool isValid = true;
    if (q == NULL || (q->front == NULL && q->size == 0)) {
        isValid = false;
    }

    // // assert(q==q); // BORRAR ESTE ASSERT
    return isValid;
}

pqueue pqueue_empty(void) {
    pqueue q = malloc(sizeof(struct s_pqueue)); 
    q->size = 0;
    q->front = NULL; 
    return q;
}
pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
     // assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    // "caso base"
    if (q->front == NULL) { // fifo
        q->front = new_node;
    } else if (priority < q->front->priority) {
        new_node->next = q->front;
        q->front       = new_node;
    } else {
         // para ver donde meter el nodo nuevo en la cola, debo de ver el anteriror y posterior
        // apuntan a algo asi no tenes segmentation_fault
        struct s_node *prev = q->front;     // para ver el nodo de enfrente
        struct s_node *current = q->front->next;  // para ver el nodo de atras

        while (current != NULL && current->priority <= priority) {
            prev = current;
            current = current->next;
        }
        // una vez ya encontrado la prioridad, debo de colocarla entre nodos
        // tener en cuenta el fifo
        // engancho entre el prev y current el nuevo nodo-
        prev->next    = new_node;
        new_node->next = current;
    }
    // // assert(e==e && priority==priority && new_node==new_node); // BORRAR ESTE ASSERT
    q->size++; // por que se agrega un nodo más
    return q;
}

bool pqueue_is_empty(pqueue q) {
    // // assert(q==q); // BORRAR ESTE ASSERT
    return (q->front == NULL);
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(!pqueue_is_empty(q));
    // // assert(q==q); // BORRAR ESTE ASSERT
    return q->front->elem;
}

unsigned int pqueue_peek_priority(pqueue q) {
    assert(!pqueue_is_empty(q));
    // sabemos que las prioridadees van del orden p1<p2<p3...<pn
    // recorre todos los nodos en busca de la mayor prioridad
    // // assert(q==q); // BORRAR ESTE ASSERT
    return q->front->priority;
}

unsigned int pqueue_size(pqueue q) {
     // assert(invrep(q));
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    // se crea un nodo temporal para borrar y no romper nada
    struct s_node *node_to_destroy = q->front; 
    q->front = q->front->next; // como se borra el primer nodo, el nuevo primer nodo es el siguiente
    destroy_node(node_to_destroy);
    q->size--;
    // //assert(q==q); // BORRAR ESTE ASSERT
    return q;
}

pqueue pqueue_destroy(pqueue q) {
     // assert(invrep(q));
    free(q);
q = NULL;
    assert(q == NULL);
    return q;
}

// ! ARREGLOS CIRCULARES FUNCIONES

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

};

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l) {
    free(l);
};
