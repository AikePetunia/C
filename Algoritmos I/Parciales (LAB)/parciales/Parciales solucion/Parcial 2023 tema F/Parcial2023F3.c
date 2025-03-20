#include <stdbool.h>
#include <stdio.h>
#define N 5

struct paridad {
    int pares;
    int impares;
    bool paridad_alternada;
};

struct paridad analizar_paridad(int tam, int a[]) {
    struct paridad res;
    res.pares = 0;
    res.impares = 0;
    res.paridad_alternada = true;
    int i = 0;
    while (i < N) {
        if(a[i] % 2 == 0) {
            res.pares++;
        }   else {
            res.impares++;
        }
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
            res.paridad_alternada = false;
        }
        i = i + 1;
    }
    return res;
};

int main (void) {
    int a[N];
    int i = 0;

    while (i < N ) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &a[i]);
        i = i + 1;
    }

    struct paridad res = analizar_paridad(N, a);

    if (res.paridad_alternada == true) {
        printf("Hay paridad alterada, y hay %d pares, y %d impares", res.pares, res.impares );
    }   else {
        printf("no hay paridad alterada, y hay %d pares, y %d impares", res.pares, res.impares );  
    }
    return 0;
}