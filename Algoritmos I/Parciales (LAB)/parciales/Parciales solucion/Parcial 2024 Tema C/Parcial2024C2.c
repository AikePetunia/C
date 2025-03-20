#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define N 5

void llenar_con_temperaturas(float a[], int tam) {
    int i = 0;
    while (i < N) {
        printf("Ingrese el la temperatura %d (Celcius) : ", i + 1);
        scanf("%f", &a[i]);
        assert(a[i] > 0);
        i = i + 1;
    }
}

bool hay_mas_de_2_altas(float a[], int tam) {
    int i = 0;
    int contTempAlta = 0;
    while (i < tam) {
        if(a[i] >= 30.0) {
            contTempAlta++;
        }
        i = i + 1;
    }
    if (contTempAlta >= 3) {
        return true;
    } else {
        return false;
    }
}

int main (void) {
    float a[N];
    llenar_con_temperaturas(a, N);
    bool respuesta = hay_mas_de_2_altas(a, N);

    if (respuesta == true) {
        printf("hay por lo menos 3 temperaturas altas ");
    }   else if (respuesta == false) {
        printf("no hay temperaturas altas");
    }
    return 0;
}