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
Para calcular posiciones reales de los arreglos circulares:
int real_index = (start + i) % MAX_ELEMS;
Si quieres avanzar, usas (start + n) % MAX_ELEMS.
Si quieres retroceder, usas (start - n + MAX_ELEMS) % MAX_ELEMS
Se juega con el restooo 
7 % 10 = 7      // porque 7 dividido entre 10 da 0, resto 7
9 % 10 = 9
10 % 10 = 0     // porque 10 dividido entre 10 da 1, resto 0
12 % 10 = 2     // 12 dividido entre 10 da 1, resto 2
-1 % 10 = -1    // en C, el módulo de negativos se mantiene negativo
*/

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
    l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH; // if l->start == 0, if we -1 then + max_length = before last pos
    l->elems[l->start] = e;
    l->size++;
    return l;
    // será simple
    /*
    assert(l->size < MAX_LENGTH); // que el tamaño no pase el max_length
    // ir al incio, agregar elemento desde ahí
    for (int i = l->size; i > 0; i--) {
        l->elems[i] = l->elems[i-1];
    } 
    l->elems[0] = e;
    return l; 
    */
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
    int pos = (l->start + l->size) % MAX_LENGTH; 
    l->elems[pos] = e;
    l->size++;
    return l;

    /*
    assert(l->size < MAX_LENGTH);
    l->elems[l->size] = e;   
    l->size++;
    return l;
    */
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
    return l->elems[l->start]; // the head is always the start
    // o if (xs != NULL);
    // return l->data;
    // return l->elems[0];
}

//Removes in-place the first element of list `l`.
list tail(list l) {
    l->start = (l->start + 1) % MAX_LENGTH;
    l->size--;
    return l;

    /*
    assert(l->size > 0);
    for (int i = 1; i < l->size; i++) {
        l->elems[i-1] = l->elems[i];
    }
    l->size--;
    return l;
    */
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
    return l->elems[(l->start + n) % MAX_LENGTH];

    // printf("el numero recibido de n es %d \n", n);
    // printf("el numero a devolver es %d \n", l->elems[n]);
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
    list newList = malloc(sizeof(struct _list));
    newList->size = l->size;
    // normalize the order. Instead of starting at pos 3 for example, we start at 0, making it more easy.
    newList->start = 0;
    for (int i = 0; i < l->size; i++) {
        newList->elems[i] = l->elems[(l->start + i) % MAX_LENGTH];
    }
    return newList;


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
    Element 1: newList->elems[(0 + 1) % 5] = newList->[1] = E
    Element 2: newList->elems[(0 + 2) % 5] = newList->[2] = A
    Element 3: newList->elems[(0 + 3) % 5] = newList->[3] = B
    */

    /*
    list newElem;
    newElem = malloc(sizeof(struct _list));
    int i = 0;
    newElem->size = l->size;
    while(i < l->size) {
        newElem->elems[i] = l->elems[i];
    }
    return newElem;
    */
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

// Deja en l sólo los primeros n elementos, eliminando el resto.
list take(list l, int n) {
    // la funcion sigue siendo igual que sin arreglos circulares
    if (n >= length(l)) {
        return l;
    }
    l->size = n;
    return l;

    /*
    // // me siento rara haciendo que no haya un assert si es más grande n q el length
    if (n >= length(l)) {
        return l;
    }
    l->size = n; // devuelvo el arreglo en el tamaño n
    return l;
    */
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
    assert (n <= l->size);
    for (int i = n; i < l->size; i++) {
        l->elems[i - n] = l->elems[i];
    }
    l->size -= n;
    return l;
    /*
    assert(n <= l->size);
    for (int i = n; i < l->size; i++) {
        l->elems[i - n] = l->elems[i];
    }
    l->size -= n;
    return l;
    */

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
    assert (l->size + l0->size > MAX_LENGTH);
    
    if (l->size == 0 && l0->size > 0) {
        return l0;
    } else {
        return l;
    }

    int i = 0;
    while (i <= l0->size) {
        l->elems[l->size] = l0->elems[i];
        l->size++;
        i++;
    }
    return l;
    /*
    ! el resto de algoritmos no tienen terminaciones tempranas, debería devolver l0 si l == 0 o similares
    assert(l->size + l0->size <= MAX_LENGTH);

    int i = 0;
    while (i <= l0->size) {
        l->elems[l->size] = l0->elems[i];
        l->size++;
        i++;
    }
    return l;
    */

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

/*

usuario@phdsec:~/Development/C/Algoritmos II/Lab/lab5.5/ej6$ gcc -Wall -Wextra -std=c99 list.c tests.c -o tests
usuario@phdsec:~/Development/C/Algoritmos II/Lab/lab5.5/ej6$ ./tests 
TESTING head
Test case 1: OK
Test case 2: OK
Test case 3: OK
TESTING index
Test case 1: OK
Test case 2: OK
Test case 3: OK
TESTING length
Test case 1: OK
Test case 2: OK
Test case 3: OK
Test case 4: OK
usuario@phdsec:~/Development/C/Algoritmos II/Lab/lab5.5/ej6$ gcc -Wall -Wextra -std=c99 list.c tests2.c -o tests
usuario@phdsec:~/Development/C/Algoritmos II/Lab/lab5.5/ej6$ ./tests 
TESTING tail
Test case 1: OK
Test case 2: OK
Test case 3: OK
TESTING addr
Test case 1: OK
Test case 2: OK
Test case 3: OK
Test case 4: OK
TESTING take
Test case 1: OK
Test case 2: OK
Test case 3: OK
Test case 4: OK
Test case 5: OK

*/

