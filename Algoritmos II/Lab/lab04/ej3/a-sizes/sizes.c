#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

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
            sizeof(messi.name), sizeof(messi.age), 
            sizeof(messi.height), sizeof(data_t)
        );


    printf("[Manera 1] Direccion de memoria de cada campo: \n");
    /*
    printf("Dirección de name: %p \n",
            "Dirección de age: %p \n",
            "Dirección de height: %p \n",
            (void *)messi.name, (void *)messi.age, 
            (void *)messi.height
            );
    */
    
    printf("direccion de name %p    \n", (void*)messi.name);
    printf("direccion de age %p     \n", (void*)messi.age);
    printf("direccion de height %p  \n", (void *)messi.height);

    printf("[Manera 2] Direccion de memoria de cada campo: \n");
    
    printf("direccion de name %lu    \n", (uintptr_t)messi.name);
    printf("direccion de age %lu     \n", (uintptr_t)messi.age);
    printf("direccion de height %lu  \n", (uintptr_t)messi.height);

    
    /*printf(" Dirección de name: %lu\n",
            "Dirección de age: %lu\n",
            "Dirección de height: %lu\n",
            (uintptr_t)messi.name, (uintptr_t)messi.age, 
            (uintptr_t)messi.height
            );*/
    

        
    return EXIT_SUCCESS;
}
// https://www.youtube.com/watch?v=n_Se6bt8jM0
// https://www.youtube.com/watch?v=of2kZkUDApw&list=PLLfC2vEod54J7vzFIeX23iyaSAjFhevQV&index=8&t=240s