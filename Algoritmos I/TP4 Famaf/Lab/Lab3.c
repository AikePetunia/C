#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool es_vocal(char letra ) {
    char vocales[] = {'a', 'e', 'i', 'o', 'u'};
    letra = tolower(letra); // pasa a minúsculas la letra dada

    for(int i = 0; i < 5; i++) {// recorre el array de vocales hasta coincidir con la letra dada
        if (letra == vocales[i]) { //si letra esta en la lista de vocales, de indice i.
            printf("La letra ingresada es una vocal\n");
            return false;
        }
        else {
            printf("La letra ingresada no es una vocal. %c \n", letra);
            return true;
        }
    }   
    
}
int main(void) {

    char letra;
    printf("Ingrese una vocal: \n"); //pregunta la letra
    scanf("%c", &letra);

    es_vocal(letra); //pasa la letra a la funcion

    return 0;
}