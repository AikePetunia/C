#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef int list_elem;
typedef struct node * list;
// estas funciones son del tipo de la estrucutura de node. (Lista enlazada)

/* constructors */
list empty(); 
// crea una lista vacia

list addl (list l, list_elem e); 
// agrega un element al comienzo de la lista

void destroy (list l);
// liberacion de memoria

/* operations */

bool is_empty(list l);
// devuelve true si l es vacía

list_elem head (list l);
// devuelve el primer elemento de la lsita 
// pre: !is_empty.  

list tail(list l);
//elimina el primer elemento de la lista
// pre: !is_empty

list addr(list l, list_elem e);
// agrega elementos al final de la lista 

int length (list l);
// da el largo de la lista

list concat (list l1, list l0);
// agrega al final de todos los l0 todos los lemenetos de l1 en el mismo orden

list_elem list_index(list l, int n);
// deja en l sólo los primeros n elementos, eliminando el resto

list take(list l, int n);
// toma deja en l solo los primeros n elementos, eliminando el resto 

list drop (list l, int n);
// elimina los prtiermos n elementos de l

list copy_list(list l);

void print_list(list l);

#endif