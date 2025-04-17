#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cima.h"
#include "cima_log.h"

// arreglo de un millon de elementos:
#define ARRAY_LENGTH 1000000

double medir_cima(int a[], int length);
double medir_cima_log(int a[], int length);

int main(void) {
    int a[ARRAY_LENGTH];
    int current_length;

    double cpu_time_used;

    // llenar arreglo con elementos en orden creciente:
    // 0, 1, 2, ..., 999999
    // la cima es el último elemento: 999999
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        a[i] = i;
    }

    printf("length\tcima\tcima_log\n");

    // tomar e imprimir 99 puntos de muestra:
    current_length = ARRAY_LENGTH / 100;
    for (int i = 0; i < 100-1; i++) {
        printf("%i\t", current_length);

        cpu_time_used = medir_cima(a, current_length);
        printf("%f\t", cpu_time_used);

        cpu_time_used = medir_cima_log(a, current_length);
        printf("%f\n", cpu_time_used);

        current_length += ARRAY_LENGTH / 100;
    }

    return EXIT_SUCCESS;
}

double medir_cima(int a[], int length) {
    clock_t start, end;
    double cpu_time_used;

    // tomar tiempo al inicio
    start = clock();

    // llamar a la funcion (ignorar resultado)
    cima(a, length);

    // tomar tiempo al final
    end = clock();

    // calcular tiempo en milisegundos
    cpu_time_used = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000);

    return cpu_time_used;
}

double medir_cima_log(int a[], int length) {
    clock_t start, end;
    double cpu_time_used;

    // tomar tiempo al inicio
    start = clock();

    // llamar a la funcion (ignorar resultado)
    cima_log(a, length);

    // tomar tiempo al final
    end = clock();

    // calcular tiempo en milisegundos
    cpu_time_used = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000);

    return cpu_time_used;
}
