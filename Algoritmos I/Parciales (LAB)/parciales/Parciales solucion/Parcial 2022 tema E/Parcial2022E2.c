#include <stdio.h>

int suma_cuadrados_pares(int a[], int tam) {
    int sum = 0;
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 == 0 ) {  
            int cuadrado = a[i] * a[i];
            sum += cuadrado;
            
        }
    }

    return sum;
}

int main (void) {
    int a[] = { 3, -5, 1, 9, 7 };
    int tam = 5;
    const N = 5;
    int tamUser;
    printf("Ingrese el arreglo de longitud 5: \n");
    for (int i; i < N; i++) {
        int dummy;
        printf("Elemento %d: \n", i + 1);
        scanf("%d", &dummy);
    }
    
    printf("Ingrese los elementos para el arreglo: \n");
    for(int k; k < tamUser; k++) {
        int dummy; 
        printf("Elemento %d: ", k + 1);
        scanf("%d", &dummy);
    }

    suma_cuadrados_pares(a, tam);
    return 0;
}