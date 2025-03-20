#include <stdio.h>
#include <limits.h>
struct maxmin_t {
    int minimo;
    int indice_min;
    int maximo;
    int indice_max;
};

struct maxmin_t cotas(int a[], int tam) {
    struct maxmin_t resultado;
    resultado.maximo = INT_MIN;
    resultado.minimo = INT_MAX;
    resultado.indice_min = 0;
    resultado.indice_max = 0;
for (int i = 0; i < tam; i++) {
        if (a[i] < resultado.minimo) {
            resultado.minimo = a[i];
            resultado.indice_min = i;
        }
        if (a[i] > resultado.maximo) {
            resultado.maximo = a[i];
            resultado.indice_max = i;
        }
    }
    return resultado;
};

int main (void) {
    //Debe darme el maximo de una lista y su posicion. 
    //Debe darme el minimo de una lista y su posicion.
  
    int a[5];
    int tam = 5;
    const int N = 5;

    printf("Ingrese los elmentos para un arreglo de longitud 5: \n");

    for (int k = 0; k < N; k++) {
        printf("Elemento %d:", k);
        scanf("%d", &a[k]);
    }

    struct maxmin_t respuesta = cotas(a, tam);
    
    
    printf("El minimo %d el indice minimo %d, El maximo %d, El indice maximo %d",  respuesta.minimo, respuesta.indice_min,   respuesta.maximo, respuesta.indice_max);

}