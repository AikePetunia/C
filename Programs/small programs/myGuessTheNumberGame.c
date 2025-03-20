#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    // random numbers -> Pseudo randoms

    srand(time(0)); //se usa la hora para la raiz de el numero, si no se usa dara los mismos numeros siempre

    int number1Example = (rand() % 6) +1;   // da un numero random de 0 al 32567, para reducir el valor es  % (numero) empieza del cero (evitar con +1)
 
    printf("%d \n ", number1Example);

    // Crear un programa de adivansas de numeros, con frio si esta muy lejos, con caliente si esta muy cerca. Del 1 al 100

    int numberGuess = (rand() % 100) + 1;
    int numberUser;

    printf("\n*/*/*/*/*/*/*/*/*\n");
    printf("Guess the number!\n");
    printf("Enter the number\n");
    scanf("%d", &numberUser);
    printf("\n*/*/*/*/*/*/*/*/*\n");

    do {
        scanf("%d", &numberUser);
        if (numberUser > numberGuess) {
            printf("Too far, High number");
        } else if (numberUser < numberGuess){
            printf("Too low, lower number");
        } 
    } while (numberUser != numberGuess);
    
    printf("You won!\n");

    return 0;
}