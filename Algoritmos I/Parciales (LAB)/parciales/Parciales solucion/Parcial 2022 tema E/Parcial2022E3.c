#include <stdio.h>
#include <limits.h>
#include <assert.h>

struct minmul_t {
    int minimo;
    int indice;
};

struct minmul_t multiplo_minimo(int a[], int tam, int k) {
    struct minmul_t resultado;  
    resultado.minimo = INT_MAX; 
    resultado.indice = -1; 
    for (int i = 0; i < tam; i++) {
        if (a[i] % k == 0 && a[i] < resultado.minimo) {
            resultado.minimo = a[i];
            resultado.indice = i;
        } 
    }
    return resultado;
};

int main (void) {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int N = 5;
    int tam = 10;
    int k;
    printf("Ingrese los elementos para el arreglo de longitud 5: \n");
    for (int i = 0; i < N; i++) {
        int dummy;
        printf("Elemento %d: \n", i + 1);
        scanf("%d", &dummy);
    }

    printf("Elegir un valor K para hacer las cosas: \n");
    scanf("%d", &k);
    assert(k != 0);

    struct minmul_t resultado = multiplo_minimo(a, tam, k);

    if (resultado.indice != -1) {
        printf("El mínimo múltiplo de %d es %d en el índice %d\n", k, resultado.minimo, resultado.indice);
    } else {
        printf("No hay múltiplos de %d en el arreglo.\n", k);
    }   //bue esto no va, pero tambien yo no me voy a poner a debuggear siempre q testeo
    return 0;
}