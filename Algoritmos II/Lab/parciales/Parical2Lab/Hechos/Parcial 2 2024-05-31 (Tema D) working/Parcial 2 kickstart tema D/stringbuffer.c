#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "stringbuffer.h"

struct s_stringbuffer {
    struct s_node *first;
    struct s_node *last;
    int size; // para string_length que sea o(1)
};

struct s_node {
    char c;
    struct s_node *nextchar;
};

typedef struct s_node * node_t;

// Representation invarian, veryfies if it's a valid string or list
static bool invrep(stringbuffer sb) {
    if (sb == NULL) return false;

    if (sb->first == NULL || sb->last == NULL) {
        return sb->first == NULL && sb->last == NULL && sb->size == 0;
    }

    if (sb->last->nextchar != NULL) return false;

    int count = 1;
    node_t curr = sb->first;
    while (curr != NULL && curr != sb->last) {
        curr = curr->nextchar;
        count++;
    }

    if (curr != sb->last) return false; 
    return count == sb->size;
}


// Creates a single node in dynamic memory with a given char
static node_t create_node(char c) {
    node_t newnode=NULL;    
    newnode = malloc(sizeof(stringbuffer));
    assert(newnode != NULL);
    newnode->c = c;
    newnode->nextchar = NULL;
    assert(newnode!=NULL);
    return newnode;
}


// Destroy a single node
static node_t destroy_node(node_t node) {
    free(node);
    node = NULL;
    assert(node==NULL);
    return node;
}


// Public functions of the Abstract Data Type
stringbuffer stringbuffer_empty(void) {
    stringbuffer sb = malloc(sizeof(struct s_stringbuffer));
    sb->first = NULL;
    sb->last  = NULL;
    // printf("test \n");
    assert(stringbuffer_is_empty(sb));

    return sb;
}


stringbuffer stringbuffer_create(const char *word) {
    assert(word != NULL);
    // creamos nodos, siguiendo los requisitos de como funcionan listas enlazadas
    // ya que tienen un first, "middle" (newnode), last.
    stringbuffer sb = malloc(sizeof(struct s_stringbuffer));
    
    sb->first = NULL;
    sb->last = NULL;
    sb->size = 0;

    node_t newnode = NULL;
    node_t last = NULL;
    int i = 0;

    while (word[i] != '\0') { // los strings terminan en \0
        newnode = malloc(sizeof(struct s_node));
        newnode->c = word[i];
        newnode->nextchar = NULL;

        if (sb->first == NULL) {
            // primer nodo
            sb->first = newnode;
        } else {
            // enlazo con el anterior
            sb->last->nextchar = newnode;
        }

        sb->last = newnode;
        sb->size++;
        i++;
    }

    // assert(invrep(sb) && !stringbuffer_is_empty(sb));
    return sb;
}



bool stringbuffer_is_empty(stringbuffer sb){
    bool isEmpty = false;
    // assert(invrep(sb));
    if ( (sb->first == NULL) && (sb->last == NULL)) {
        isEmpty = true;
    }
    // assert(invrep(sb));
    return sb;
}


stringbuffer stringbuffer_append(stringbuffer sb, const char c) { // o(1)
    sb->last = create_node(c);
    // printf("test1 \n");
    sb->size++;
    return sb;
}


char stringbuffer_char_at(stringbuffer sb, unsigned int index) {
    // assert(invrep(sb) && !stringbuffer_is_empty(sb) && index<stringbuffer_length(sb));
    unsigned pos = 0;
    node_t node = sb->first;
    while(pos < index) {
        node = node->nextchar;
        pos++;
    }
    return node->c;
}

stringbuffer stringbuffer_remove(stringbuffer sb, unsigned int index) {
    node_t curr = sb->first;
    node_t prev = NULL;

    if (index == 0) {
        sb->first = curr->nextchar;
        if (sb->first == NULL) {
            sb->last = NULL;
        }
        destroy_node(curr);
    } else {
        unsigned int pos = 0;
        while (pos < index) {
            prev = curr;
            curr = curr->nextchar;
            pos++;
        }
        prev->nextchar = curr->nextchar;
        if (curr == sb->last) {
            sb->last = prev;
        }
        destroy_node(curr);
    }

    sb->size--;
    return sb;
}



stringbuffer stringbuffer_replace(stringbuffer sb, const char c, unsigned int index) {
    // dado el index,
    // debo de buscar en sb ese index
    // cambiar el char por el c
    assert(invrep(sb) && index < stringbuffer_length(sb));
    unsigned int pos = 0;
    node_t curr = sb->first;

        while (pos < index) {
            curr = curr->nextchar;
            pos++;
        }
        curr->c = c;
    
    // assert(invrep(sb));
    return sb;
}


unsigned int stringbuffer_length(stringbuffer sb) {
    return sb->size;
}


char* stringbuffer_to_string(stringbuffer sb) {
    // assert(invrep(sb));
    char *string = malloc(sizeof(char) * (sb->size + 1));
    node_t curr = sb->first;
    int i = 0;
    while (i != sb->size) {
        // itero en los nodos
        // por cada iteracion, guardo en el indice i de string
        // el sb->first->c
        string[i] = curr->c;
        curr = curr->nextchar;
        i++;
    }
    string[i] = '\0';
    assert(string != NULL);
    return string;
}


void stringbuffer_dump(stringbuffer sb) {
    node_t node = sb->first;
    while (node != NULL) {
        printf("%c", node->c);
        node = node->nextchar;
    }
    printf("\n");
}


stringbuffer stringbuffer_destroy(stringbuffer sb) {
    free (sb);
    sb = NULL;
    assert(sb == NULL);
    return sb;
}
