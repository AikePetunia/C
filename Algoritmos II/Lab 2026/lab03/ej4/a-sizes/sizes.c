#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"
#include <string.h>

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",
           sizeof(messi.name),
           sizeof(messi.age),
           sizeof(messi.height),
           sizeof(data_t)
        );

    printf("--- direcciones de memoria --- \n");
    printf("name %p \n",  &messi.name);
    printf("age %p \n",  &messi.age);
    printf("height %p \n",  &messi.height );
    
    // c ??
    int *dataP = NULL;
    dataP = malloc(sizeof(data_t));
    free(dataP);

    return EXIT_SUCCESS;
}

/*
gcc -Werror -Wall -Wextra -std=c99 sizes.c -o sizes
*/