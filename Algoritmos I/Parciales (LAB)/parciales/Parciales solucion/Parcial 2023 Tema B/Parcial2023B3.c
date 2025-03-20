#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#define N 5

struct datos {
    bool esta_ordenado_asc;
    int maximo;
};


struct datos esta_ordenado_asc(int tam, int a[]) {
    struct datos respuesta;
    respuesta.maximo = INT_MIN;
    respuesta.esta_ordenado_asc = true;
    int i = 0;
    while (i < N) {
        if (a[i] > respuesta.maximo) {
            respuesta.maximo = a[i];
        }
        if (i < N - 1 && a[i] > a[i + 1]) {  
            respuesta.esta_ordenado_asc = false;
        }
        i = i + 1;
    }
    return respuesta;
};

int main (void) {
    int a[N];
    int i = 0;

    while (i < N ) {
        printf("elemento %d: ", i + 1);
        scanf("%d", &a[i]);
        i = i + 1;
    }
    assert(i > 0);

    struct datos respuesta = esta_ordenado_asc(N, a);

    if (respuesta.esta_ordenado_asc == true) {
        printf("Esta ordenado y el numero mas grande es %d", respuesta.maximo);
    }   else {
        printf("No esta ordenado \n ");
        printf("numero mas grande es %d", respuesta.maximo);

    }
    return 0;
}