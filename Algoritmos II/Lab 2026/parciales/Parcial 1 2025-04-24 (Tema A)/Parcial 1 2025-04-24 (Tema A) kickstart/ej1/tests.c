#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>

#include "flag_sort.h"

#define MAX_LENGTH 10
#define N_TESTCASES 11

struct testcase {
    int length;
    color_t a[MAX_LENGTH];
    color_t sorted_a[MAX_LENGTH];
};

bool equal_arrays(color_t a[], color_t b[], int length);

int main(void) {
    struct testcase tests[N_TESTCASES] = {
        // largo, arreglo de entrada, arreglo resultado
        { 1, {red}, {red} },
        { 1, {white}, {white} },
        { 1, {blue}, {blue} },
        { 2, {red, red}, {red, red} },
        { 2, {red, white}, {red, white} },
        { 2, {white, red}, {red, white} },
        { 2, {red, blue}, {red, blue} },
        { 2, {blue, red}, {red, blue} },
        { 2, {white, blue}, {white, blue} },
        { 2, {blue, white}, {white, blue} },
        { 6, {blue, red, white, white, blue, red}, {red, red, white, white, blue, blue} },
    };

    printf("TESTING flag_sort\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        flag_sort(tests[i].a, tests[i].length);

        if (equal_arrays(tests[i].a, tests[i].sorted_a, tests[i].length)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }
    }

    return 0;
}

bool equal_arrays(color_t a[], color_t b[], int length) {
    int i = 0;
    while (i < length && a[i] == b[i]) {
        i++;
    }
    return i == length;
}
