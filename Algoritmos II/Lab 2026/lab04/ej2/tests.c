#include <stdio.h>
#include "robot.h"

#define N_TESTCASES 9

int main() {
    // representación de un solo caso de test
    struct testcase {
        int aceite_codo;
        bool quemado_codo;
        int aceite_mano;
        bool quemado_mano;
    };

    // casos de test (uno por línea)
    struct testcase tests[N_TESTCASES] = {
        { ACEITE_OPTIMO, true, ACEITE_OPTIMO, false }, // codo quemado
        { ACEITE_OPTIMO, false, ACEITE_OPTIMO, true }, // mano quemada
        { ACEITE_OPTIMO, true, ACEITE_OPTIMO, true },  // todo quemado
        { 11, false, ACEITE_OPTIMO, false },           // falta aceite codo
        { ACEITE_OPTIMO, false, 11, false },           // falta aceite mano
        { 11, false, 11, false },                      // varios problemas
        { 11, true, 11, false },                       // varios problemas
        { 11, false, 11, true },                       // varios problemas
        { 11, true, 11, true },                        // varios problemas
    };

    printf("TESTING reparar_robot\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        // creamos un robot nuevo
        robot_t robot = robot_nuevo();

        // lo usamos
        usar_robot(robot, tests[i].aceite_codo, tests[i].quemado_codo,
                          tests[i].aceite_mano, tests[i].quemado_mano);

        // TEST! llamamos la función a testear
        reparar_robot(robot);

        // chequeamos si se arregló el robot
        if (verificar_robot(robot)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }

        destruir_robot(robot);
    }

    return 0;
}
