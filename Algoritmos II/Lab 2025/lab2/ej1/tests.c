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
    { {8}, 1, 0, 8}, // test 1
    { {0, 1}, 2, 0, 0}, // test 2
    { {0, 2}, 2, 1, 2}, // test 3
    { {8, 9}, 2, 0, 8}, // test 4
    { {10, 11}, 2, 1, 11},  // test 5
    { {8, -2, 9, 0, 13}, 5, 0, -2 },
    { {8, -2, 9, 0, 13}, 5, 1, 0 },
    { {8, -2, 9, 0, 13}, 5, 2, 8 },
    { {8, -2, 9, 0, 13}, 5, 3, 9 },
    { {8, -2, 9, 0, 13}, 5, 4, 13 }
    // da problemas el partition, a la hora de buscar elementos de mas de 2. se necesita recursion
    };
    int result;

    printf("TESTING k_esimo\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = k_esimo(tests[i].a, tests[i].length, tests[i].k);
        if (result == tests[i].result) {
            printf("OK. numero esperado: %d \n", result);
            // printf("OK\n");
        } else {
            printf("FAILED. numero esperado: %d \n", result);
            // printf("FAILED\n");
        }
    }

    return 0;
}

/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c k_esimo.c tests.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 k_esimo.o tests.o -o tests
./tests
*/