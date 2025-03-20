#include <stdio.h>
#include <assert.h>
#define N 5 



struct stonks {
    int sube;
    int baja;
};

struct stonks stonks_master(int tam, int a[]) {
    struct stonks stonk;
    stonk.sube = 0;
    stonk.baja = 0;
    int i = 0;
    while (i < N) {
        if (a[i] <= a[i + 1]) {
            stonk.sube++;
        } else if (a[i] > a[i + 1]) {
            stonk.baja++;
        }
        i = i + 1;
    }
    return stonk;
};

int main ( void ){ 
    int a[N];
    int i = 0;

    while (i < N) {
        printf("Ingrese el elemento %d:", i + 1);
        scanf("%d", &a[i]);
        i = i + 1;
    }

    struct stonks respuesta = stonks_master(N, a);

    printf("Suben %d, baja %d", respuesta.sube, respuesta.baja);

    return 0;
}