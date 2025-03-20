#include <stdio.h>
#include <assert.h>
#define N 5

struct cinco_t {
    int primero;
    int segundo;
    int tercero;
    int cuarto;
    int quinto;
};

struct cinco_t cinco_pares(int a[], int tam) {
    struct cinco_t numero = {-1, -1, -1, -1, -1};
    int i = 0;
    while (i < N) {
        if (a[i] % 2 == 0 && i == 0) {
            numero.primero = a[i];
        } else if (a[i] % 2 == 0 && i == 1) {
            numero.segundo = a[i];
        } else if (a[i] % 2 == 0 && i == 2) {
            numero.tercero = a[i];
        } else if (a[i] % 2 == 0 && i == 3) {
            numero.cuarto = a[i];
        } else if (a[i] % 2 == 0 && i == 4) {
            numero.quinto = a[i];
        }
    i = i + 1;
    }
    return numero;
}

int main (void) {
    int a[N];
    int i = 0;


    while (i < N) {
        printf("elemento %d :", i + 1);
        scanf("%d", &a[i]);
        i = i + 1;
    }

    struct cinco_t respuesta = cinco_pares(a, N);

    printf("Enteros pares encontrados:\n");
    printf("Primero: %d\nSegundo: %d\nTercero: %d\nCuarto: %d\nQuinto: %d\n",
           respuesta.primero, respuesta.segundo, respuesta.tercero, respuesta.cuarto, respuesta.quinto);
    return 0;
}