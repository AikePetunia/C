#include <stdio.h>
#include <limits.h>
#define N 5

int minimo_pares(int tam, int a[]) {
    int min_value = INT_MAX;
    int i = 0;
    while (i < N) {
       if (a[i] % 2 == 0 && a[i] < min_value) {
           min_value = a[i];
       }
       i = i + 1;
    }
    return min_value;

}   //devuelve el elemento par mas chico del arreglo

int minimo_impares(int tam, int a[]) {
    int min_value = INT_MAX;
    int i = 0;
    while (i < N) {
       if (a[i] % 2 != 0 && a[i] < min_value) {
           min_value = a[i];
       }
       i = i + 1;
    }
    return min_value;
}   //devuelve el elemento impar mas chico del arreglo

int main(void) {
    int a[N];
    int m;
    int i = 0;

    printf("Este programa no admite decimales. \n");
    printf("Ingrese un elemento por cada linea\n");
    while(i < N) {
        printf("elemento %d: ", i); 
        scanf("%d", &a[i]);
        i = i + 1;
    }   

    printf("el minimo par del arreglo es: %d\n", minimo_pares(N, a));
    printf("el minimo impar del arreglo es: %d\n", minimo_impares(N, a));

}