#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "robot.h"

struct _robot {
    struct _codo * codo;
};

struct _codo {
    struct _mano * mano;
    int aceite;
    bool quemado;
};

struct _mano {
    int aceite;
    bool quemado;
};

/**
 * @brief Crea un robot nuevo, con aceite óptimo y sin partes quemadas
 *
 */
robot_t robot_nuevo() {
    robot_t robot;

    robot = malloc(sizeof(struct _robot));

    robot->codo = malloc(sizeof(struct _codo));
    robot->codo->aceite = ACEITE_OPTIMO;
    robot->codo->quemado = false;

    robot->codo->mano = malloc(sizeof(struct _mano));
    robot->codo->mano->aceite = ACEITE_OPTIMO;
    robot->codo->mano->quemado = false;

    return robot;
}

/**
 * @brief Usa el robot, provocando cambios en el aceite y posibles
 * partes quemadas
 *
 */
void usar_robot(robot_t robot,
                 int aceite_codo, bool quemado_codo,
                 int aceite_mano, bool quemado_mano) {
    robot->codo->aceite = aceite_codo;
    robot->codo->quemado = quemado_codo;
    robot->codo->mano->aceite = aceite_mano;
    robot->codo->mano->quemado = quemado_mano;
}

/** 
 * @brief Verifica si el robot tiene el aceite óptimo y ninguna parte quemada.
 *
 */
bool verificar_robot(robot_t robot) {
    bool b1 = robot->codo->aceite == ACEITE_OPTIMO;
    bool b2 = robot->codo->quemado == false;
    bool b3 = robot->codo->mano->aceite == ACEITE_OPTIMO;
    bool b4 = robot->codo->mano->quemado == false;
    return (b1 && b2 && b3 && b4);
}

/**
 * @brief Imprime en pantalla un robot
 *
 */
void mostrar_robot(robot_t robot) {
    printf("    codo              mano\n");
    printf("   aceite            aceite\n");
    printf("     %i                %i\n", robot->codo->aceite, robot->codo->mano->aceite);
    printf("  quemado?          quemado?\n");
    printf("     %i                %i\n", robot->codo->quemado, robot->codo->mano->quemado);
}

/**
 * @brief Repara el robot
 *
 * Reemplaza SOLAMENTE las partes quemadas por partes nuevas con aceite óptimo
 * (requiere liberar memoria y alojar memoria nueva)
 *
 * A las partes no quemadas NO LAS REEMPLAZA, sólo les pone el aceite óptimo
 */
void reparar_robot(robot_t robot) {
    printf("\n\n === stats iniciales === \n");
    printf("La mano está quemada? %d \n", robot->codo->mano->quemado);
    printf("El codo está quemado? %d \n", robot->codo->quemado);
    printf("Cantidad de aceite en la mano %d \n", robot->codo->mano->aceite);
    printf("Cantidad de aceite en el codo %d \n", robot->codo->aceite);
    printf("=== stats iniciales === \n");

    // No está quemado, pero se le refillea el aceita
    if (robot->codo->quemado == false && robot->codo->aceite != ACEITE_OPTIMO) {
        printf("Refill de aceite en CODO: \n");
        robot->codo->aceite = ACEITE_OPTIMO;
    }

    // No está quemado, pero se le refillea el aceita
    if (robot->codo->mano->quemado == false && robot->codo->mano->aceite != ACEITE_OPTIMO) {
        printf("Refill de aceite en MANO: \n");
        robot->codo->mano->aceite = ACEITE_OPTIMO;
    }

    // si el codo esta quemado, se tiene que reparar si o si la mano tmb
    if (robot->codo->quemado == true) {
        printf("liberando memoria para robot->codo \n");
        // como liberamos memoria para el codo, tambien lo hace para la mano
        free(robot->codo);
        printf("memoria liberada \n");

        printf("asignado nueva memoria para codo \n");
        robot->codo = malloc(sizeof(struct _codo));
        printf("memoria asignada para el codo \n");

        robot->codo->aceite = ACEITE_OPTIMO;
        robot->codo->quemado = false;

        robot->codo->mano = malloc(sizeof(struct _mano));
           printf("intentando reparar la mano...\n");
        robot->codo->mano->aceite = ACEITE_OPTIMO;
        printf("boom?\n");
        robot->codo->mano->quemado = false;
        printf("codo reparada re piola \n");
    }
    
    // si la mano esta quemada, se repara solo la mano
    if (robot->codo->mano->quemado == true)
    {
        printf("liberando memoria para robot->codo->mano \n");
        free(robot->codo->mano);
        printf("memoria liberada \n");

        printf("asignado nueva memoria para mano \n");
        robot->codo->mano = malloc(sizeof(struct _mano));
        printf("memoria asignada para el mano \n");

        robot->codo->mano->aceite = ACEITE_OPTIMO;
        robot->codo->mano->quemado = false;
        printf("mano reparada re piola \n");
    } 



    printf("\n=== stats finales === \n");
    printf("La mano sigue quemada? %d \n", robot->codo->mano->quemado);
    printf("El codo sigue quemado? %d \n", robot->codo->quemado);
    printf("Aceite en la mano: %d \n", robot->codo->mano->aceite);
    printf("Aceite en el codo: %d \n", robot->codo->aceite);
    printf("=== stats finales === \n \n \n");
}

/**
 * @brief Destruye el robot, liberando toda la memoria
 *
 */
void destruir_robot(robot_t robot) {
    free(robot->codo->mano);
    free(robot->codo);
    free(robot);
}

/*

gcc -Wall -Wextra -std=c99 tests.c robot.c -o tests 
./tests

gcc -Wall -Wextra -std=c99 ejemplo.c robot.c -o ejemplo 
./ejemplo
*/

