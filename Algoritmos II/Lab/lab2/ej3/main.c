#include <stdio.h>
#include <stdlib.h>
#include "cima_log.h"

int main(void) {
    int a[] = {-2, 8, 9, 5, 0};
    int length = 5;
    int result;

    result = cima_log(a, length);

    printf("\nArreglo con ejercicio hecho: \n");
    printf("[");
    for(int i = 0; i < length; i++){
        printf("%d, ", a[i]);
    }
    printf("] \n");
    printf("Resultado: %d \n", result); 
    
    return EXIT_SUCCESS;
}


/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c cima_log.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 cima_log.o main.o -o main
./main
*/