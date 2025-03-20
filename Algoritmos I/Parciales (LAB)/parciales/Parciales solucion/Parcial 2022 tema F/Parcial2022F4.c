#include <stdio.h>

struct persona {
    int dni;
    float altura;
};

struct alturas_t {
    int n_altos;
    int n_bajos;
};

struct alturas_t contar_altos_y_bajos(struct persona a[], int tam, float alt) {
    struct alturas_t resultado;
    resultado.n_altos = 0;
    resultado.n_bajos = 0;

    for (int i = 0; i < tam; i++) {
        if (a[i].altura < alt) {
            resultado.n_bajos++;
        } 
        if (a[i].altura > alt) {
            resultado.n_altos++;
        } 
    }
    return resultado;
};

int main (void) {
    const int N = 5;
    struct persona a[N];
    int tam = 5;
    float alt;
    printf("Ingrese elementos para la lista de longitud 5: \n");
    for (int k = 0; k < N; k++) {
        printf("dni %d: ", k + 1);
        scanf("%d", &a[k].dni);  

        printf("altura %d: ", k + 1);
        scanf("%f", &a[k].altura); 
    } //Se guardan en tuplas
    
    printf("Ingrese la altura para comparar (Se admiten decimales)");
    scanf("%f", &alt);

    struct alturas_t resultado = contar_altos_y_bajos(a, tam, alt); 

     printf("hay enanos %d, hay aaltos %d", resultado.n_bajos, resultado.n_altos); //YA SE QUE NO VAA
}