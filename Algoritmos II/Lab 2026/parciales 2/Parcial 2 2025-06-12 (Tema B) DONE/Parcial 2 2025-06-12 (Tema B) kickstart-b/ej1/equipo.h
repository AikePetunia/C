#ifndef _EQUIPO_H
#define _EQUIPO_H

#include <stdbool.h>

#define ENERGIA_OPTIMA 100

typedef struct _equipo * equipo_t;


/**
 * @brief Crea un equipo nuevo, con jugadores con energia óptima y sin lesionar
 *
 */
equipo_t equipo_nuevo();

/**
 * @brief Cansa al equipo, cambiando la energía y generando lesiones
 *
 */
void cansar_equipo(equipo_t equipo,
             int energia_defensor, bool lesionado_defensor,
             int energia_delantero, bool lesionado_delantero);

/** 
 * @brief Controla si el equipo tiene sus jugadores en perfectas condiciones
 * (energía óptima y sin lesionar)
 *
 */
bool controlar_equipo(equipo_t equipo);

/** 
 * @brief Imprime en pantalla un equipo
 *
 */
void mostrar_equipo(equipo_t equipo);

/**
 * @brief Cura al equipo
 *
 * Si un jugador no está lesionado, se le debe poner la energía óptima
 * SIN CAMBIARLO.
 * Si un jugador está lesionado, se debe:
 *   1. Sacar el jugador lesionado (liberar memoria)
 *   2. Poner un jugador nuevo con la energía óptima (alojar memoria)
 */
void curar_equipo(equipo_t equipo);

/**
 * @brief Desarma el equipo, liberando toda la memoria
 *
 */
void desarmar_equipo(equipo_t equipo);

#endif
