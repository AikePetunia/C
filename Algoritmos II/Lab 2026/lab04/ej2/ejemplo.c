#include <stdio.h>
#include "robot.h"

int main() {
    // EJEMPLO DE USO DEL ROBOT

    // declaro variable para el robot
    robot_t robot;

    // creo un robot nuevo
    robot = robot_nuevo();

    // muestro el robot
    mostrar_robot(robot);

    // uso el robot y se quema el codo
    usar_robot(robot, ACEITE_OPTIMO, true, ACEITE_OPTIMO, false);

    // chequeo el robot
    if (verificar_robot(robot)) {
        printf("El robot está Ok\n");
    } else {
        printf("El robot se rompió!\n");
    }

    // reparo el robot
    reparar_robot(robot);

    // chequeo el robot de nuevo
    if (verificar_robot(robot)) {
        printf("El robot se arreglo!\n");
    } else {
        printf("El robot sigue roto\n");
    }

    // destruyo el robot
    destruir_robot(robot);
}
