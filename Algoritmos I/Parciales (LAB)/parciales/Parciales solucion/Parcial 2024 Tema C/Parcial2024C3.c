#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define N 5

typedef struct {
    int cuantas_bajas;
    int cuantas_medias;
    int cuantas_altas;
} s_temperaturas;

void llenar_con_temperaturas(float a[], int tam) {
    int i = 0;
    while (i < N) {
        printf("Ingrese el la temperatura %d (Celcius) : ", i + 1);
        scanf("%f", &a[i]);
        assert(a[i] > 0);
        i = i + 1;
    }
}

s_temperaturas totales(float a[], int tam) {
    s_temperaturas res;
    res.cuantas_bajas = 0;
    res.cuantas_medias = 0;
    res.cuantas_altas = 0;
    int i = 0;
    while (i < tam) {
        if(a[i] < 15.0) {
            res.cuantas_bajas++;
        }
        if(a[i] <= 30.0 && a[i] >= 15.0) {
            res.cuantas_medias++;
        }
        if(a[i] >= 30.0) {
            res.cuantas_altas++;
        }
        i = i + 1;
    }
    return res;
};

int main (void) {
    float a[N];
    llenar_con_temperaturas(a, N);
    s_temperaturas res = totales(a, N);

    printf("Hay %d temperaturas bajas \n", res.cuantas_bajas);
    printf("Hay %d temperaturas medias \n", res.cuantas_medias);
    printf("Hay %d temperaturas altas", res.cuantas_altas);

    return 0;
}