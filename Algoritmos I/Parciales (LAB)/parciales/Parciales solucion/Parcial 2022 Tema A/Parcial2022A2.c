#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define N 5

bool es_primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i * i <= n; i += 2) {  
        if (n % i == 0) return false;
    }
    return true;
}

int cuantos_primos(int a[], int tam, int pos1, int pos2) {
    int i = pos1;
    int cuantosPrimosContador = 0; // o 1, funciona de manera extraña la verdad
    while (i <= pos2 && i < N){
        if (es_primo(a[i]) == true) {
            cuantosPrimosContador++;
        }
        i = i + 1;
    }
    return cuantosPrimosContador;
}

int pedirEntero(void) {
    int x;
    scanf("%d", &x);
    return x;
}

int main (void) {
    int pos1, pos2;
    int a[N];
    int i = 0;
    printf("Ingrese la primera posicion");
    pos1 = pedirEntero();
    printf("Ingrese la segunda posicion:");
    pos2 = pedirEntero();

    assert(pos1 > 0 && pos2 > 0 && pos1 <= pos2);

    printf("Ingrese los elementos del arreglo \n");
    while (i < N ) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &a[i]);
        i = i + 1;
    }    

    int respuesta = cuantos_primos(a, N, pos1, pos2);

    printf("Hay %d numeros primos entre pos1 y pos2", respuesta);
    return 0;

}