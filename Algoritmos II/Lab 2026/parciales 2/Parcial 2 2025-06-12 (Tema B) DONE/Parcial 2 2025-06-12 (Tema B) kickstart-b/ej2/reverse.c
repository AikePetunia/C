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

list reverse(list l) {
    /*
    Lista original:
    [1]->[2]->[3]->[4]->[5]->NULL
    Lista reversa:
    NULL<-[1]<-[2]<-[3]<-[4]<-[5]
    */
   list new_list = NULL; // Arrancamos con la nueva lista vacía
    list curr = l;        // Puntero para recorrer la lista original

    while (curr != NULL) {
        /* * OPCIÓN 2: Si tenés que alojar la memoria manualmente creando el nodo.
         * (Reemplazá 'struct node' y 'elem' por los nombres reales de tu estructura)
         */
        struct node *new_node = malloc(sizeof(struct _list));
        new_list->data = curr->data; 
        
        // Insertamos el nuevo nodo al principio de la nueva lista
        new_list->next = new_list;
        new_list = new_node;

        // Avanzamos en la lista original (sin modificarla)
        curr = curr->next;
    }

    return new_list;
}

/**
 * @brief Inserts element `e` at index `n`.
 */
list insert_at(list l, elem e, int n) {
    if (n == 0) {
        return addl(e, l); // Reutilizamos tu función
    }

    list aux = l;
    int index = 0;
    
    // Avanzamos hasta el nodo ANTERIOR al lugar de inserción
    while (aux != NULL && index < n - 1) {
        aux = aux->next;
        index++;
    }

    if (aux != NULL) {
        list new_node = malloc(sizeof(struct _list));
        new_node->data = e;
        new_node->next = aux->next; // El nuevo apunta al resto
        aux->next = new_node;       // El anterior apunta al nuevo
    }

    return l;
}

/**
 * @brief Removes element at index `n`.
 */
list remove_at(list l, int n) {
    if (l == NULL) return NULL;

    if (n == 0) {
        return tail(l); // Reutilizamos tu función tail que ya hace free
    }

    list aux = l;
    int index = 0;

    // Avanzamos hasta el nodo ANTERIOR al que queremos borrar
    while (aux != NULL && aux->next != NULL && index < n - 1) {
        aux = aux->next;
        index++;
    }

    // Si encontramos el anterior y el que le sigue (el que queremos borrar) existe
    if (aux != NULL && aux->next != NULL) {
        list to_remove = aux->next;
        aux->next = to_remove->next; // Desenganchamos
        free(to_remove);             // Liberamos
    }

    return l;
}

/**
 * @brief Returns true if element `e` is in the list.
 */
bool contains(list l, elem e) {
    list aux = l;
    while (aux != NULL) {
        if (aux->data == e) {
            return true;
        }
        aux = aux->next;
    }
    return false;
}

/**
 * @brief Returns the number of times `e` appears in the list.
 */
int count_occurrences(list l, elem e) {
    int count = 0;
    list aux = l;
    while (aux != NULL) {
        if (aux->data == e) {
            count++;
        }
        aux = aux->next;
    }
    return count;
}
/**
 * @brief Removes duplicate consecutive or non-consecutive elements.
 */
