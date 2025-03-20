#include <math.h>
#include <stdio.h>


int main () {

    char operator;
    long int number1;
    long int number2;

    printf ("Escriba el operador a usar \n 1. Sum \n 2. Substraction \n 3. Multiplication \n 4. Division\n ");
    scanf ("%c", &operator);

    switch (operator) {
    case 1:
        printf("Por favor, dame el primer número para operar la Suma: ");
        scanf("%ld", &number1);
        printf("Por favor, dame el segundo número para operar la Suma: ");
        scanf("%ld", &number2);
        printf("Resultado: %ld\n", number1 + number2);
        break;
    case 2:
        printf("Por favor, dame el primer número para operar la Resta: ");
        scanf("%ld", &number1);
        printf("Por favor, dame el segundo número para operar la Resta: ");
        scanf("%ld", &number2);
        printf("Resultado: %ld\n", number1 - number2);
        break;
    case 3:
        printf("Por favor, dame el primer número para operar la Multiplicación: ");
        scanf("%ld", &number1);
        printf("Por favor, dame el segundo número para operar la Multiplicación: ");
        scanf("%ld", &number2);
        printf("Resultado: %ld\n", number1 * number2);
        break;
    case 4:
        printf("Por favor, dame el primer número para operar la División: ");
        scanf("%ld", &number1);
        printf("Por favor, dame el segundo número para operar la División: ");
        scanf("%ld", &number2);
        if (number2 != 0) {
            printf("Resultado: %ld\n", number1 / number2);
        } else {
            printf("Error: División por cero no es permitida.\n");
        }
        break;
    default:
        printf("Por favor, dame un operador válido.\n");
        break;
    }
}