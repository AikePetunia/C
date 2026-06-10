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
    int i = 3;
    // preparo la lista
    List list = malloc(sizeof(struct Node));

    List head = list; // con el que voy a recorrer y el primer nodo.
    i--;

    while (i > 0)
    {
        head->data = i * 10; // pongo dato
        head->next = malloc(sizeof(struct Node));// asigno memoria
        head = head->next; // avanzo
        i--;
    }

    head->data = 0;
    head->next = NULL;
    return list;
}

/**
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
    List aux = xs;
    while(aux->next != NULL) { // me voy al final
        aux = aux->next;
    }
    aux->next = malloc(sizeof(struct Node));
    aux->next->data = 88;
    aux->next->next = NULL;
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
