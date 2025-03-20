#include <assert.h>
#include <stdio.h>
#define N 5

int sumatoria(int tam, int a[]) {
    int i = 0;
    int suma = 0;
    while (i < tam) {
        suma = a[i] + suma;
        i = i + 1;
    }
    return suma;
}

int main (void) {
    int a[N];
    int i = 0;

    while (i < N) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &a[i]);
        i = i +1;
    }
    int respuesta = sumatoria(N, a);

    printf("La sumaatoria total es de %d", respuesta);
    return 0;
}