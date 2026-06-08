#include <stdio.h>
#include "equipo.h"

#define N_TESTCASES 5

int main() {
    // representación de un solo caso de test
    struct testcase {
        int energia_defensor;
        bool lesionado_defensor;
        int energia_delantero;
        bool lesionado_delantero;
    };

    // casos de test (uno por línea)
    struct testcase tests[N_TESTCASES] = {
        { ENERGIA_OPTIMA, true, ENERGIA_OPTIMA, false },   // lesion del defensor
        { ENERGIA_OPTIMA, false, ENERGIA_OPTIMA, true },   // lesion del delantero
        { ENERGIA_OPTIMA, true, ENERGIA_OPTIMA, true },    // lesion de ambos
        { 0, false, ENERGIA_OPTIMA, false },              // pierde energía el defensor
        { ENERGIA_OPTIMA, false, 0, false },              // pierde energía el delantero
    };

    printf("TESTING curar_equipo\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        // creamos un equipo nuevo
        equipo_t equipo = equipo_nuevo();

        // lo cansamos
        cansar_equipo(equipo, tests[i].energia_defensor, tests[i].lesionado_defensor,
                              tests[i].energia_delantero, tests[i].lesionado_delantero);

        // TEST! llamamos la función a testear
        curar_equipo(equipo);

        // chequeamos si se curó el equipo
        if (controlar_equipo(equipo)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        desarmar_equipo(equipo);
    }

    return 0;
}
