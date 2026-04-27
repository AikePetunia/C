#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "fixstring.h"

#define N_TESTCASES 8

struct testcase {
    fixstring s1;
    fixstring s2;
    bool eq;
    bool leq;
};

int main(void) {
    struct testcase tests[N_TESTCASES] = {
        // Test cases: s1, s2, eq, leq
        {"", "", true, true},
        {"", "hola", false, true},
        {"hola", "", false, false},
        {"hola", "hola", true, true},
        {"hola", "holanda", false, true},
        {"holanda", "hola", false, false},
        {"hola", "chau", false, false},
        {"chau", "hola", false, true},
    };
    bool eq, leq;

    printf("TESTING fstring_eq\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        eq = fstring_eq(tests[i].s1, tests[i].s2);
        if (eq != tests[i].eq) {
            printf("FAILED: fstring_eq(\"%s\", \"%s\") expected %d got %d.\n",
                   tests[i].s1,
                   tests[i].s2,
                   tests[i].eq,
                   eq);
        } else {
            printf("OK\n");
        }
    }

    printf("\nTESTING fstring_less_eq\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        leq = fstring_less_eq(tests[i].s1, tests[i].s2);
        if (leq != tests[i].leq) {
            printf("FAILED: fstring_less_eq(\"%s\", \"%s\") expected %d got %d.\n",
                   tests[i].s1,
                   tests[i].s2,
                   tests[i].leq,
                   leq);
        } else {
            printf("OK\n");
        }
    }

    return EXIT_SUCCESS;
}
