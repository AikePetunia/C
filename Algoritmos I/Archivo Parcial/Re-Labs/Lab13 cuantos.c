#include <stdio.h>
#define N 5
struct comp_t {
    int menores;
    int iguales;
    int mayores;
};

struct comp_t cuantos(int tam, int a[], int elem) {
    struct comp_t respuesta;
    respuesta.menores = 0;
    respuesta.iguales = 0;
    respuesta.mayores = 0;
    int i = 0;
    while (i < N) {
        if (a[i] < elem) {
            respuesta.menores++;
        }  
        if (a[i] > elem) {
            respuesta.mayores++;
        }   
        if (a[i] == elem) {
            respuesta.iguales++;
        }
        i = i + 1;
    }
    return respuesta;
}

int main (void) {
    int elem;
    int i = 0;
    int a[N];

    while (i < N) {
        printf("ingrese el elemento %d: ", i);
        scanf("%d", &a[i]);
        i = i + 1 ;
    }

    printf("Ingrese un elemento para coso");
    scanf("%d", &elem);
    struct comp_t respuesta = cuantos(N, a, elem);
    printf("Hay %d mayores, %d menores y %d iguales a %d", respuesta.mayores, respuesta.menores, respuesta.iguales, elem);

}