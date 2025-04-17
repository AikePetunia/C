#include <stdio.h>
#include <stdbool.h>
#define N 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    int i = 0;
    struct bound_data resultados;
    resultados.is_upperbound = false;
    resultados.is_lowerbound = false;
    resultados.exists = true;
    resultados.where;
    while (i < length) {
        if (value >= arr[i]) {
            resultados.is_upperbound = true;
        }
        else {
            resultados.is_upperbound = false;
        }

        if (value <= arr[i]) {
            resultados.is_lowerbound = true;
        }
        else {
            resultados.is_lowerbound = false;
        }

        if (value == arr[i]) {
            resultados.exists = true;
            resultados.where = i;
        }
        i++;
    }
    return resultados;

};

int main (void) {
    struct bound_data resultados;
    int arr[N];
    int i;
    int value;
    
    printf("Ingrese el arreglo");

    while (i < N) {
        printf("elemento %d: ", i);
        scanf("%d", &arr[i]);
        i++;
    }

    printf("ingrese un valor: ");
    scanf("%d", &value);

    //int arr[4] = {0, -1, 9, 4};

    resultados = check_bound(value, arr, 4);
    printf("%d \n", resultados.is_upperbound); 
    printf("%d \n", resultados.is_lowerbound); 
    printf("%d \n", resultados.exists);        
    printf("%u \n", resultados.where);         
    return 0;
}