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
