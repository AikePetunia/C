#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#define N 5

bool existe_multiplo(int m, int tam, int a[]) {     //devuelve bool
    int i = 0;
    printf("Ingrese el multiplo que desea buscar: ");
    scanf("%d", &m);
    while(i < N) {
        if (a[i] % m == 0) {
            printf("El multiplo %d existe en el arreglo\n", m);
            return true;
        }
        i = i + 1;
    }
    printf("El multiplo %d no existe en el arreglo\n", m);
    return false;
}

bool todos_pares(int tam, int a[]) {    //devuelve bool
    int i = 0;
    while (i < N) {
        if (a[i] % 2 != 0) {
            return false;
        } //hay impares
        i = i + 1;
    }
    return true; //todos son pares
}


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

    if (todos_pares(N, a) == false) {
        printf("No todos los elementos del arreglo son pares\n");
        printf("El minimo impar es: %d\n", minimo_impares(N, a));
        printf("El minimo par es: %d\n", minimo_pares(N, a));
    } else {
        printf("Todos los elementos del arreglo son pares\n");
        printf("El minimo par es: %d\n", minimo_pares(N, a));
    }

    existe_multiplo(m, N, a);


}