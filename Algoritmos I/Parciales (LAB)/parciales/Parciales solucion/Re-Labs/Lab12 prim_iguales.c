#include <stdio.h>
#define N 15

int prim_iguales(int tam, int a[]) {
    int tramo_actual = 1; 
    int tramo_max = 1;
    int valor_tramo = a[0]; 
    int i = 0;
    while (i < N) { 
        if (a[i] == a[i - 1]) { 
            tramo_actual++;
        } else { 
            if (tramo_actual > tramo_max) { 
                tramo_max = tramo_actual; 
                valor_tramo = a[i - 1]; 
            }
            tramo_actual = 1; //reinicia
        }
        i = i + 1;
    }
    if (tramo_actual > tramo_max) {
        tramo_max = tramo_actual;
        valor_tramo = a[tam - 1];
    }
    printf("El mayor tramo de elementos iguales tiene longitud %d y el valor numerico es %d\n", tramo_max, valor_tramo);
}

int main (void) {
    int i = 0;
    int a[N];

    while (i < N){
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
    int tramoLargo = prim_iguales(N,a);
    printf("El tramo mas largo es de %d", tramoLargo);
    return 0;
}
