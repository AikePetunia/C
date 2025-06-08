#include <stdio.h>
#include <stdlib.h>
/* 
! linked lists

? what's the difference between, array list and linked list ?
    * array list:
    store elements in a contiguos memory locations
    (first element 0x2, second 0x4, thirth 0x6, etc)
    ! difficult to insert or delete elements, implies moving all elements, etc, etc.asm

    * linked list: 
    self referential structure in c. (Like a recursion)
    composed in a big chain of nodes 
    non-contiguos. 
    no index, but contains a adress to the next node.
    needs to finish with a null.   
    nodes -> 

      Node 1        Node 2        Node 3
    +--------+    +--------+    +--------+
    | Data   |    | Data   |    | Data   |
    | Next --|----→ Next --|----→ Next --|----→ NULL
    +--------+    +--------+    +--------+
*/
// ! Basic structure of a node:
typedef struct Node {
    int data;           // The data (can be any data type)
    struct Node* next;  // Pointer to the next node
} Node;

/*
? how to insert new values?

 -> inserting a new node is changing the direction of the old node to a new node
 -> deleting it's simply changing the next adress
 ! bad at searching, start at the head to the tail. o(n), but making insertion or deletion of node is o(1)
*/

// ! https://pythontutor.com/render.html#mode=edit <- visualizacion de ejecucion 

// Create a Linked list.

// NOTA: Guardar el Head de una lista enlazada, hace que puedas guardar TODA la lista enlazada (pues la referencia queda)
typedef Node *List;

// Lista nelazada de 20 -> 10 -> 0
List setup_example() {
  // Crear → Asignar data → Enlazar al anterior → Avanzar nodo.
  int i = 20;

  Node *head = NULL;     // Puntero al primer nodo de la lista
  Node *current = NULL;  // Puntero auxiliar para construir la lista

  while (i >= 0) {
      Node *newNode = malloc(sizeof(*newNode)); // Reservamos espacio
      newNode->data = i;                        // Asignamos valor
      newNode->next = NULL;                     // Inicialmente apunta a NULL

      if (head == NULL) {
          // Primer nodo (caso base) y solo recae una vez
          head = newNode;       // head apunta al primer nodo
          current = head;       // current también
      } else {
          // Siguientes nodos (caso recursivo)
          current->next = newNode; // Enlazamos
          current = newNode;       // Avanzamos
      }

      i -= 10; // Bajamos de 20 -> 10 -> 0
  }

  return head; // Retornamos la cabeza (inicio de la lista)
}

// appendear nuevos nodos

void append_example(List xs) {
  // encontrar último nodo -> crear el nuevo nodo -> attachearlo a los nodos viejos
  if (xs != NULL) { // pre condicion, la lista enlazada no debe ser vacia
    while(xs->next != NULL) { // el que tenga xs->next == NULL es el tail
      xs = xs->next;
    }

    // ya verificado que estamos en tail:
    Node *newNode =malloc(sizeof(Node));
    
    newNode->data = 88; // asignamos el valor
    newNode->next = NULL;   // ahora es el final "y es el nuevo tail"
  
    xs->next = newNode; // entonces, de los nodos anterior, el ultimo lo contectamos con el nuevo nodo
  }
}

List tail_example(List xs) { // xs es el head del nodo
   // guardar primer nodo -> avanzar el resto de nodos -> liberar el primer nodo guardado
  if (xs != NULL) { // si la lista no está vacía (hay al menos un nodo) (guárdame este nodo que quiero borrarlo, pero antes necesito avanzar)
    Node *temp = xs;     // guardamos una referencia al primer nodo (cabeza)
    xs = xs->next;       // avanzamos xs al segundo nodo (nuevo inicio de la lista)
    free(temp);          // liberamos la memoria del nodo anterior (ya no está conectado)
  }
  return xs; // devolvemos el nuevo inicio de la lista (puede ser NULL si solo había un nodo)
}

// ! NOTE: Most of linked lists requieres a head and current nodes.
// -> When the function ends, you need to return the start of the list
// -> Once you advance Node, you can't go back without starting over

/*
Head pointer - Stays fixed at the beginning of the list

Needed so you can return the entire list later
Never changes during traversal
Current pointer - Moves through the list

Used for operations like connecting new nodes
Gets updated as you build or traverse the list
Helps you keep track of "where you are" in the list
*/

/* 
-> About sizes
*/
typedef int list_elem;
typedef struct node {
    list_elem data;         // int
    struct node *next;
} node; 
typedef struct node * list;


typedef struct node {
    list_elem data;
    struct node *next;
} node; 
typedef struct node * list;  // list is just a pointer type!

list l = malloc(sizeof(struct node));  // Correct for allocating a node. allocates enough memory for a complete node (typically 8-16 bytes)
list l = malloc(sizeof(list));         // Incorrect for allocating a node. only allocates memory for a pointer (typically 4-8 bytes)


/* 
* The difference is:
* sizeof(struct node) gets the size of the actual node structure (with data and next pointer)
* sizeof(list) gets the size of a pointer to a node (because list is defined as struct node *)
*/


/* 
  ? doubly linked list.
  
  * use more memory bc it's two addresses per node (previous, next) 
  * can go backwards and forwards
  
  Basic structure for doubly linked list: 
*/
struct DoubleNode {
    int data;
    struct DoubleNode* next;
    struct DoubleNode* prev;
};
/*
 Basic operations we can implement:
 - insertFront (like push)
 - insertBack (like offer)
 - deleteFront (like pop)
 - deleteBack
 - insertAfter
 - deleteNode
*/