list remove_duplicates(list l) {
    list curr = l;

    while (curr != NULL) {
        list runner = curr;
        // Comparamos el actual contra el resto de la lista
        while (runner->next != NULL) {
            if (runner->next->data == curr->data) {
                // Encontramos un duplicado, lo desenganchamos
                list duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
    return l;
}

/**
 * @brief Returns true if the list is sorted in ascending order.
 */
bool is_sorted(list l) {
    if (l == NULL || l->next == NULL) {
        return true; // Lista vacía o de 1 elemento está ordenada
    }

    list aux = l;
    while (aux->next != NULL) {
        if (aux->data > aux->next->data) {
            return false; // Si el actual es mayor al siguiente, rompió el orden
        }
        aux = aux->next;
    }
    return true;
}

/**
 * @brief Inserts element `e` in a sorted list maintaining the order.
 */
list insert_sorted(list l, elem e) {
    // Si está vacía o el elemento es menor al primero, va a la cabeza
    if (l == NULL || e < l->data) {
        return addl(e, l);
    }

    list aux = l;
    // Buscamos el nodo anterior a donde debe ir insertado
    while (aux->next != NULL && aux->next->data < e) {
        aux = aux->next;
    }

    list new_node = malloc(sizeof(struct _list));
    new_node->data = e;
    new_node->next = aux->next;
    aux->next = new_node;

    return l;
}
/**
 * @brief Modifies all elements in-place by applying function `f`.
 */
list map(list l, elem (*f)(elem)) {
    list aux = l;
    while (aux != NULL) {
        aux->data = f(aux->data);
        aux = aux->next;
    }
    return l;
}

/**
 * @brief Creates a NEW list with elements that satisfy the predicate `p`.
 */
list filter(list l, bool (*p)(elem)) {
    list new_list = NULL;
    list tail_ptr = NULL; // Usamos un puntero al final para insertar en O(1)
    
    list aux = l;
    while (aux != NULL) {
        if (p(aux->data)) {
            list new_node = malloc(sizeof(struct _list));
            new_node->data = aux->data;
            new_node->next = NULL;

            if (new_list == NULL) {
                new_list = new_node; // Primer elemento
                tail_ptr = new_list;
            } else {
                tail_ptr->next = new_node; // Enganchamos al final
                tail_ptr = new_node;       // Avanzamos el tail
            }
        }
        aux = aux->next;
    }
    return new_list;
}

/**
 * @brief Converts the linked list to a dynamically allocated C array.
 * Note: Returns a pointer to elem (elem*), memory must be freed by caller.
 */
elem* to_array(list l) {
    int len = length(l);
    if (len == 0) return NULL;

    elem* arr = malloc(sizeof(elem) * len);
    list aux = l;
    int i = 0;

    while (aux != NULL) {
        arr[i] = aux->data;
        aux = aux->next;
        i++;
    }

    return arr;
}


/*
A. Pararme EN el índice n (ideal para leer o modificar ese dato):
Avanzás mientras no te caigas de la lista Y mientras tu contador no haya llegado a n.
*/
list aux = l;
int i = 0;

// Avanza hasta llegar a la posición n
while (aux != NULL && i < n) {
    aux = aux->next;
    i++;
}

// Al salir del while, si aux no es NULL, estás parado exactamente en el índice n.

/*
B. Pararme un paso ANTES del índice n (ideal para insertar o borrar en n):
Como vimos antes, para conectar flechas necesitás el nodo anterior. Entonces frenás en n - 1.
*/
list aux = l;
int i = 0;

// Avanza hasta llegar al nodo anterior (n-1)
while (aux != NULL && i < n - 1) {
    aux = aux->next;
    i++;
}

// Al salir, aux está en n-1. Ya podés hacer: aux->next = nuevo_nodo;

//A. Pararme EN el elemento que busco:
//Avanzás mientras no te caigas Y el elemento no sea el que buscás.C

list aux = l;

// Mientras el dato NO sea 99, sigo avanzando
while (aux != NULL && aux->data != 99) {
    aux = aux->next;
}

// Al salir, si aux no es NULL, aux->data es 99 (te frenaste justo encima)

//B. Pararme un paso ANTES del elemento que busco (para borrarlo):
//Acá combinás la técnica del "mirar hacia adelante" con la condición. Mirás si el dato del nodo que sigue es el que buscás.

list aux = l;

// Mientras haya un nodo siguiente Y ese nodo siguiente NO tenga el 99
while (aux != NULL && aux->next != NULL && aux->next->data != 99) {
    aux = aux->next;
}

// Al salir, si aux->next no es NULL, estás un paso antes del 99.
// Ya podés "puentearlo": aux->next = aux->next->next;