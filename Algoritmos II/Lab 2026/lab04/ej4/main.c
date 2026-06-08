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
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
 // recorre hasta encontrar el nodo cuyo next es NULL, luego modifica ese nodo.
    while (xs->next != NULL) {
        printf("buscando la ultima parte de coso \n");
        xs = xs->next;
    }
    // finalmente en el ultimo, "extiendo"
    xs->next = malloc(sizeof(Node));
    xs->next->data = 88;
    xs->next->next = NULL;
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


/*
gcc -Wall -Wextra -pedantic -std=c99 main.c -o main
./main 
*/