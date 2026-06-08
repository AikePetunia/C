#include <stdio.h>
#include "moto.h"

#define N_TESTCASES 5

int main() {
    // representación de un solo caso de test
    struct testcase {
        int presion_del;
        bool pinchada_del;
        int presion_tras;
        bool pinchada_tras;
    };

    // casos de test (uno por línea)
    struct testcase tests[N_TESTCASES] = {
        { PRESION_OPTIMA, true, PRESION_OPTIMA, false },   // pincha delantera
        { PRESION_OPTIMA, false, PRESION_OPTIMA, true },   // pincha trasera
        { PRESION_OPTIMA, true, PRESION_OPTIMA, true },    // pincha ambas
        { 0, false, PRESION_OPTIMA, false },               // pierde presión delantera
        { PRESION_OPTIMA, false, 0, false },               // pierde presión trasera
    };

    printf("TESTING reparar_moto\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        // creamos una moto nueva
        moto_t moto = moto_nueva();

        // la rompemos
        romper_moto(moto, tests[i].presion_del, tests[i].pinchada_del,
                           tests[i].presion_tras, tests[i].pinchada_tras);

        // TEST! llamamos la función a testear
        reparar_moto(moto);

        // chequeamos si se arregló la moto
        if (chequear_moto(moto)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        destruir_moto(moto);
    }

    return 0;
}
