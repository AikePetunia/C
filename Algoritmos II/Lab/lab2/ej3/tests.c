#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 10

int main() {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {1}, 1, 1}, // 1
        { {8}, 1, 1}, // 2 
        { {2}, 1, 1}, // 3
        { {1,2}, 2, 2}, // 4 
        { {1,2,3}, 3, 3}, // 5 
        { {1,2,3,4}, 4, 4}, // 6 
        { {1,2,3,4,5,6,7,8,9}, 9, 9}, // 7 
        { {5,4,3,2,1}, 5, 5},// 8
        { {2, -13}, 2, -1},// 9
        { {5, -3, 10}, 3, -1}// 10
        /*
        Ejercicio 2, tiene_cima.
        El arreglo [5,4,3,2,1] tiene cima en el primer elemento? es decir, si un arreglo esta ordenado decrecientemente o creciente [1,2,3,4,5] significa que tiene cima el arreglo?
        francolq — Yesterday at 5:54 PM
        sí y sí
        */
    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: \n", i+1);

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}

/*
compile:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c cima_log.c tests.c 
gcc -Wall -Werror -Wextra -pedantic -std=c99 cima_log.o tests.o -o tests
./tests
debug:
gcc -g -Wall -Werror -Wextra -pedantic -std=c99 -c cima_log.c tests.c
gcc -g -Wall -Werror -Wextra -pedantic -std=c99 cima_log.o tests.o -o tests
gdb ./tests
break cima_log
run
step
display izq
display der
display mid
display cima
display res
*/