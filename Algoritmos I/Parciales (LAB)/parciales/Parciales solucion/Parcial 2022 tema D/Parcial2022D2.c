#include <stdio.h>
#include <assert.h>
#define N 5

int multiplica_multiplos (int a[], int tam, int k) {
    int res = 1; 
    for (int i = 0; i < tam; i++) {
        if (a[i] % k == 0) {
            res = a[i] * res;
        }
    }
    return res;
}

int main (void) {
    int a[N];
    int k;
    int i = 0;
    int resultado;

    printf("ingrese elementos para el arreglo de tamaño %d \n", N);
    while (i < N) {
        printf("Ingrese un elemento para el arreglo en indice %d: \n", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
    printf("Ingrese el elemento k multiplo: \n");
    scanf("%d", &k);
    assert(k !=0);

    resultado = multiplica_multiplos(a, N, k);
    printf("resultado: %d", resultado); //esto ya se q no va aca
    return 0;
}