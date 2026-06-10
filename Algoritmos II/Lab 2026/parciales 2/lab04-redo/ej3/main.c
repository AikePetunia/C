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
    // reservo el nodo
    List head = malloc(sizeof(struct Node));
    if (head == NULL)
        return NULL;

    List current = head;
    while (i > 0)
    {
        // mientras tengamos donde recorrer
        current->data = i * 10;
        current->next = malloc(sizeof(struct Node));
        current = current->next;
        i--;
    }
    current->data = 0;
    current->next = NULL;
    return head;
}

void list_destroy(List head) {
    List current = head;
    while (current != NULL) {
        List next_node = current->next;
        free(current);
        current = next_node;
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

    show_list(my_list);

    list_destroy(my_list);

    return 0;
}
