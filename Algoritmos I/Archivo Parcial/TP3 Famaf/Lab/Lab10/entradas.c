#include <stdio.h>

int pedir_entero (char name) {
	int x;
	printf("Ingrese un numero \n");
	scanf("%d", &x); // \n hacia q se pongan dos inputs lol
	return x;	//solo debe devolver un valor, justamente es un solo int
}

void imprimir_entero (int x, char name) {
	printf("La variable %c tiene el valor: %d", name, x);
}

int main (void) {
	int x;
	x = pedir_entero('n');
	imprimir_entero(x, 'n');
	
	return 0;	
}