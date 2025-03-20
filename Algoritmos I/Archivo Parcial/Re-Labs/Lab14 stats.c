#include <stdio.h>
#include <float.h>
#define N 5

struct datos_t {
    float max;
    float min;
    float promedio;
};

struct datos_t stats(int tam, float a[]) {
    struct datos_t num;
    int i = 0;
    num.min = FLT_MAX;
    num.max = FLT_MIN;
    num.promedio = 0.0;
    int sumParaProm = 0.0;
    while (i < N) {
       if (a[i] < num.min) {
           num.min = a[i];
       }
        if (a[i] > num.max) {
            num.max = a[i];
        }
        sumParaProm = a[i] + sumParaProm;
        i = i + 1;
    }
    num.promedio = sumParaProm / N;
    return num;
}

int main (void) {
    int i = 0;
    float a[N];
    while (i < N)  {
        printf("Ingrese el elemento %d : ", i + 1);
        scanf("%f", &a[i]);
        i = i + 1;
    }
    struct datos_t num = stats(N, a);

    printf("El numero max es %f \n", num.max);
    printf("El numero minimo es %f \n", num.min);
    printf("El promedio es %f", num.promedio);

    return 0;
}