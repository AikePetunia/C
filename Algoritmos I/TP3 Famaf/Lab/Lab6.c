#include <stdio.h>

int main() {
    int x, y, z, m;

    printf("ingrese el valor de x: ");
    scanf("%d", &x);
    printf("ingrese el valor de y: ");
    scanf("%d", &y);
    printf("ingrese el valor de z: ");
    scanf("%d", &z);
    printf("ingrese el valor de m: ");
    scanf("%d", &m);

    if (x < y) {
        m == x;
    } else if (x >= y ) {
        m == y;
    } else if ( m < z) {
        // continue; // skip; HOW, que pongo aca?
    } else if ( m >= z) {
        m == z;
    }

    printf("El valor de m es: %d\n", m); 
    /*
    ingrese el valor de x: 5
    ingrese el valor de y: 4
    ingrese el valor de z: 8
    ingrese el valor de m: 0
    El valor de m es: 4
    */

   //chekiar codigo

    return 0;
}