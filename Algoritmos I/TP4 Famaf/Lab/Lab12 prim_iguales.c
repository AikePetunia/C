#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

bool es_primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; n % 2 != 0; i+2) {
        if (n % i == 0) return false;
    }
    return true;
}

int prim_iguales(int tam, int a[]) {
    int i = 0;
    int j = 0;
    while (i < N) {
        while (j < N) {
            if (es_primo(a[i]) && es_primo(a[j]) && a[i] == a[j]) {
                return true; 
            }
            j = j + 1; 
        }
        i = i + 1;
    }
    return false;
}

void mayor_tramo(int tam, int a[]) {
    int tramo_actual = 1; // cuenta la posicion
    int tramo_max = 1; // asumo que el largo maximo del arreglo es 1
    int valor_tramo = a[0]; // posicion inicial en la cual estoy en el arreglo

    for (int i = 1; i < tam; i++) { //inicio en el elemento 1 para comparar con el elemento 0 (al inicio, dsps incrementa)
        if (a[i] == a[i - 1]) { // si hay un elemento igual que el anterior, suma 1 al contador del tramo actual (cuanto durará)
            tramo_actual++;
        } else { 
            if (tramo_actual > tramo_max) { // si no son guales los elementos, compara si el tramo actual es mayor al tramo maximo para ver si sale o no del bucle
                tramo_max = tramo_actual; 
                valor_tramo = a[i - 1]; 
                /*
                si el tramo actual es mayor que el máximo hasta ahora (tramo_actual > tramo_max), 
                actualizamos tramo_max con el valor de tramo_actual y guardamos el 
                valor de ese tramo (valor_tramo = a[i - 1])
                */
            }
            tramo_actual = 1;
        }
    }
    if (tramo_actual > tramo_max) {
        tramo_max = tramo_actual;
        valor_tramo = a[tam - 1];
    }
    /*
    Finalización del bucle: Cuando el bucle ha terminado, es posible que el tramo más largo esté al final 
    del arreglo y no se haya actualizado porque el else solo se ejecuta cuando el tramo termina, es decir, 
    cuando los elementos dejan de ser iguales. Por eso, es necesario hacer una última verificación fuera del bucle:
    */
    printf("El mayor tramo de elementos iguales tiene longitud %d y el valor numerico es %d\n", tramo_max, valor_tramo);
}

int main(void) {
    int a[N];
    int i = 0;
    printf("Ingrese los elementos del arreglo: \n");
    while (i < N) {
        printf("elemento (Ingrese numeros) %d: ", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
    
    if (prim_iguales(N, a)) {
        printf("Hay dos elementos en el arreglo que son primos iguales\n");
    } else{
        printf("No hay dos elementos en el arreglo que sean primos iguales\n");
    }
    mayor_tramo(N, a);
}