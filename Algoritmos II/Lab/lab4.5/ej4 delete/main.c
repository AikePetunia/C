#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */

List setup_example() {
   // crear -> asignar -> enlazar anterior -> avanzar nodo
   int i = 20;
   Node *Head = malloc(sizeof(*Head)); // iniciamos el primer nodo con el tamaño adecuado
   Node *head = NULL;       // los punteros se inicializan en null si no tienen asignacion inmediata
   Node *current = NULL;    // para ir agregando (Nodo auxiliar)

   while (i<=20 && i>= 0) {
        Node *newNode = malloc(sizeof(*newNode)); // para los nuevos nodos 
        newNode->data = i;                        // i dato
        newNode->next = NULL;                     // asign

        if (head == NULL) {
            head = newNode;                         // primer nodo
            current = head;                         // entonces, si se creo un nodo, es el current.
        } else {
            // resto de nodos
            current->next = newNode;
            current = newNode;
        }
            i -= 10;
   }

   Head->next = NULL;
   return head;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    // guardar -> avanzar -> liberar
   if (xs != NULL) {    
    Node *temp  = xs; // guardo el primer nodo (lo que apunta xs ahora)
    xs = (xs)->next; // avanzo al segundo nodo
        free(temp); // libero el primer nodo 
   }
   return xs; // devuelvo el nuevo inicio de la lista
}

void show_list(List xs) { 
    printf("[ "); 
    while (xs != NULL) { // la pre condincion está a ca
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
