#include <stdio.h>
#include <stdbool.h> 

int main() {
    int x, y, z;
    bool b, w;

    x = x * 4;  
    y = y * -4; 
    z = z * 8;  

    b = false; 
    w = true;  

    printf("x %% 4 == 0: %d\n", x % 4 == 0);
    printf("x + y == 0 && y - x == (-1) * z: %d\n", (x + y == 0) && (y - x == (-1) * z));
    printf("not b && w: %d\n", !b && w);

    // 1 Byte, trabajan en binario 1 = True, 0 = False    %d
    // 1 Byte, trabajan en binario 1 = True, 0 = False    %d    
    //podria poner la logica en una variable y luego imprimir la variable

    //Chekiado
    return 0;
}