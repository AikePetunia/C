#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
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
    return l; 
    // si agreguamos un elemento, tenemos que hacer crecer el arreglo
     
    // a lo mejor debería de hacer como una llamada recursiva para correr
    // de lugar los nuevos elementos del arreglo?

    /*
    list nl = malloc(sizeof(struct _list));
    nl->data = e;
    nl->next = l;
    return nl;
    */
}   

list addr(list l, elem e) {
    assert(l->size < MAX_LENGTH);
    l->elems[l->size] = e;   
    l->size++;
    return l;
    /*
    q->data = e;  // guardamos el elemento
    q->next = NULL;
    if (!is_empty(l)) {
        p = l; // apunta al mismo elemento que l
        while (p->next != NULL) { // mientras no estemos en el final
            p = p->next; // iteramos hasta estarlo
        }
        p->next = q; // cuando lo estemos, lo apuntamos a el elemento de e al último nodo
    } else {
        l = q; // no habría elemento q agregar )?
    }
    return l;
    */
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
    /*
    assert(!is_empty(l));
    list p;
    p = l;
    l = l->next;
    free(p);
    return l;    
    */
}


// Devuelve el n-ésimo elemento de la lista l
elem index(list l, int n) {
    assert(n >= 0 && n < l->size);
    // printf("el numero recibido de n es %d \n", n);
    // printf("el numero a devolver es %d \n", l->elems[n]);
    return l->elems[n];
    /*
    // printf("[index] el assert \n");
    assert(length(l) > n);
    // printf("[index] pasado el assert \n");
    list temp = l;              // copia temp de la lista
    for (int i = 0; i < n; i++) {
        // printf("en el bucle for \n");
        temp = temp->next; // mientras no estemos en el index, avanzamos de nodo
    }
    return temp->data; // retornamos el dato en el index
    */
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
    /*
    list current = NULL;
    list head = NULL;

    while (l != NULL) { // mientras no estemos en el final de la lista
        list l2 = malloc(sizeof(struct _list)); // si copio el nodo, tengo espacio para el dato y el siguiente nodo
        l2->data = l->data; // copyes l2 data to l
        l2->next = NULL; // sinces we don't know if it ended, a good practice is to keep the last _list with null
        
        if (head == NULL) { // only with the first case 
            head = l2;      // como ya iteramos por primera vez, sabemos que el nuevo nodo es l2
            current = head; // por que es lo que seguimos
        } else {
            current->next = l2; // el siguiente nodo es un l2 si es que no es null
            current = l2; 
        }
        l = l->next; // advance the new _list
    }    
    return head;
    */
}

// Deja en l sólo los primeros n elementos, eliminando el resto
list take(list l, int n) {
    // me siento rara haciendo que no haya un assert si es más grande n q el leng
    if (n >= length(l)) {
        return l;
    }
    l->size = n; // devuelvo el arreglo en el tamaño n
    return l;
    /*
    if (n >= length(l)) {
        return l;
    } if (n == 0 || l == NULL) {
        destroy_list(l);
        return NULL;
    }
    

    list current = l;
    list original = l;

    for (int i =0; i < n-1; i++) { // encuentro el index del take
        current = current->next;
    }

    // entonces el for saldrá, y cuando salga, separo lo "viejo de lo nuevo".
    list to_remove = current->next;

    //desconecta la lista
    current->next = NULL;

    destroy_list(to_remove); // borramos lo que va después del index de take.
    return original;
    */
}   

// Elimina los primeros n elementos de l
list drop (list l, int n) {
    assert(n <= l->size);
    for (int i = n; i < l->size; i++) {
        l->elems[i - n] = l->elems[i];
    }
    l->size -= n;
    return l;


    /*
    // same logic as take but backwards
    assert (n<=length(l));
    if (n == 0 || l == NULL) {
        destroy_list(l);
        return NULL;
    }
    if (n == length(l)) {
        return l;
    }

    list new_head = l;
    
    // la logica de tomar y llegar a un index es lo mismo
    for (int i = 0; i < n; i++) {
        new_head = new_head->next;
    }

    list temp = l;
    list next = NULL;
    for (int i = 0; i < n; i++) {
        next = temp->next;
        free(temp);
        temp = next;
    }

    return new_head;
    */
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


    /*
    list p, q;
    p = copy_list(l0); // copio pasando la lista
    q = l; // paso q como l
    
    // asi tengo ambas copias:
    // pasa los elementos
    while (q->next != NULL){
        q = q->next;
    }
    // copia el ultimo nodo de q como p
    q->next = p;

    return l;
    */
}
