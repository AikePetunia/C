#include <stdio.h>
#include <stdbool.h>

int main() {

    /*
    Sobre C: 
    - Es un lenguaje imperativo.
    - Es destacado por su nivel de eficiencia.
    - Es débilmente tipado de medio nivel.
    - Es “Case Sensitive”.
    - Se adopta el estándar (ISO/IEC 9899:1990) que lo hace multiplataforma.
    
    ¡En lenguaje C, no existe la asignación múltiple!
    Debemos tener cuidado cómo traducimos para que se respete la semántica del programa,. Es decir, tengan estados equivalentes (el valor de las variables sean los mismos).

    Esta librería implementa "assert" para determinar el cumplimiento de asunciones en el programa.
    Evalúa el cumplimiento del predicado que se le da como argumento y si no se cumple, se aborta el programa.

    #include <assert.h>
    ...
    assert (i != 4);

    En caso de ingresar datos que incumplen la aserción:
    "main: main.c:7: main: Assertion `i != 4' failed. Aborted"
    Puede usarse para comprobar que una pre-condición se satisface antes de llamar a una función
    Puede usarse para comprobar que una postcondición se satisface después de llamar a una función
    Para cualquier otra suposición que estemos seguros que se tenga que cumplir (caso contrario, el programa no tiene sentido que continúe)

    #include <limits.h>
    ...
    printf("The minimum value of INT = %d\n", INT_MIN);

    Esta librería define los valores máximos y mínimos de los tipos básicos de C
    Podemos utilizarla por ejemplo, para cuando en una derivación necesitamos utilizar -∞ o +∞
    Como usarla:

    */

    // Comentarios
    // Así se comenta en una línea
    /*
    Múltiples
    comentarios
    */

    /*
    \n = nueva línea en un print u otros
    \t = espacios tipo tab en los textos
    */
    printf("ESTO ES UN GRID DE NUMEROS \n");
    printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n");
    printf("ESTO ES UN GRID DE NUMEROS\n");

    /*
    Para imprimir comillas, se debe usar la barra invertida (\)
    */
    printf("yo comi una \"hamburguesa\" ayer\n");

    // Variables

    int number1; // Declaración
    number1 = 5; // Inicialización

    // Alternativamente

    // Números 
    int number = 5;                        // 4 Bytes (-2b to 2b+)                                  %d
    unsigned int number8 = 4294967295;     // 4 bytes (0 to 4b) %u
    long long int number9 = 3123333333;    // 8 bytes (-9q to 9q) %lld
    unsigned long long int number10 = 414; // 8 bytes (0 to 18q) %llu
    short int number5 = 32767;             // 2 bytes (-32,768 a +32,767)                             %d
    unsigned short int number6 = 65535;    // 2 bytes (0 a +65,535)                                   %d
    short number7 = 32767;                 // 2 bytes (-32,768 a +32,767) (no necesario declarar int) %d
    unsigned short number123 = 65535;      // 2 bytes (0 a +65,535) (no es necesario declarar int)    %d

    float number4 = 2.3123123514512;       // Decimal, 4 bytes (32 bits de precisión) 6-7 dígitos     %f
    float number2 = 2.04;                  // Decimal, 4 bytes (32 bits de precisión) 6-7 dígitos     %f
    double number3 = 2.3123123514512;      // Decimal, 8 bytes (64 bits de precisión) 15-16 dígitos   %lf

    printf("%0.15f FLOAT NORMAL CON MUCHOS NUMEROS, se pierde precisión con muchos dígitos\n", number4);
    printf("%0.15lf LONG FLOAT CON capacidad de manejar más dígitos\n", number3);
    printf("%f float normal\n", number2);

    // Booleans
    // Se necesita declarar al inicio (antes de usarse) #include <stdbool.h>

    bool t = true;   // 1 Byte, trabajan en binario 1 = True, 0 = False    %d
    bool f = false;  // 1 Byte, trabajan en binario 1 = True, 0 = False    %d    
    printf("%d, %d,\n1 = True, 0 = False\n\n", t, f); 

    // Caracteres o strings

    char grades = 'F';             // Char, un caracter                                              %c
    char name[] = "Aike";          // Strings o lista de caracteres                                  %s
    char numerito1 = 100;          // 1 byte (-128 a +127)                                           %d o %c
    signed char numerito2 = 100;   // 1 byte (-128 a +127) (realmente innecesario, ya están todos signed)
    unsigned char numerito3 = 255; // 1 byte (0 a +255)                                              %d o %c

    printf("Char con números según el ASCII, si uso \"%c\" se usa un caracter según ASCII, y \"%d\" será un número\n\n");
    printf("Esto es un caracter \n%c\nArte ASCII según tabla\n%d\nNúmero normal\n\n", numerito1, numerito1);

    printf("Tengo %d años, me llamo %s, la nota que tengo es %c, y sin redondeo es %.2f\n\n\n\n\n", number, name, grades, number2); 
    
    /* El %d es para enteros
    (se especifica el tipo, y después las variables que van en el print serán en orden)
    No hay espacios para unir los strings con +
    Para los strings, no es necesario poner el [], pero sí el %s de String
    */

    /* Otros format specifier (%)
    %.1 = Decimal pecision              <- Cantidad de decimales que apareceran de un float
    %1 = minimum field width            <- espacio en blaco despues de algo )? $    1.00
    %- = Left align                     <-
    */

    // Constantes <- variable no alterable

    const float pi = 3.14159;

    // ARITMETICA

    /*
    + Adición
    - Resta
    * Multiplicación
    % Módulo
    / División
    ++ Incremento
    -- Decremento 
    */

    int sum = 5; 
    sum++;
    int min = 2;
    min++;
    int operation = 5 - 2; 
    int division = 5 / (float) 2;   // Se puede hacer así. No se guarda el resto ni habrá display de un decimal si no es FLOAT, es con módulo
    float division1 = 5 / 2;        // Se puede hacer así

    printf("%d\n", operation);

    // El "atajo aritmético" funciona con todos los operadores
    
    int x = x + 1;
    // En su lugar
    x += 1;

    int z = z + 2;
    // En su lugar 
    z -= 2;

    return 0;
}
