#include <stdio.h>



int main () {
    // bitwise operators = Operadores especiales para la programacion en bits (saber binario viene bien)

    // & = ANd
    // | = or
    // ^ = XOR
    // << = left shift
    // >> = right shift

    int x = 6; // 6 = 110
    int y = 12; // 12 = 1100
    int z = 0; // 0 = 0

    z = x & y;

    printf("and = %d\n", z);
    
    z = x | y ;

    printf("or = %d\n", z);

    z = x ^ y;

    printf("xor = %d\n", z);

    z = x >> y;

    printf("right shift = %d\n", z);

    z = x << y;

    printf("left shift = %d\n\n\n\n\n", z);

    // memory  = lista de bytes en la ram   (street)
    // memory block = una unidad (byte) en la memoria, usada para guardar algun valor (person)
    // memory adress = la direccion de donde un bloque de memoria esta asignado (house adress)

    long int a = 'x';   
    char b = 'y';
    long int c = 'z';

    printf("%d \n bytes", sizeof(a));
    printf("%d \n bytes", sizeof(b));
    printf("%d \n bytes", sizeof(c));

    //¿Ahora, donde esta ubicados? Cada coso tiene un block memoryr

    printf("\n %p \n", &a);     //es Hexadecimal, seria de 0 - 9 + A - F *discreth maths noices*
    printf("%p \n", &b);
    printf("%p \n", &c);

    //aca tiene mas sentido el cuanto ocupan las variables en la memoria
   
    return 0;
}