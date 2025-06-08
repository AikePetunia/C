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
    int i = 20;
    Node *head = NULL;
    Node *current = NULL;

    for (i = 20; i>= 0; i -= 10) {
        Node *newNode = malloc(sizeof(*newNode));
        newNode->data = i;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

/**
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
    // encontrar último nodo -> crear el nuevo nodo -> attachearlo a los nodos viejos
    if (xs != NULL) { // la lista enlazada no está vacia (pre)
        // avanza de nodo, donde xs es null
        while(xs->next != NULL) {
            xs = xs->next;
        }
        // nuevo nodo
        Node *newNode = malloc(sizeof(Node));
        // valor nuevo
        newNode->data = 88;
        // nuevo final
        newNode->next = NULL;
        // conecto el ultimo nodo con el nuevo
        xs->next = newNode;
    } 
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del append: ");

    show_list(my_list);

    append_example(my_list);

    printf("Lista después del append: ");

    show_list(my_list);

    return 0;
}
