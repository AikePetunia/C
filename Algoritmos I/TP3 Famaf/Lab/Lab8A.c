#include <stdio.h>

int main() {

    int x = 13;
    int y = 3; 
    int i = 0; 

    do {
        x = x - y;
        i = i + 1;
    } while (x >= y);
    
    printf("El resultado de la division entera es i = %d\n  x = %d\n, y = %d\n", i);
    
/*
    - **Estado Inicial (σ0):**
    - `σ01: (x → 13, y → 3, i → 0)`

    - **Después de Iteración 1 (σ1):**
    - `σ11: (x → 10, y → 3, i → 1)`

    - **Después de Iteración 2 (σ2):**
    - `σ21: (x → 7, y → 3, i → 2)`

    - **Después de Iteración 3 (σ3):**
    - `σ31: (x → 4, y → 3, i → 3)`

    - **Después de Iteración 4 (σ4):**
    - `σ41: (x → 1, y → 3, i → 4)`

    Resumen

    σ01: (x → 13, y → 3, i → 0)
    σ11: (x → 10, y → 3, i → 1)
    σ21: (x → 7, y → 3, i → 2)
    σ31: (x → 4, y → 3, i → 3)
    σ41: (x → 1, y → 3, i → 4)

*/

    // chekiado!
    return 0;
}