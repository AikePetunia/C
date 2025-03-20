#include <stdio.h>
#include <limits.h> 

int maximo_negativo(int a[], int tam) {
    int max = INT_MIN;
    for (int i = 0; i < tam ; i++) {
        if (a[i] < 0 && a[i] > max) {
         max = a[i];
        }
    }
    return max;
};

int main (void) {
    int a[] = { 8, -100, 2, -5, 3 };//sacar los negativos para ver el neutro
    int tam = 5;
    const int N = 5;

    printf("Ingrese los elementos del arreglo de tamaño 5: \n");
    for (int k = 0; k < N; k++ ) {
        int dummy;
        printf("Elemento %d:", k);
        scanf("%d", &dummy);    
    }

    int rta = maximo_negativo(a, tam);
    printf("el numero es: %d", rta); //ya se q esto no va,,,
    return 0;
}