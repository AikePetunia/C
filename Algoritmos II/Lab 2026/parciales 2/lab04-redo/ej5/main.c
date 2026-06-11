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
    List list = malloc(sizeof(struct Node));

    List head = list;
    while (i > 0) {
        head->data = i * 10;
        head->next = malloc(sizeof(Node)); // asigno espacio para el proximo nodo
        head = head->next; // asigno coso
        i--;
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    List temp = xs;
    xs = xs->next; // avazo una pos
    free(temp); // borro la posicion que avancé
    return xs;
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

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
