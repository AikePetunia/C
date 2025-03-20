#include <stdio.h>
#include <assert.h>
//Procedimiento intercambio. Similar a variables, pero con elementos de arreglos.

void intercambiar(int tam, int a[], int i, int j) { //Las funciones void NO retornan nada
    // tam es el tamaño maximo del arreglo dado por el user.
    // las dos posiciones que es j e i, cuales se intercambiaran.
    // a es el arreglo.
    if (i < tam && j < tam && i >= 0 && j >= 0) { //veo si me dio posiciones válidas
        int aux = a[i];
        a[i] = a[j];
        a[j] = aux; 
    }
    else {
        printf("Error: Las posiciones deben ser válidas.\n");
    }

}

int main (void) {
    int a[10]; //10 elementos máximos en el arreglo
    int i, j, tam;

    printf("Ingrese la cantidad de elementos que tendrá el arreglo: \n");
    scanf("%d", &tam);

    assert(tam > 0 && tam <= 10 && "\n Error: El tamaño debe ser entre 1 y 10.\n");

    printf("Ingrese elementos al arreglo a:  \n");

    for (int k = 0; k < tam; k++) {
        printf("Elemento %d: ", k);
        scanf("%d", &a[k]);     //este trozo de codigo me lo dio chat gpt pq ni idea como seria, pero otra manera no lo se.
    }
    printf("Ingrese la posicion i para intercambiar \n");
    scanf("%d", &i);
    printf("Ingrese la posicion j para intercambiar \n");
    scanf("%d", &j);

    assert(i >= 0 && i < tam && j >= 0 && j < tam && "Las posiciones deben ser válidas."); //veo si me dio posiciones válidas

    intercambiar(tam, a, i, j); // Pasa los elementos a la funcion intercambiar

    printf("Arreglo después del intercambio: \n");
    for (int k = 0; k < tam; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");
    return 0;
}
