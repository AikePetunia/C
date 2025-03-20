#include <stdio.h>
#include <float.h>
#define N 5

struct datos_t {
    float min;
    float max;
    double promedio;
};

struct datos_t stats(int tam, float a[]) {
    struct datos_t resultado;
    resultado.min = FLT_MAX;
    resultado.max = FLT_MIN;
    float sum = 0.0;
    int i = 0;
    while (i < N) {
       if (a[i] < resultado.min) {
           resultado.min = a[i];
       }
        if (a[i] > resultado.max) {
             resultado.max = a[i];
        }
       sum += a[i];
    }

    resultado.promedio = sum / N;
    return resultado;

}

int main (void) {
    float a[10];
    int i = 0;

    printf("Ingrese los numeros del arreglo: \n");
    while (i < N) {
        printf("Elemento %d: ", i);
        scanf("%f", &a[i]);
        i = i + 1;
    }

    struct datos_t resultado = stats(N, a);
    printf("El valor minimo es: %f\n", resultado.min);
    printf("El valor maximo es: %f\n", resultado.max);
    printf("El promedio es: %f\n", resultado.promedio);
    return 0;
}
