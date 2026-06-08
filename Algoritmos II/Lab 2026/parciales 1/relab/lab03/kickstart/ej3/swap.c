#include <stdio.h>

void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x = 6;
    int y = 4;
    printf("x: %d, y:%d \n", x, y);
    swap(x, y);
    printf("x: %d, y:%d \n", x, y);
}