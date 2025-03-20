#include <stdio.h>

void imprimir_hola(void) {
    printf("hola\n");
}

void imprimir_chau(void) {
    printf("chau\n");
}

int main() {
    imprimir_hola();
    imprimir_hola();

    imprimir_chau();
    imprimir_chau();

    do 
        imprimir_hola(); //hola si romper las bolas
    while (1);
    

    return 0;
}