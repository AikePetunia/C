#include <stdio.h>
#include <ctype.h>

int main () {

    // Hacer un programa que haga conversion de grados celcius a Fahreint  y viceversa

    float celsius;
    float fahrenheit;
    int opcionUsuario;

    printf("d q quieres convertir a qué?\n 1. De Celsius a Fahrenheit \n 2. De Fahrenheit a Celsius\n");
    scanf("%d", &opcionUsuario);

    if (opcionUsuario == 2) {
        printf("qtemperatura deseas convertir a Grados celcius? ");
        scanf("%f", &celsius);
        
        float formulaCtF = (celsius * 9.0/5.0) + 32.0;

        printf("Su temperatura en Grados celcius  es: %f\n", formulaCtF);
        
    } else if (opcionUsuario == 1) {
        printf("q temperatura deseas convertir a Farenheit? ");
        scanf("%f", &fahrenheit);
         
        float formulaFtC = (fahrenheit - 32.0) * 5.0/9.0;

        printf("Su temperatura en Farenheit es: %f\n", formulaFtC);

    } else {
        printf("Porfa, introduzca un número válido!\n");
    }
    
    
    // F=(C×5/9​)+32 
    // C=(F−3/2)×5/9​   
}