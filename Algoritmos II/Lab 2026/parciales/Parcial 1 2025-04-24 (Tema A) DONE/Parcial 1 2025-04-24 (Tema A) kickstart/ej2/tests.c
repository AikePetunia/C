#include <stdbool.h>
#include <stdio.h>

#include "weather_table.h"
#include "queries.h"

#define N_TESTCASES 5

struct testcase {
    int year;
    int result;
};

int main(void) {
    WeatherTable a;

    struct testcase tests[N_TESTCASES] = {
        // año, resultado
        {1980, 70487},
        {1985, 1017},
        {1990, 102897},
        {2000, 124373},
        {2005, 59359},
    };

    int result;
    
    table_from_file(a, "../input/weather_cordoba.in");

    printf("TESTING year_rainfall\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = year_rainfall(a, tests[i].year);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED: expected %i but got %i\n", tests[i].result, result);
        }
    }

    return 0;
}
