#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#define N 5

typedef struct {
    int cuantas_a;
    int cuantas_x;
    int cuantas_z;
} s_total;

s_total totales(char a[], int tam) {
    s_total res;
    res.cuantas_a = 0;
    res.cuantas_x = 0;
    res.cuantas_z = 0;  
    int i = 0;
    while(i < N) {
        if (a[i] == 'a') {
            res.cuantas_a++;
        } else if (a[i] == 'x') {
            res.cuantas_x++;
        } else if (a[i] == 'z') {
            res.cuantas_z++;
        }
        i = i + 1;
    }   
    return res;
};

void llena_con_char(char a[], int tam) {
    int i = 0;
    while (i < N) {
        printf("Ingrese el elemento %d : ", i + 1);
        scanf(" %c", &a[i]);
        a[i] = tolower(a[i]); 
        i++;
    } 
}

int main (void) {
    assert(N > 0);
    char a[N];
    llena_con_char(a, N);

    s_total res = totales(a, N);
    printf("Hay %d a\n", res.cuantas_a);
    printf("Hay %d x\n", res.cuantas_x);
    printf("Hay %d z\n", res.cuantas_z);

    return 0;
}