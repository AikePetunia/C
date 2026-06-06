#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "moto.h"

struct _moto {
    struct _rueda * rueda_delantera;
    struct _rueda * rueda_trasera;
};

struct _rueda {
    int presion;
    bool pinchada;
};


/**
 * @brief Crea una moto nueva, con ruedas con presion óptima
 *
 */
moto_t moto_nueva() {
    moto_t moto;

    moto = malloc(sizeof(struct _moto));

    moto->rueda_delantera = malloc(sizeof(struct _rueda));
    moto->rueda_delantera->presion = PRESION_OPTIMA;
    moto->rueda_delantera->pinchada = false;

    moto->rueda_trasera = malloc(sizeof(struct _rueda));
    moto->rueda_trasera->presion = PRESION_OPTIMA;
    moto->rueda_trasera->pinchada = false;

    return moto;
}

/**
 * @brief Rompe la moto, modificando presion y pinchadura de ambas ruedas
 *
 */
void romper_moto(moto_t moto,
                 int presion_del, bool pinchada_del,
                 int presion_tras, bool pinchada_tras) {
    moto->rueda_delantera->presion = presion_del;
    moto->rueda_delantera->pinchada = pinchada_del;
    moto->rueda_trasera->presion = presion_tras;
    moto->rueda_trasera->pinchada = pinchada_tras;
}

/** 
 * @brief Chequea si la moto tiene sus ruedas en perfectas condiciones
 * (presión óptima y sin pinchar)
 *
 */
bool chequear_moto(moto_t moto) {
    bool b1 = moto->rueda_delantera->presion == PRESION_OPTIMA;
    bool b2 = moto->rueda_delantera->pinchada == false;
    bool b3 = moto->rueda_trasera->presion == PRESION_OPTIMA;
    bool b4 = moto->rueda_trasera->pinchada == false;
    return (b1 && b2 && b3 && b4);
}

/** 
 * @brief Imprime en pantalla una moto
 *
 */
void mostrar_moto(moto_t moto) {
    // https://ascii.co.uk/art/motorcycles
    printf("     _\n");
    printf("  |>/--.    __\n");
    printf(" __/'---\\--__\n");
    printf("/  \\ #0_\\\\/  \\\n");
    printf("\\__/  '   \\__/\n");
    printf("delantera   trasera\n");
    printf("presion     presion\n");
    printf("   %i          %i\n", moto->rueda_delantera->presion, moto->rueda_trasera->presion);
    printf("pinchada?   pinchada?\n");
    printf("   %i          %i\n", moto->rueda_delantera->pinchada, moto->rueda_trasera->pinchada);
}

/**
 * @brief Repara las ruedas de la moto
 *
 * Si una rueda no está pinchada, se le debe poner la presión óptima
 * SIN CAMBIARLA.
 * Si una rueda está pinchada, se debe:
 *   1. Descartar la rueda pinchada (liberar memoria)
 *   2. Colocar una rueda nueva con la presión óptima (alojar memoria)
 */
void reparar_moto(moto_t moto) {

    if (moto->rueda_delantera->pinchada == false) {
        moto->rueda_delantera->presion = PRESION_OPTIMA;
    }

    if (moto->rueda_delantera->pinchada == true) {
        free(moto->rueda_delantera);
        moto->rueda_delantera = malloc(sizeof(struct _rueda));
        moto->rueda_delantera->presion = PRESION_OPTIMA;
        moto->rueda_delantera->pinchada = false;
    }

        if (moto->rueda_trasera->pinchada == false) {
        moto->rueda_trasera->presion = PRESION_OPTIMA;
    }

    if (moto->rueda_trasera->pinchada == true) {
        free(moto->rueda_trasera);
        moto->rueda_trasera = malloc(sizeof(struct _rueda));
        moto->rueda_trasera->presion = PRESION_OPTIMA;
        moto->rueda_trasera->pinchada = false;
    }

}

/**
 * @brief Destruye la moto, liberando toda la memoria
 *
 */
void destruir_moto(moto_t moto) {
    free(moto->rueda_delantera);
    free(moto->rueda_trasera);
    free(moto);
}

/*
gcc -Wall -Wextra -std=c99 tests.c moto.c -o tests 
./tests 

con ejemplo:
gcc -Wall -Wextra -std=c99 ejemplo.c moto.c -o ejemplo 
./ejemplo 
*/