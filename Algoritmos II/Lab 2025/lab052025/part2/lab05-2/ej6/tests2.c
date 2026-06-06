#include <stdbool.h>
#include <stdio.h>
#include "list.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TAIL 3
#define N_TESTCASES_ADDR 4
#define N_TESTCASES_TAKE 5

// construye una lista a partir de un arreglo
// (usa los constructores de lista empty y addl)
list array_to_list(int array[], int length) {
    list result;
    result = empty();

    // agregamos al revés ya que usamos addl
    for (int i = length; i > 0; i--) {
        result = addl(array[i-1], result);
    }

    return result;
}

// chequea si dos listas son iguales
// (usa las funciones de listas length e index)
bool is_equal_to(list l1, list l2) {
    int len1 = length(l1);
    int len2 = length(l2);
    int i = 0;
    while (i < len1 && i < len2 && index(l1, i) == index(l2, i)) {
        i++;
    }
    return i == len1 && len1 == len2;
}

// // imprime una lista
// // (usa las funciones de listas length e index)
// void show_list(list l) {
// }

// Testeo de la función tail()
void test_tail() {
    // representación de un solo caso de test
    struct tail_testcase {
        int a[MAX_LENGTH];       // elementos de la lista de entrada
        int length;              // largo de la lista de entrada
        int result[MAX_LENGTH];  // elementos esperados de la lista resultado
        int result_length;       // largo esperado de la lista resultado
    };

    // casos de test (uno por línea)
    struct tail_testcase tests[N_TESTCASES_TAIL] = {
      { {-2}, 1, {}, 0 },             // testea: tail([-2]) == []
      { {1, -2}, 2, {-2}, 1 },        // testea: tail([1, -2]) == [-2]
      { {8, 1, -2}, 3, {1, -2}, 2 },  // testea: tail([8, 1, -2]) == [1, -2]
    };

    list input;
    list result, expected_result;

    printf("TESTING tail\n");

    for (int i=0; i < N_TESTCASES_TAIL; i++) {
        printf("Test case %i: ", i+1);

        // creamos la lista de entrada
        input = array_to_list(tests[i].a, tests[i].length);

        // TEST! llamamos la función a testear
        result = tail(input);

        // creamos la lista resultado esperada
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // comparamos resultado obtenido con resultado esperado
        if (is_equal_to(result, expected_result)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        destroy_list(result);
        destroy_list(expected_result);
    }
}

// Testeo de la función addr()
void test_addr() {
    // representación de un solo caso de test
    struct addr_testcase {
        int a[MAX_LENGTH];       // elementos de la lista de entrada
        int length;              // largo de la lista de entrada
        elem e;                  // elemento a agregar
        int result[MAX_LENGTH];  // elementos esperados de la lista resultado
        int result_length;       // largo esperado de la lista resultado
    };

    // casos de test (uno por línea)
    struct addr_testcase tests[N_TESTCASES_ADDR] = {
      { {8, 1, -2}, 3, 44, {8, 1, -2, 44}, 4 },  // testea: addr([8, 1, -2], 44) == [8, 1, -2, 44]
      { {1, -2}, 2, 44, {1, -2, 44}, 3 },        // testea: addr([1, -2], 44) == [1, -2, 44]
      { {-2}, 1, 44, {-2, 44}, 2 },              // testea: addr([-2], 44) == [-2, 44]
      { {}, 0, 44, {44}, 1 },                    // testea: addr([], 44) == [44]      
    };

    list input;
    list result, expected_result;

    printf("TESTING addr\n");

    for (int i=0; i < N_TESTCASES_ADDR; i++) {
        printf("Test case %i: ", i+1);

        // creamos la lista de entrada
        input = array_to_list(tests[i].a, tests[i].length);

        // TEST! llamamos la función a testear
        result = addr(input, tests[i].e);

        // creamos la lista resultado esperada
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // comparamos resultado obtenido con resultado esperado
        if (is_equal_to(result, expected_result)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        destroy_list(result);
        destroy_list(expected_result);
    }
}

// Testeo de la función take()
void test_take() {
    // representación de un solo caso de test
    struct take_testcase {
        int a[MAX_LENGTH];       // elementos de la lista de entrada
        int length;              // largo de la lista de entrada
        int n;                   // cantidad de elementos a tomar
        int result[MAX_LENGTH];  // elementos esperados de la lista resultado
        int result_length;       // largo esperado de la lista resultado
    };

    // casos de test (uno por línea)
    struct take_testcase tests[N_TESTCASES_TAKE] = {
      { {8, 1, -2}, 3, 0, {}, 0 },          // testea: take([8, 1, -2], 0) == []
      { {8, 1, -2}, 3, 1, {8}, 1 },         // testea: take([8, 1, -2], 1) == [8]
      { {8, 1, -2}, 3, 2, {8, 1}, 2 },      // testea: take([8, 1, -2], 2) == [8, 1]
      { {8, 1, -2}, 3, 3, {8, 1, -2}, 3 },  // testea: take([8, 1, -2], 3) == [8, 1, -2]
      { {8, 1, -2}, 3, 4, {8, 1, -2}, 3 },  // testea: take([8, 1, -2], 4) == [8, 1, -2]
    };

    list input;
    list result, expected_result;

    printf("TESTING take\n");

    for (int i=0; i < N_TESTCASES_TAKE; i++) {
        printf("Test case %i: ", i+1);

        // creamos la lista de entrada
        input = array_to_list(tests[i].a, tests[i].length);

        // TEST! llamamos la función a testear
        result = take(input, tests[i].n);

        // creamos la lista resultado esperada
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // comparamos resultado obtenido con resultado esperado
        if (is_equal_to(result, expected_result)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        destroy_list(result);
        destroy_list(expected_result);
    }
}

int main() {
    test_tail();
    test_addr();
    test_take();

    return 0;
}
