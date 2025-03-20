#include <stdio.h>
#include <stdbool.h>

/*
  Las estructuras son utilizadas en la solución de algunos problemas donde es necesario agrupar datos de diferentes tipos. 
  También pueden ser utilizadas para manejar datos que serían muy difíciles de describir con los tipos de datos primitivos.
  
  En el lenguaje "C" se utiliza el comando `struct` para agrupar diferentes valores de acuerdo a lo que se necesite.
  Para hacer una analogía, las `structs` se parecen a una tupla, donde a cada elemento le asigno un nombre, para luego poder referirme a él más fácilmente.

  Definiendo un `struct`:
  Supongamos que queremos definir un tipo `par` para poder representar un par ordenado. Deberíamos utilizar las siguientes instrucciones:

  struct par {
      int fst;
      int snd;
  };

  Declaración e inicialización de un `struct`:
  Para declarar una variable que tenga el tipo de la estructura definida previamente y poder asignarle algún valor a los campos se procede como sigue:

  struct par dupla;
  ...
  dupla.fst = 3;
  dupla.snd = 2;

  Lectura:
  Para leer los valores de la estructura que definimos:

  ...
  x = dupla.fst;
  y = dupla.snd;

  También podemos escribir el `struct` asociado con `typedef`. De esta manera evitamos tener que usar `struct par` para la declaración, como sigue:

  typedef struct {
      int fst;
      int snd;
  } par;

  int main(void) {
      par dupla;
      dupla.fst = 3;
      ...

  Sinónimo de tipos:
  La sentencia `typedef` no solo se aplica a estructuras sino que permite definir sinónimos para cualquier tipo (igual que `type` en Haskell).
  Se debe indicar primero el tipo original y luego el sinónimo que se va a definir:
  
  typedef <tipo_viejo> <tipo_nuevo>;
  
  Por ejemplo, si se quiere definir un nuevo tipo `letra` como un sinónimo de `char`:
  typedef char letra;
*/

/* Definición de la estructura en C */
struct par {
    int fst;
    int snd;
};

/* Función para imprimir los valores de la estructura */
void imprime_par(struct par p) {
    printf("El par es fst = %d y snd = %d\n", p.fst, p.snd);
}

/* Función para crear y devolver una estructura `par` */
struct par inventa_par(void) {
    struct par res;
    res.fst = 95;
    res.snd = 44;
    return res;
}

int main(void) {
    /* Declaro la variable del tipo `struct` */
    struct par p0;

    /* Inicializo los campos de la estructura */
    p0.fst = 4;
    p0.snd = 45;

    /* Imprimo los valores de la estructura */
    imprime_par(p0);

    /* Imprimo los valores de una estructura creada por `inventa_par` */
    imprime_par(inventa_par());

    return 0;
}
