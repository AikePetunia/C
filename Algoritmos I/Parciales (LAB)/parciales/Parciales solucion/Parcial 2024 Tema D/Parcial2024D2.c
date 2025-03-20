#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#define N 5

void llena_con_char(char a[], int tam) {
    int i = 0;
    while (i < N) {
        printf("Ingrese el elemento %d : ", i + 1);
        scanf(" %c", &a[i]);
        a[i] = tolower(a[i]); 
        i++;
    } 
}

bool hay_mas_de_2_consonantes(char a[], int tam) {
    int consCont = 0;
    int i = 0;
    while(i < tam) {
        if (a[i] >= 'a' && a[i] <= 'z' && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u') { 
            consCont++;
        }
        i = i + 1;
    }   
    if (consCont > 2)  {
        return true;
    }   else {
        return false;
    }
}

int main (void) {
    assert(N > 0);
    char a[N];
    llena_con_char(a, N);

    bool respuesta = hay_mas_de_2_consonantes(a, N);

    if(respuesta == true) {
        printf("Hay al menos 2 consonantes en el arreglo");
    }   else {
        printf("No hay mas de 2 consonantes en el arreglo");
    }

    return 0;
}