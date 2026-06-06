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
    List head = malloc(sizeof(Node));
    if (head == NULL)
        return NULL;

    List current = head;
    while (i > 0)
    {
        // mientras tengamos donde recorrer
        current->data = i * 10;
        if (i > 1) {
            current->next = malloc(sizeof(Node));
            if (current->next == NULL)
                return NULL;
            current = current->next;
        } else {
            current->next = NULL;
        }
        i--;
    }
    return head;
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

    return 0;
}

/*
gcc -Wall -Wextra -pedantic -std=c99 main.c -o main 
./main
*/

