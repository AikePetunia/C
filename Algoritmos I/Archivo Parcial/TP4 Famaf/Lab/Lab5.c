#include <stdio.h>

int suma_hasta (int n) { //funcion que suma los primeros n numeros enteros

    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    return suma;
}

int main(void) {
    int n;
    printf("Ingrese un numero entero: \n");
    scanf("%d", &n);
    printf("La suma de los primeros %d numeros enteros es: %d\n", n, suma_hasta(n)); 
    //llama a la funcion suma_hasta y hace el calculo para devolver

    return 0;
}