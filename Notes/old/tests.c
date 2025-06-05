#include <assert.h>
#include <stdio.h>

int main () {
int x;
int xInput;
    printf("Ingrese un entero positivo\n");
    scanf("%d",&xInput);
    x = xInput;
    assert(xInput > 0  && x == xInput);
    while ( x < 10){
        x = x + 1;
    }
    assert( x >= 10 );
    }