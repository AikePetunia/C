#ifndef _ROBOT_H
#define _ROBOT_H

#include <stdbool.h>

#define ACEITE_OPTIMO 999

typedef struct _robot * robot_t;


/**
 * @brief Crea un robot nuevo, con aceite óptimo y sin partes quemadas
 *
 */
robot_t robot_nuevo();

/**
 * @brief Usa el robot, provocando cambios en el aceite y posibles
 * partes quemadas
 *
 */
void usar_robot(robot_t robot,
                 int aceite_codo, bool quemado_codo,
                 int aceite_mano, bool quemado_mano);

/** 
 * @brief Verifica si el robot tiene el aceite óptimo y ninguna parte quemada.
 *
 */
bool verificar_robot(robot_t robot);

/** 
 * @brief Imprime en pantalla un robot
 *
 */
void mostrar_robot(robot_t robot);

/**
 * @brief Repara el robot
 *
 * Reemplaza SOLAMENTE las partes quemadas por partes nuevas con aceite óptimo
 * (requiere liberar memoria y alojar memoria nueva)
 *
 * A las partes no quemadas NO LAS REEMPLAZA, sólo les pone el aceite óptimo
 */
void reparar_robot(robot_t robot);

/**
 * @brief Destruye el robot, liberando toda la memoria
 *
 */
void destruir_robot(robot_t robot);

#endif
