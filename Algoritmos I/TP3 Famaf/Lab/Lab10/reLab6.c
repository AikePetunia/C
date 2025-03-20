#include <stdio.h>

int pedir_entero (char name) {
	
	
	printf("Ingrese un valor a su variable \n");
	scanf("%c \n", &name);

    int x, y, z, w;
	printf("Ingrese un numero \n");
	scanf("%d \n", &x);
    printf("Ingrese un numero \n");
	scanf("%d \n", &y);
    printf("Ingrese un numero \n");
	scanf("%d \n", &z);
    printf("Ingrese un numero \n");
	scanf("%d \n", &w);
	return x;
}

void imprimir_entero (int x, int y, int z, int w, char name) {
	printf("Su variable '%c' tiene", name);
	printf(" el numero entero y  : %d\n", x);
    printf(" numero entero y  : %d\n", y);
	printf(" numero entero y  : %d\n", z);
	printf(" numero entero : %d\n", w);

}

int main () {
	int n;
    int y, z, w;
	
	n = pedir_entero('n');
	imprimir_entero( n, y, z, w, 'n');
	
	return 0;	
}


// no deja ingresar numeros?
/*



Codigo lab 6:

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
        m = x;
    } else if (x >= y ) {
        m = y;
    } else if ( m < z) {
        // continue; / skip; 
    } else if ( m >= z) {
        m = z;
    }

    printf("El valor de m es: %d\n", m); 
    
    ingrese el valor de x: 5
    ingrese el valor de y: 4
    ingrese el valor de z: 8
    ingrese el valor de m: 0
    El valor de m es: 4
    

    return 0;

*/