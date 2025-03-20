#include <stdbool.h>
#include <stdio.h>
#define N 5

struct particion {
    bool hay_cero;
    int cantidad_de_pares;
    int cantidad_de_impares
};

struct particion par_impar(int tam, int a[]) {
    struct particion res;
    res.cantidad_de_impares = 0;
    res.cantidad_de_pares = 0;
    res.hay_cero = false;
    int i = 0;

    while (i < N) {
        if (a[i] == 0) {
            res.hay_cero = true;
        } else if (a[i] % 2 == 0) {
            res.cantidad_de_pares++;
        } else if (a[i] % 2 != 0) {
            res.cantidad_de_impares++;
        }
        i = i + 1;
    }
    return res;
}

int main (void) {
    int a[N];
    int i = 0;

    while (i < N ) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &a[i]);
        i = i + 1;
    }

    struct particion respuesta = par_impar(N, a);

    if(respuesta.hay_cero == true) {
        printf("Hay cero, y hay %d pares, y %d impares", respuesta.cantidad_de_pares, respuesta.cantidad_de_pares);
    } else {
        printf("no hay cero, y hay %d pares, y %d impares", respuesta.cantidad_de_pares, respuesta.cantidad_de_pares);

    }
    return 0;
}