#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* 
      Node 1        Node 2        Node 3
    +--------+    +--------+    +--------+
    | Data   |    | Data   |    | Data   |
    | Next --|----→ Next --|----→ Next --|----→ NULL
    +--------+    +--------+    +--------+
*/

typedef Node *List; // define que List apunta al struct de Node

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
/*
entonces, es algo que se crea a partir de un nodo q apunta a otro q apunta a otro
*/
List setup_example() {
    // Crear → Asignar data → Enlazar al anterior → Avanzar nodo.
    int i = 20;
    Node *head = NULL;       // comienzo de la lista
    Node *current = NULL;    // para ir agregando

    for (i = 20; i >= 0; i -= 10) {
        Node *newNode = malloc(sizeof(*newNode));
        newNode->data = i;
        newNode->next = NULL;

        // "caso base"
        if (head == NULL) {
            head = newNode;       // el primer nodo
            current = head;       //  entonces, si se creo un nodo, es el current.
        // "caso recursivo" (repetidos)
        } else {
            current->next = newNode;
            current = newNode;
        }
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
usuario@phdsec:~/Development/C/Algoritmos II/Lab/lab4.5/ej2 create$ gcc -Wall -Wextra -pedantic -std=c99 main.c -o main
usuario@phdsec:~/Development/C/Algoritmos II/Lab/lab4.5/ej2 create$ ./main 
[ 20, 10, 0, ]
*/