#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#define N 5
struct datos {
    bool hay_multiplo_de_10;
    int mayor_multiplo_de_10;
};

struct datos hay_multiplo(int tam, int a[]) {
    struct datos res;
    res.mayor_multiplo_de_10 = INT_MIN;
    res.hay_multiplo_de_10 = false;
    int i = 0;
    while (i < N) {
        if (a[i] % 10 == 0) {
            res.hay_multiplo_de_10 = true;
            if (a[i] > res.mayor_multiplo_de_10) {
                res.mayor_multiplo_de_10 = a[i];
            }
        }
        i = i + 1;
    }
    return res;
};

int main (void) {
    int a[N];
    int i = 0;
    while (i < N) {
        printf("elemento %d", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
    struct datos respuesta = hay_multiplo(N, a);

    if (respuesta.hay_multiplo_de_10 == true) { //ya se q esto no va,,,
        printf("Hay multiplos de 10 \n");
        printf("El multiplo de 10 mas grande es %d ", respuesta.mayor_multiplo_de_10);
    }   else {
        printf("no hay multiplos de 10 \n");
        printf("El multiplo de 10 mas grande es %d", respuesta.mayor_multiplo_de_10);
    }


    return 0;
}