#include <stdio.h>
#include "moto.h"

int main() {
    // EJEMPLO DE USO DE LA MOTO

    // declaro variable para la moto
    moto_t moto;

    // creo una moto nueva
    moto = moto_nueva();

    // muestro la moto
    mostrar_moto(moto);

    // pincho la rueda delantera (pongo a true el segundo parámetro)
    romper_moto(moto, PRESION_OPTIMA, true, PRESION_OPTIMA, false);

    // chequeo la moto
    if (chequear_moto(moto)) {
        printf("La moto está Ok\n");
    } else {
        printf("La moto se rompió!\n");
    }

    // reparo la moto
    reparar_moto(moto);

    // chequeo la moto de nuevo
    if (chequear_moto(moto)) {
        printf("La moto se arreglo!\n");
    } else {
        printf("La moto sigue rota\n");
    }

    // destruyo la moto
    destruir_moto(moto);
}
