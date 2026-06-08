#include <stdio.h>
#include "equipo.h"

int main() {
    // EJEMPLO DE EQUIPO

    // declaro variable para el equipo
    equipo_t equipo;

    // creo un equipo nuev
    equipo = equipo_nuevo();

    // muestro el equipo
    mostrar_equipo(equipo);

    // lesiono al delantero (pongo a true el cuarto parámetro)
    cansar_equipo(equipo, ENERGIA_OPTIMA, false, ENERGIA_OPTIMA, true);

    // controlo el estado del equipo
    if (controlar_equipo(equipo)) {
        printf("El equipo está perfecto\n");
    } else {
        printf("El equipo está cansado\n");
    }

    // curo al equipo
    curar_equipo(equipo);

    // controlo el equipo de nuevo
    if (controlar_equipo(equipo)) {
        printf("El equipo se curó!\n");
    } else {
        printf("El equipo sigue cansado\n");
    }

    // desarmo el equipo
    desarmar_equipo(equipo);
}
