#include <stdio.h>
#define N 5
struct persona {
    int dni;
    float altura;
};

struct alturas_t {
    int n_altos;
    int n_bajos;
};

struct alturas_t contar_altos_y_bajos(struct persona a[], int tam, float alt) {
    struct alturas_t respuesta;
    respuesta.n_altos = 0;
    respuesta.n_bajos = 0;
    int i = 0;
    while (i < N) {
        if (a[i].altura < alt) {
            respuesta.n_bajos++;
        }
        if (a[i].altura >= alt) {
            respuesta.n_altos++;
        }
        i = i + 1;
    }
    return respuesta;
}

int main (void) {
    struct persona a[N];
    float alt;
    int i = 0;
    while (i < N ) {
        printf("ingrese el dni: \n");
        scanf("%d", &a[i].dni);

        printf("Ingrse la altura, para los decimales, usar . : \n");
        scanf("%f", &a[i].altura);
        i = i + 1;
    }
    
    printf("ingrese la altura a comprar\n");
    scanf("%f", &alt);

    contar_altos_y_bajos(a, N, alt);
    struct alturas_t respuesta = contar_altos_y_bajos(a, N, alt);

    printf("Hay %d personas bajas, hay %d personas altas q la altura %d", respuesta.n_bajos, respuesta.n_altos, alt);

    return 0;
}