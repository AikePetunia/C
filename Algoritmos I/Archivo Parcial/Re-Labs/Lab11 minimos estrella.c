#include <stdio.h>
#include <limits.h>
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

int minimo_pares(int tam, int a[]) {
    int minPar = INT_MAX;
    int i = 0;
    while (i < N) {
        if (a[i] % 2 == 0 && a[i] < minPar) {
            minPar = a[i];
        }
        i = i + 1;
    }
    return minPar;
}

int minimo_impares(int tam, int a[]) {
    int minImpar = INT_MAX;
    int i = 0;
    while (i < N) {
       if (a[i] % 2 != 0 && a[i] < minImpar) {
           minImpar = a[i];
       }
       i = i + 1;
    }
    return minImpar;
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

    int minimoParRespuesta = minimo_pares(N, a);
    int minimoImparRespuesta = minimo_impares(N, a);
    bool existeMultiploRespuesta = existe_multiplo(m, N, a);
    bool paresRespuesta = todos_pares(N, a);

    printf("Todos los elementos del arreglo son pares\n");
    printf("El mínimo par es: %d\n", minimoParRespuesta);
    printf("El mínimo impar es: %d\n", minimoImparRespuesta);
    
    if (existeMultiploRespuesta) {
        printf("Existe al menos un múltiplo de %d en el arreglo.\n", m);
    } else {
        printf("No existe ningún múltiplo de %d en el arreglo.\n", m);
    }
}