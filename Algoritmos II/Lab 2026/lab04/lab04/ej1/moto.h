#ifndef _MOTO_H
#define _MOTO_H

#include <stdbool.h>

#define PRESION_OPTIMA 32

typedef struct _moto * moto_t;


/**
 * @brief Crea una moto nueva, con ruedas con presion óptima y sin pinchar
 *
 */
moto_t moto_nueva();

/**
 * @brief Rompe la moto, modificando presion y pinchadura de ambas ruedas
 *
 */
void romper_moto(moto_t moto,
                 int presion_del, bool pinchada_del,
                 int presion_tras, bool pinchada_tras);

/** 
 * @brief Chequea si la moto tiene sus ruedas en perfectas condiciones
 * (presión óptima y sin pinchar)
 *
 */
bool chequear_moto(moto_t moto);

/** 
 * @brief Imprime en pantalla una moto
 *
 */
void mostrar_moto(moto_t moto);

/**
 * @brief Repara las ruedas de la moto
 *
 * Si una rueda no está pinchada, se le debe poner la presión óptima
 * SIN CAMBIARLA.
 * Si una rueda está pinchada, se debe:
 *   1. Descartar la rueda pinchada (liberar memoria)
 *   2. Colocar una rueda nueva con la presión óptima (alojar memoria)
 */
void reparar_moto(moto_t moto);

/**
 * @brief Destruye la moto, liberando toda la memoria
 *
 */
void destruir_moto(moto_t moto);

#endif
