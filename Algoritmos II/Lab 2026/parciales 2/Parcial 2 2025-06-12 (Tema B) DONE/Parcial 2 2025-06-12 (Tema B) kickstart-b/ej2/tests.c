#include "list.h"
#include "reverse.h"

#include <stdbool.h>
#include <stdio.h>

#define MAX_LENGTH 10
#define N_TESTCASES_REVERSE 7

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

// Testeo de la función reverse()
void test_reverse() {
    // representación de un solo caso de test
    struct reverse_testcase {
        int l[MAX_LENGTH];       // elementos de la lista de entrada
        int length;              // largo de la lista de entrada
        int result[MAX_LENGTH];  // elementos esperados de la lista resultado
        int result_length;       // largo esperado de la lista resultado
    };

    // casos de test (uno por línea)
    struct reverse_testcase tests[N_TESTCASES_REVERSE] = {
      { {}, 0, {}, 0 },
      { {7}, 1, {7}, 1 },
      { {7, 42}, 2, {42, 7}, 2 },
      { {7, 42, 128}, 3, {128, 42, 7}, 3 },
      { {7, 42, 128, 9}, 4, {9, 128, 42, 7}, 4 },
      { {7, 42, 128, 9, 42}, 5, {42, 9, 128, 42, 7}, 5 },
      { {7, 42, 128, 9, 42, 11}, 6, {11, 42, 9, 128, 42, 7}, 6 },
    };

    list l, l_copy, result, expected_result;

    printf("TESTING reverse\n");

    for (int i=0; i < N_TESTCASES_REVERSE; i++) {
        printf("Test case %i: ", i+1);

        // creamos la lista de entrada y el resultado esperado
        l = array_to_list(tests[i].l, tests[i].length);
        expected_result = array_to_list(tests[i].result, tests[i].result_length);

        // TEST! llamamos la función a testear
        result = reverse(l);

        // chequeamos:
        // 1. el resultado obtenido es el resultado esperado
        bool result_ok = is_equal_to(result, expected_result);
        destroy_list(expected_result);
        destroy_list(result);

        // 2. la lista original sigue intacta
        l_copy = array_to_list(tests[i].l, tests[i].length);
        bool input_ok = is_equal_to(l, l_copy);
        destroy_list(l);
        destroy_list(l_copy);

        if (result_ok && input_ok) {
            printf("OK\n");
        } else if (!result_ok) {
            printf("FAILED: incorrect result\n");
        } else {
            printf("FAILED: input modified\n");
        }
    }
}

int main() {
    test_reverse();

    return 0;
}
