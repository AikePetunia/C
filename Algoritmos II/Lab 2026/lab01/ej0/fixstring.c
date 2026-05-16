#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "fixstring.h"

// Retorna la cantidad de caracteres antes del '\0' (final de string)
unsigned int fstring_length(fixstring s) {
   int i = 0;
   int countLength = 0;

   // Contar hasta encontrar el terminador '\0'
   while (s[i] != '\0') {
    i++;
    countLength++;
   }
   return countLength;
}

// Retorna true si s1 y s2 son idénticas (incluyendo '\0' en la misma posición)
bool fstring_eq(fixstring s1, fixstring s2) {
    int i = 0;
    
    // Avanzar mientras ambas cadenas sean iguales y no terminen
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }

    // Si ambas están en '\0', son iguales. Si no, compara el carácter donde difieren
    return (s1[i] == s2[i]); 
}

// Retorna true si s1 <= s2 lexicográficamente
bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;

    // Avanzar mientras ambas cadenas sean iguales y no terminen
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }

    // Comparar en la posición donde difieren (o donde termina una)
   return s1[i] <= s2[i];
}


/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c fixstring.c tests.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 fixstring.o tests.o -o tests
./tests
*/