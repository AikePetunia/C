#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef int elem;

typedef struct _list {
    elem data;         // int
    struct _list *next;
} _list; 

typedef struct _list * list;

// liberacion de memoria
void destroy_list(list l) {
    while (l != NULL) {
        list temp = l;
        l = l->next;
        free(temp);
    } 
}

// Constructors
list empty() {
    list l = NULL;
    return l;
}

bool is_empty(list l) {
    return l == NULL;
}
int length (list l) {
    int length = 0; 
    while (l != NULL) {
        length++;
        l = l->next;
    }
    return length;
}

// agrega un elemento al comienzo de la lista
list addl (elem e, list l)  {
    list nl = malloc(sizeof(struct _list));
    nl->data = e;
    nl->next = l;
    return nl;
}   

list addr(list l, elem e) {
    list p, q = malloc(sizeof(struct _list)); // creamos dos elementos más, uno para aputnar al final y otro para guardar el valor final, para después agregar el elemento
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
}
// agrega elementos al final de la lista 

/* operations */
elem head (list l) {
    assert(!is_empty(l));
    // o if (xs != NULL);
    return l->data;

}
// devuelve el primer elemento de la lsita 
// pre: !is_empty.  

list tail(list l) {
    assert(!is_empty(l));
    list p;
    p = l;
    l = l->next;
    free(p);
    return l;    
}
//elimina el primer elemento de la lista


// Devuelve el n-ésimo elemento de la lista l
elem index(list l, int n) {
    // printf("[index] el assert \n");
    assert(length(l) > n);
    // printf("[index] pasado el assert \n");
    list temp = l;              // copia temp de la lista
    for (int i = 0; i < n; i++) {
        // printf("en el bucle for \n");
        temp = temp->next; // mientras no estemos en el index, avanzamos de nodo
    }
    return temp->data; // retornamos el dato en el index
}

// Copia todos los elementos de l1 en la nueva lista l2 
list copy_list(list l) {
    list current = NULL;
    list head = NULL;

    while (l != NULL) { 
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
}

// Deja en l sólo los primeros n elementos, eliminando el resto
list take(list l, int n) {
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
}   

// Elimina los primeros n elementos de l
list drop (list l, int n) {
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
}

// agrega al final de todos los l todos los lemenetos de l1 en el mismo orden
list concat (list l, list l0) {
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
}

void print_list(list l) {
    printf("[ \n \n");
    while (l != NULL) {
        printf("%d", l->data);
        l = l->next;
    }
    printf("] \n \n");
}

/* 
! borre sin querer el file original de list.c de este directorio
! este archivo es una copia y quiza algun parametro o nombre de funcion este fallado. Pero pasa los tests
! lab 5.5.
 */