#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

#define MAX_LENGTH 5
#define N_TESTCASES 11

struct testcase {
    int a[MAX_LENGTH];
    int length;
    int k;
    int result;
};

int main() {
    struct testcase tests[N_TESTCASES] = {
        { {8}, 1, 0, 8 },
        { {42}, 1, 0, 42 },
        { {1, 2}, 2, 0, 1 },
        { {1, 2}, 2, 1, 2 },
        { {2, 1}, 2, 0, 1 },
        { {2, 1}, 2, 1, 2 },
        { {8, -2, 9, 0, 13}, 5, 0, -2 },
        { {8, -2, 9, 0, 13}, 5, 1, 0 },
        { {8, -2, 9, 0, 13}, 5, 2, 8 },
        { {8, -2, 9, 0, 13}, 5, 3, 9 },
        { {8, -2, 9, 0, 13}, 5, 4, 13 }
    };
    int result;

    printf("TESTING k_esimo\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i:\n", i+1);
        result = k_esimo(tests[i].a, tests[i].length, tests[i].k);
        printf("Result: %i,  Expected: %i \t", result, tests[i].result);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }
    }

    return 0;
}
