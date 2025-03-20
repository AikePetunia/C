#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
    int x;
    scanf("%d", &x);
    return x;
}

int main (void) {
    int i,j,k,I,J,K;

    printf("Ingrese el valor de i:");
    i = pedirEntero();

    printf("Ingrese el valor de k:");
    k = pedirEntero();

    printf("Ingrese el valor de j:");
    j = pedirEntero();

    I = i;
    J = j;
    K = k;

    //pre
    assert(i == I && j == J && k == K && I > 0 && J > 0 && K > 0);
    
    //cuerpo
    i = i * j;
    j = j * k;
    k = k * I;

    //pos
    assert(i == I * J && j == J * K && K && k == K * I);
    
    printf("Los valores finales son i %d, j %d, y k %d", i, j, k);
    return 0;
}