#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

typedef struct {
    int cuantos_aprobados;
    int cuantos_promocionados;
    bool hay_promocionados;
} s_resultado;

void llena_con_notas(int a[], int tam) {
    int i = 0;
    while (i < N) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &a[i]);
        assert(a[i] >= 0 && a[i] <= 10);
        i = i + 1;
    }
}

s_resultado resultados(int a[], int tam) {
    s_resultado res;
    res.cuantos_aprobados = 0;
    res.cuantos_promocionados = 0;
    res.hay_promocionados = false;
    int i = 0;
    while (i < N) {
        if (a[i] >= 6 && a[i] <= 10) {
            res.cuantos_aprobados++;
        }   
        if (a[i] >= 8 && a[i] <= 10) {
            res.cuantos_promocionados++;
            res.hay_promocionados = true;
        }   
        i = i + 1;
    }
    return res;

}

int main (void) {
    assert(N > 0);
    int a[N];
    llena_con_notas(a, N);
    s_resultado res = resultados(a, N);

    if (res.cuantos_aprobados >= 3) {
        printf("Hay por lo menos 3 aprobados \n");
    } if (res.hay_promocionados == true) {
        printf("Hay promocionado(s) y son %d", res.cuantos_promocionados);
    } else if (res.hay_promocionados == false) {
        printf("no hay promocionados");
    } else {
        printf("no hay suficientes aprobados.");
    }

    return 0;
}