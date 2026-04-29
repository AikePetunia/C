#include <stdio.h>

int swap(int a, int b) {
    int tmp;
    tmp = a;
    a = b; 
    b = tmp;
} 

int main() {
    int x = 10;
    int y = 12;
    printf("x: %d, y: %d \n", x, y);
    swap(x,y);
    printf("x: %d, y: %d", x, y);
}

/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 swap.c -o swap
*/