#include <stdio.h>
#include <stdbool.h>
#define N 5

bool todos_pares(int tam, int a[]) {
    int i = 0;
    bool paresBool;
    while ( i < N ) {
        if (a[i] % 2 != 0) {
            paresBool = false;
        }
        i = i + 1;
    }
    paresBool = true;
    return paresBool;
}

bool existe_multiplo(int m, int tam, int a[]) {
    int i = 0;
    bool respuesta;
    while (i < N) {
        if (a[i] % m == 0) {
            respuesta = true;
        }   else {
            respuesta = false;
        }
        i = i + 1;
    }
    return respuesta;
}

int main (void) {
    int a[N];
    int i = 0;
    int m;

    while (i < N ) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
    printf("Ingrese un elemento para ver si hay multiplos en la lista");
    scanf("%d", &m);

    int respuesta = existe_multiplo(m, N, a);
    int paresRespuesta = todos_pares(N, a);

    if (paresRespuesta == true) {
        printf("en la lista son todos pares \n");
    }   else {
        printf("en la lista no son todos pares \n");
    }

    if (respuesta = true) {
        printf("existe el multiplo %d en la lista \n", m);
    } else {
        printf("no existe el multiplo %d en la lista \n", m);
    }
}