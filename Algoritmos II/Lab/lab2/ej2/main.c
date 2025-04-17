#include <stdio.h>
#include <stdlib.h>
#include "cima.h"

int main(void) {
    int a[] = {1, 8, 9, 5, 0, 3} ;
    int length = 6;
    int result;

    result = cima(a, length);

    printf("\nArreglo con ejercicio hecho: \n");
    printf("[");
    for(int i = 0; i < length; i++){
        printf("%d, ", a[i]);
    }
    printf("]");
    printf("\nVariables usadas:\n");
    printf("length: %d \n", length);
    printf("Resultado: %d \n", result); 
    
    return EXIT_SUCCESS;
}

/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c cima.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 cima.o main.o -o main
./main
*/