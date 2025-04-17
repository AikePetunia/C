#include <stdio.h>
#include <stdlib.h>
#include "k_esimo.h"

int main(void) {
    int a[] = {8, 0, 9, -2, 13};
    int length = 5;
    int k = 2;
    int result;

    printf("Arreglo con ejercico no hecho: \n");
    printf("[");
    for(int i = 0; i < length; i++){
        printf("%d, ", a[i]);
    }
    printf("]");
    
    result = k_esimo(a, length, k);
    printf("\n Arreglo con ejercicio hecho: \n");
    printf("[");
    for(int i = 0; i < length; i++){
        printf("%d, ", a[i]);
    }
    printf("]");
    printf("\nVariables usadas:\n");
    printf("Elemento K: %d \n", k);
    printf("Elemento k-esimo intercambiado: %d \n", a[k]);
    printf("Resultado: %i \n", result);
    
    return EXIT_SUCCESS;
}

/* Tests y compilacion:
gcc -Wall -Wextra -pedantic -std=c99 -c k_esimo.c main.c 
gcc -Wall -Wextra -pedantic -std=c99 k_esimo.o main.o -o main
*/