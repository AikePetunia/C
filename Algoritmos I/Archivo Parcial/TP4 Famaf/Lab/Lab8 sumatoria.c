#include <stdio.h>
#include <assert.h>
#define N 5

int sumatoria (int tam, int a[]) {
    int suma = 0;
    int i = 0;
    while (i < N) {
        suma += a[i]; //esta expresion es legal bajo lo que nos enseñaron en la clase?
        i = i + 1;
    }
    printf("la sumatoria de los elementos del arreglo es: %d\n", suma);
}

int main() {
    int a[N];
    int i = 0;
    printf("Introduzca los valores de los elementos \n");
    while (i < N) {
        printf("elemento %d: ", i); //bueno, misma. no puedo con el assert checkear que son numeros los ingresados?
        scanf("%d", &a[i]);
        i = i + 1;
    }

    sumatoria(N, a);
    
    return 0;
}

/*
int pedirEntero(void) {
    int x;
    scanf("%d", &x);
    return x;
}

void imprimirEntero(int x, int y, int z) {
    printf("Los valores son x %d, y %d, z %d", x, y, z);
}
int main (void) {
    int x, y, z, X, Y, Z;
    printf("Ingrese un numero entero para x");
    x = pedirEntero();
    printf("Ingrese un numero entero para y");
    y = pedirEntero();
    printf("Ingrese un numero entero para z");
    z = pedirEntero();
    
    X = x; 
    Y = y;
    Z = z;
    //Precondicion
    assert(x == X && y == Y && z == Z && x != y);

    x = y;
    y = X;
    z = X - Y;
    
    //post condicion
    assert(x == Y);
    assert(y == X);
    assert(z != 0);

    imprimirEntero(x,y,z);

    return 0;
}
*/