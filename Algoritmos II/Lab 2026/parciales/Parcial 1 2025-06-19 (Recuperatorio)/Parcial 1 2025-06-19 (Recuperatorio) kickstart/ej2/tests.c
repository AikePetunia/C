#include <stdbool.h>
#include <stdio.h>

#include "weather_table.h"
#include "queries.h"

#define N_TESTCASES 5

bool equal_arrays(int a[], int b[], int length) {
    int i = 0;
    while (i < length && a[i] == b[i]) {
        i++;
    }
    return i == length;
}

struct testcase {
    int year;
    int expected_result[MONTHS];
};

int main() {
    WeatherTable a;

    struct testcase tests[N_TESTCASES] = {
        // año, resultado
        { 1980, {2692, 5004, 2388, 4597, 991, 1803, 0, 5004, 305, 2210, 7010, 3988} },
        { 1985, {406, 102, 102, 305, 0, 0, 0, 0, 0, 0, 0, 102} },
        { 1990, {5588, 2007, 5309, 9906, 406, 0, 610, 0, 305, 9906, 2794, 4597} },
        { 2000, {3810, 5232, 6604, 6426, 2489, 203, 889, 178, 1016, 2743, 7391, 5690} },
        { 2005, {6198, 2007, 5309, 3607, 0, 51, 787, 787, 711, 3404, 711, 3708} },
    };

    int result[MONTHS];
    
    table_from_file(a, "../input/weather_cordoba.in");

    printf("TESTING max_daily_rainfall\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        max_daily_rainfall(a, tests[i].year, result);

        if (equal_arrays(result, tests[i].expected_result, MONTHS)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
            for (month_t month = january; month <= december; month++) {
                printf("%i, ", result[month]);
            }
            printf("\n");
        }
    }

    return 0;
}
