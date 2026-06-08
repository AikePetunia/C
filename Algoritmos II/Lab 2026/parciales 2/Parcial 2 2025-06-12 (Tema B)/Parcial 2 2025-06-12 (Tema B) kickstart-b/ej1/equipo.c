#include "equipo.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct _equipo {
    struct _jugador * defensor;
    struct _jugador * delantero;
};

struct _jugador {
    int energia;
    bool lesionado;
};


/**
 * @brief Crea un equipo nuevo, con jugadores con energia óptima y sin lesionar
 *
 */
equipo_t equipo_nuevo() {
    equipo_t equipo;

    equipo = malloc(sizeof(struct _equipo));

    equipo->defensor = malloc(sizeof(struct _jugador));
    equipo->defensor->energia = ENERGIA_OPTIMA;
    equipo->defensor->lesionado = false;

    equipo->delantero = malloc(sizeof(struct _jugador));
    equipo->delantero->energia = ENERGIA_OPTIMA;
    equipo->delantero->lesionado = false;

    return equipo;
}

/**
 * @brief Cansa al equipo, cambiando la energía y generando lesiones
 *
 */
void cansar_equipo(equipo_t equipo,
             int energia_defensor, bool lesionado_defensor,
             int energia_delantero, bool lesionado_delantero) {
    equipo->defensor->energia = energia_defensor;
    equipo->defensor->lesionado = lesionado_defensor;
    equipo->delantero->energia = energia_delantero;
    equipo->delantero->lesionado = lesionado_delantero;
}

/** 
 * @brief Controla si el equipo tiene sus jugadores en perfectas condiciones
 * (energía óptima y sin lesionar)
 *
 */
bool controlar_equipo(equipo_t equipo) {
    bool b1 = equipo->defensor->energia == ENERGIA_OPTIMA;
    bool b2 = equipo->defensor->lesionado == false;
    bool b3 = equipo->delantero->energia == ENERGIA_OPTIMA;
    bool b4 = equipo->delantero->lesionado == false;
    return (b1 && b2 && b3 && b4);
}

/** 
 * @brief Imprime en pantalla un equipo
 *
 */
void mostrar_equipo(equipo_t equipo) {
    printf(" O       O\n");
    printf("/|\\     /|\\\n");
    printf("/ \\     / \\\n");
    printf("defensor   delantero\n");
    printf("energia     energia\n");
    printf("   %i          %i\n", equipo->defensor->energia, equipo->delantero->energia);
    printf("lesionado?   lesionado?\n");
    printf("   %i          %i\n", equipo->defensor->lesionado, equipo->delantero->lesionado);
}

/**
 * @brief Cura al equipo
 *
 * Si un jugador no está lesionado, se le debe poner la energía óptima
 * SIN CAMBIARLO.
 * Si un jugador está lesionado, se debe:
 *   1. Sacar el jugador lesionado (liberar memoria)
 *   2. Poner un jugador nuevo con la energía óptima (alojar memoria)
 */
void curar_equipo(equipo_t equipo) {

    // defensor sin energia, pero sin lesionado
    if (equipo->defensor->energia != ENERGIA_OPTIMA && equipo->defensor->lesionado == false) {
        equipo->defensor->energia = ENERGIA_OPTIMA;
    }

    // defensor lesionado
    if (equipo->defensor->lesionado == true) {
        free(equipo->defensor);
        equipo->defensor = malloc(sizeof(struct _jugador));
        equipo->defensor->energia = ENERGIA_OPTIMA;
        equipo->defensor->lesionado = false;
    }
    
    // delantero sin energia, pero sin lesion
    if (equipo->delantero->energia != ENERGIA_OPTIMA && equipo->delantero->lesionado == false) {
        equipo->delantero->energia = ENERGIA_OPTIMA;
    }

    // delantero lesionado
    if (equipo->delantero->lesionado == true) {
        free(equipo->delantero);
        equipo->delantero = malloc(sizeof(struct _jugador));
        equipo->delantero->energia = ENERGIA_OPTIMA;
        equipo->delantero->lesionado = false;
    }
}

/**
 * @brief Desarma el equipo, liberando toda la memoria
 *
 */
void desarmar_equipo(equipo_t equipo) {
    free(equipo->defensor);
    free(equipo->delantero);
    free(equipo);
}
