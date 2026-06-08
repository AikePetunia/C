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
    int i = 2;
    List head = malloc(sizeof(Node));
    if (head == NULL)
        return NULL;

    List current = head;

    while (i > 0) {
        current->data = i * 10;
        current->next = malloc(sizeof(Node));
            current= current->next ;
            i--;
    }
    current->data = 0;
    current->next = NULL;
    current = NULL;
    return head;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    if (xs == NULL) {
        return NULL; 
    }
    List first = xs; // primer elemento en lista enlazada (xs), el de eliminar
    List new_head = xs->next; // nueva cabeza
    free(first); // borra la cabeza vieja 
    first = NULL; // "limpia"
    return new_head;
}

/*

gcc -Wall -Wextra -pedantic -std=c99 main.c -o main 
./main 
*/

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

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
