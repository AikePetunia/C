#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

// ambas funciones void, no devuelven nada. (no return)

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /*  
        no implementes partition, ya está implementado en sort_helpers.o
        (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
        v: entre que el doc dice q *no es necesario* y aca dice no implementar...
    */
    
    /*

    * el quick sort, agarra un pivote, ya sea en el inicio, medio o final, 
    * y lo usa para comparar un elemento del anterior (si es que no es <): 
    * "Permutes elements of a[izq..der] and returns pivot such that: - izq <= pivot <= der"
    *\

    * goes before lo usamos una vez dividido el arreglo en izq y derecho.
    * swap, para intercambiar los valores si es q es goes_before da true.
    *\ 

    * quick_sort nos da el arreglo, la parte izquierda, y la parte derecha
    * primero hacemos partition, luego is sorted, goes_before, swap, y asi.
    *\ 

    * es recursivo, se llama a si misma la funcion hasta que este ordenada 
    *   (q se llame hasta q array_is_sorted() de true)
    * 1) caso base
    * 2) llamada de la funcion para recursividad
    *\
    * como hay que checkear dos posiciones (i, j), dos bucles.
    */

    // caso base:
    // los arreglos que tienen 0 o 1 elemento, no hay izq o der:
    // a = {}, a = {0}
    if (izq >= der) {
        return;
    }

    // caso recursivo, donde vuelvo a llamar a la misma funcion.
    // arreglos de tamaño n 
    // a = {1, 2, 3}, a = {3,5}, a = {4,5,6,7,1}

    // llamado recursivo
    unsigned int pivot = partition(a, izq, der); 
    if (pivot > 0 && pivot-1 >= izq) {
        quick_sort_rec(a, izq, pivot-1);  
    }
    quick_sort_rec(a, pivot+1, der);  

    //malas noticias mi gente, tantas funciones al pedo para que partition haga todo, yo para que estudio...

    /*
     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

