#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

#define MAX_LENGTH 5
#define N_TESTCASES 10

struct testcase {
    int a[MAX_LENGTH];
    int length;
    int k;
    int result;
};

/*

Parte D: Testing: Completar los tests de tests.c con al menos estos 10 (diez) casos de test:
arreglo de un elemento (k=0 obligatoriamente).
arreglo de dos elementos ordenados, con k=0.
arreglo de dos elementos ordenados, con k=1.
arreglo de dos elementos desordenados, con k=0.
arreglo de dos elementos desordenados, con k=1.
el arreglo de ejemplo dado {8, -2, 9, 0, 13} con todos los k posibles.

Compilar, ejecutar los tests y asegurarse de que todos pasen:

*/

int main() {
    struct testcase tests[N_TESTCASES] = {
    // primero el array, tamaño, k, numero esperado.
    { {8}, 1, 0, 8}, 
    { {0, 1}, 2, 0, 0}, 
    { {0, 2}, 2, 1, 2}, 
    { {8, 9}, 2, 0, 8}, 
    { {10, 11}, 2, 1, 11}, 
    {{8, -2, 9, 0, 13}, 5, 0, 8}, 
    {{8, -2, 9, 0, 13}, 5, 1, -2}, 
    {{8, -2, 9, 0, 13}, 5, 2, 9}, 
    {{8, -2, 9, 0, 13}, 5, 3, 0}, 
    {{8, -2, 9, 0, 13}, 5, 4, 13}, 

    /*
    TESTING k_esimo
    Test case 1: OK
    Test case 2: OK
    Test case 3: OK
    Test case 4: OK
    Test case 5: OK
    Test case 6: OK
    Test case 7: FAILED
    Test case 8: FAILED
    Test case 9: FAILED
    Test case 10: OK
    */
    };
    int result;

    printf("TESTING k_esimo\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = k_esimo(tests[i].a, tests[i].length, tests[i].k);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }
    }

    return 0;
}

/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c k_esimo.c tests.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 k_esimo.o tests.o -o tests
./tests
*/