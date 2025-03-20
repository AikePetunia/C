#include <stdio.h>  
#define N 5
struct comp_t {
    int menores;
    int iguales;
    int mayores;
};

struct comp_t cuantos(int tam, int a[], int elem) {
    struct comp_t resultado;
    resultado.menores = 0;
    resultado.iguales = 0;
    resultado.mayores = 0;
    int i = 0;

    // Recorre el arreglo y actualiza el contador
    while (i < N) {
        if (a[i] < elem) {
            resultado.menores++;
        } else if (a[i] == elem) {
            resultado.iguales++;
        } else {
            resultado.mayores++;
        }
        i = i + 1;
    }
    return resultado;
}

int main(void) {
    int a[N];
    int elem; 
    int i = 0;

    printf("ingrese los elementos del arreglo \n");
    while (i < N) {
        printf("elemento %d: ", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }

    printf("Ingrese el numero que quiere saber cuantas veces la data de mayor menor o igual: ");
    if (scanf("%d", &elem) != 1) {
        printf("Error: el elemento debe ser un número entero\n");
        return 1;
    } //ojo con esto, puede q no se necsite 

    struct comp_t resultado = cuantos(N, a, elem);

    printf("Menores: %d\n", resultado.menores);
    printf("Iguales: %d\n", resultado.iguales);
    printf("Mayores: %d\n", resultado.mayores);

    return 0;
}
