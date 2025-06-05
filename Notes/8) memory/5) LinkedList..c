#include <stdio.h>

/* 
! linked lists

? what's the difference between, array list and linked list ?
    * array list:
    store elements in a contiguos memory locations
    (first element 0x2, second 0x4, thirth 0x6, etc)
    ! difficult to insert or delete elements, implies moving all elements, etc, etc.asm

    * linked list: 
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
struct Node {
    int data;           // The data (can be any data type)
    struct Node* next;  // Pointer to the next node
};

/*
? how to insert new values?

 -> inserting a new node is changing the direction of the old node to a new node
 -> deleting it's simply changing the next adress
 ! bad at searching, start at the head to the tail. o(n), but making insertion or deletion of node is o(1)
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