#include <stdio.h>
#include <stdbool.h>

/*
  Structures are used to solve problems where it's necessary to group data of different types.
  They can also be used to handle data that would be difficult to describe with primitive data types.
  
  In C language, the `struct` keyword is used to group different values according to what is needed.
  As an analogy, `structs` are similar to a tuple, where each element is assigned a name for easier reference.

  Defining a `struct`:
  Suppose we want to define a `pair` type to represent an ordered pair. We would use the following instructions:

  struct pair {
      int fst;
      int snd;
  };

  Declaration and initialization of a `struct`:
  To declare a variable of the previously defined structure type and assign values to its fields:

  struct pair dupla;
  ...
  dupla.fst = 3;
  dupla.snd = 2;

  Reading:
  To read the values of the structure we defined:

  ...
  x = dupla.fst;
  y = dupla.snd;

  We can also define the `struct` with `typedef`. This way we avoid having to use `struct pair` for the declaration:

  typedef struct {
      int fst;
      int snd;
  } pair;

  int main(void) {
      pair dupla;
      dupla.fst = 3;
      ...

  Type synonyms:
  The `typedef` statement not only applies to structures but allows defining synonyms for any type (like `type` in Haskell).
  First indicate the original type and then the synonym to be defined:
  
  typedef <old_type> <new_type>;
  
  For example, if you want to define a new `letter` type as a synonym for `char`:
  typedef char letter;
*/

/* Structure definition in C */
struct pair {
    int fst;
    int snd;
};

/* Function to print the values of the structure */
void print_pair(struct pair p) {
    printf("The pair is fst = %d and snd = %d\n", p.fst, p.snd);
}

/* Function to create and return a `pair` structure */
struct pair create_pair(void) {
    struct pair res;
    res.fst = 95;
    res.snd = 44;
    return res;
}

int main(void) {
    /* Declare a variable of type `struct` */
    struct pair p0;

    /* Initialize the fields of the structure */
    p0.fst = 4;
    p0.snd = 45;

    /* Print the values of the structure */
    print_pair(p0);

    /* Print the values of a structure created by `create_pair` */
    print_pair(create_pair());

    return 0;
}
