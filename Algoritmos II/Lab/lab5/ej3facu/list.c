#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct node {
    list_elem elem;
    struct node *next;
};

// Constructors
list empty() {
    list l = NULL;
    return l;
}
list addl(list_elem e, list l) {
    list nl = malloc(sizeof(struct node));
    nl->elem = e;
    nl->next = l;
    return nl;
}

// Destroy
void destroy(list l) {
    while (l != NULL) {
        list temp = l;
        l = l->next;
        free(temp);
    }
}

// Operations
bool is_empty(list l) {
    return l == NULL;
}
list_elem head(list l) {
    return l->elem;
}
list tail(list l) {
    assert(!is_empty(l));
    return l->next;  
}
list addr(list l, list_elem e) {
    list nl = malloc(sizeof(struct node));
    nl->elem = e;
    nl->next = NULL;
    if (l == NULL) return nl;
    list temp = l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nl;
    return l;
}
int length(list l) {
    int cont = 0;
    list temp = l;
    while(temp != NULL) {
        cont++;
        temp = temp->next;
    }
    return cont;
}
list concat(list l0, list l1) {
    list temp = l0;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = l1;
    return l0;
}
list_elem list_index(list l, int n) {
    assert(length(l) > n);
    list temp = l;
    for (int i = 0; i < n; i++) {
        temp = temp->next;
    }
    return temp->elem;
}
list take(list l, int n) {
    if (n <= 0 || l == NULL) return NULL;
    list nl = malloc(sizeof(struct node));
    nl->elem = l->elem;
    nl->next = take(l->next, n-1);
    return nl;
}
list drop(list l, int n) {
    for (int i = 0; i < n; i++) {
        l = l->next;
    }
    return l;
}
list copy_list(list l) {
    if (l == NULL) return NULL;
    list nl = malloc(sizeof(struct node));
    nl->elem = l->elem;
    nl->next = copy_list(l->next);
    return nl;
}

// copy_list sin recursividad:
/*
list copy_list(list l) {
    if (l == NULL) return NULL;
    list nl = malloc(sizeof(struct node));
    nl->elem = l->elem;
    nl->next = NULL;

    list prev = nl;
    list curr = l->next;
    while (curr != NULL) {
        list new_node = malloc(sizeof(struct node));
        new_node->elem = curr->elem;
        new_node->next = NULL;
        prev->next = new_node;
        prev = new_node;
        curr = curr->next;
    }
    return nl;
}
*/

void print_list(list l) {
    printf("[");
    for (list temp = l; temp != NULL; temp = temp->next) {
        printf("%d", temp->elem);
        if (temp->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}