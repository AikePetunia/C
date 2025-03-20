#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

void llena_con_notas(int a[], int tam) {
    int i = 0;
    while (i < N) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &a[i]);
        assert(a[i] >= 0 && a[i] <= 10);
        i = i + 1;
    }
}

bool hay_mas_de_3_aprobados(int a[], int tam) {
    int i = 0;
    int resultado = 0;
    while (i < N) {
        if (a[i] >= 6 && a[i] <= 10) {
            resultado++;
        }
        i = i + 1;
    }
    if (resultado >= 3) {
        return true;
    }   else {
        return false;
    }
}
int main (void) {
    assert(N > 0);
    int a[N];
    llena_con_notas(a, N);
    int aprobados = hay_mas_de_3_aprobados(a, N);

    if (aprobados == true) {
        printf("Hay como minimo 3 aprobados");
    }   else {
        printf("Hay desaprobados");
    }

    return 0;
}