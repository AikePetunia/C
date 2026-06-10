#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "character/character.h"
#include "pqueue.h"

/* ============================================================================
STRUCTS!
============================================================================ */

struct s_pqueue {
  unsigned int size;
  struct s_node *First;
};

struct s_node {
  Character character;
  float iniciative;
  struct s_node *Next;
};

/* ============================================================================
INVREP
============================================================================ */

static bool
invrep(pqueue q)
{
  bool invCumplido = false;

  // que size tenga la misma cantidad
  unsigned int count = 0;

  // tengo que tener un primer elemento como válido
  struct s_node *cursor = q->First;
  while (cursor != NULL) {
    cursor = cursor->Next;
    count++;
  }

  if (count == q->size) {
    invCumplido = true;
  }

  cursor = q->First; // reinicio el cursor al principio
  while (cursor != NULL)
  {
    if (cursor->iniciative < cursor->Next->iniciative) {
      invCumplido = true;
    }
    cursor = cursor->Next;
  }

  // que decrece
  return invCumplido;
}

/* ============================================================================
NEW
============================================================================ */

pqueue pqueue_empty(void) {
  pqueue q = NULL;
  q = malloc(sizeof(struct s_pqueue));
  q->size = 0;
  q->First = NULL;
  assert(invrep(q) && pqueue_is_empty(q));
  return q;
}

/* ============================================================================
ENQUEUE
============================================================================ */

static float calculate_priority(Character character) {
  int baseInitiative = character_agility(character); // agilidad del personaje
  int isAlive = character_is_alive(character); // 1 vivo, 0 muerto
  float modificator = character_ctype(character) == "Agile" ? 1.5 : character_ctype(character) == "tank" ? 0.8
                                                                                                         : 1;

  float iniciative = baseInitiative * modificator * isAlive;
  return iniciative;
}

static struct s_node *create_node(Character character) {
  struct s_node *new_node = NULL;
  float priority = calculate_priority(character);
  new_node = malloc(sizeof(struct s_node));
  assert(new_node != NULL);

  new_node->character = character_copy(character); // cargo el personaje
  new_node->iniciative = priority; // cargo la prioridad del personaje.
  new_node->Next = NULL;

  return new_node;
}

pqueue pqueue_enqueue(pqueue q, Character character) {
  assert(invrep(q));
  struct s_node *new_node = create_node(character);

  // primer elemento
  if (q->size == 0 || q->First == NULL) {
    q->First = new_node;
  } else if (new_node->iniciative > q->First->iniciative) {
    new_node->next
  }

  // si estoy aca, entonces ya tengo un first.
  struct s_node *cursor = q->First;
  // si encuentro justo un personaje que tiene mas prioridad que el 
  // primero de la lista enlazada, lo encolo de nuevo y borro lo anterior)?
  //caso contrario, solo lo attacheo al next.
  return q;
}

/* ============================================================================
IS EMPTY?
============================================================================ */

bool pqueue_is_empty(pqueue q) {
  bool empty = 0;

  if (q->First->Next == NULL) {
    empty = 1;
  }

  return empty;
}

/* ============================================================================
PEEKS
============================================================================ */

// obtiene el personaje con mayor prioridad
// @returns character
Character pqueue_peek(pqueue q) {
  assert(invrep(q));
  assert(q != NULL);
  assert(q->First != NULL);

  struct s_node *aux = q->First;
  struct s_node *best = aux;
  float maxCharacterPriority = calculate_priority(aux->character);

  while (aux != NULL) {
    float p = calculate_priority(aux->character);
    if (p > maxCharacterPriority) {
      maxCharacterPriority = p;
      best = aux;
    }
    aux = aux->Next;
  }

  return best->character;
}

// @returns character priority
float pqueue_peek_priority(pqueue q) {
  Character characterPriority = pqueue_peek(q);
  int charPeekPriority = calculate_priority(characterPriority);
  return charPeekPriority;
}

/* ============================================================================
SIZE
============================================================================ */

// O(1), si lo haces con while() ya es O(n)
// ademas invrep ya hizo el while y checkeo los tamaños.
unsigned int pqueue_size(pqueue q) {
  assert(invrep(q));
  return q->size;
}

/* ============================================================================
COPY
============================================================================ */

pqueue pqueue_copy(pqueue q) {
  assert(invrep(q));

  // manera 1 (limpia y correcta):
  // creamos una lista vacia y encolamos los elementos originales.
  // manera 2 (chanchita):
  // newQ->size = q->size;
  // newQ->First = q->First; // se copian todos los nodos
  pqueue copy_q = pqueue_empty(); // lista nueva vacia

  struct s_node *cursor = q->First;
  while (cursor != NULL) {
    copy_q = pqueue_enqueue(copy_q, cursor->character);
    cursor = cursor->Next;
  }

  assert(invrep(copy_q));
  return copy_q;
}

/* ============================================================================
DESTROY!
============================================================================ */
static struct s_node *destroy_node(struct s_node *node) {
  assert(node != NULL);
  free(node);
  assert(node == NULL);
  return node;
}

pqueue pqueue_dequeue(pqueue q) {
  assert(invrep(q));
  /*
   * COMPLETAR
   */
  return q;
}

pqueue pqueue_destroy(pqueue q) {
  free(q);
  assert(q == NULL);
  return q;
}
