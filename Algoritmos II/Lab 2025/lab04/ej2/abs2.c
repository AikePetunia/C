#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
void absolute(int x, int *y) {
    // si usara y solo tengo la direccion de memoria (&res)
    // si uso *y tengo el valor de &res, desreferencia el puntero
    if (x >= 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---
    a = -10;
    // los & pasan las direcciones de memorias, y los punteros, apuntan a estas
    absolute(a, &res);
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/*
c) Para pensar:
¿El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out? -> out
¿Qué tipo de parámetros tiene disponibles  C para sus funciones?
    Parámetros in //
    Parámetros out  //
    Parámetros in/out //




*/