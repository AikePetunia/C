#include <stdio.h>
#include <assert.h>
#define N 5

int sum_init(int tam, int a[], int n) {
    int i = 0;
    int sumaElem = 0;
    assert(n <= tam);
    while(i < n) {
        sumaElem = sumaElem + a[i];
        i = i + 1;
    }
    return sumaElem;
}

int main (void) {
    int a[N];
    int n;
    int i = 0;
    while (i < N) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }

    printf("Ingrese un numero n para sumar hasta ese punto en el arreglo \n");
    scanf("%d", &n);

    int res = sum_init(N, a, n);
    printf("La suma es %d", res);
    return 0;
}