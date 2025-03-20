#include <stdio.h>
#include <assert.h>
#define N 5
void pedir_arreglo(int n_max, int a[]) {    //no debe retornar nada, ni true ni false. Solo pide elementos.

    assert(n_max >= 0 && n_max <= N && "\n Error: El tamaño debe ser entre 1 y N.\n");
    printf("ingrese elementos al arreglo a:  \n");
    int i = 0;
    while (i < n_max) { //Alternativamente, tam, N. 
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
}

void imprimir_arreglo(int n, int a[]) {     //no debe retornar nada, ni true ni false. Solo printea.
    int i = 0;
    while (i < n) {
        printf("%d ,", a[i]);
        i = i + 1;
    }
    printf("\n");
}

int main(void) {
    int n_max;
    int a[N];

    printf("Ingrese la cantidad de elementos que tendrá el arreglo: \n");
    if (scanf("%d", &n_max) != 1) {
            printf("Error: Debe ingresar un número.\n");
    } else {
        pedir_arreglo(n_max, a);
        imprimir_arreglo(n_max, a);
    }
    return 0;
}