#include <stdio.h>
#include <limits.h>
#define N 5

struct paridad_t {
    int maximo_par;
    int minimo_impar;
};

struct paridad_t maxmin_paridad(int a[], int tam) {
    struct paridad_t respuesta;
    respuesta.minimo_impar = INT_MIN;
    respuesta.maximo_par = INT_MAX;
    int i = 0;
    while (i < tam) {
        if (a[i] % 2 == 0) {
            respuesta.minimo_impar = a[i];
        } 
        if (a[i] % 2 != 0) {
            respuesta.maximo_par = a[i]; 
        }  
        i = i + 1;
    }
    return respuesta;
}

int main (void) {
    int a[N];
    int i = 0;
    printf("ingrese elementos para el arreglo de tamaño %d \n", N);
    while (i < N) {
        printf("Ingrese un elemento para el arreglo en indice %d: \n", i + 1);
        scanf("%d", &a[i]);
        i = i + 1;
    }
    struct paridad_t resultado = maxmin_paridad(a, N);
    printf("el minimo par %d, el maximo impar %d", resultado.minimo_impar, resultado.maximo_par);
    return 0;
}