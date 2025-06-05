#include <stdio.h>
#include <stdbool.h>
#include <string.h>


// Definiciones de funciones
void milanesa(char name[], int age) {
    printf("\nSoy una milanesa");
    printf("\nSoy una milanesa %s", name);
    printf("\nSoy una milanesa DE CARNE y tiene %d", age);
    printf("\nSoy una milanesa");
}

double square(double x) {
    return x * x;
}

int findMax(int x, int y) {
    // Operador ternario: (condición) ? valor_si_verdadero : valor_si_falso
    return (x > y) ? x : y;
}

// Declaraciones de funciones
void hello(char name[], int age);

int main() {
    // Operadores lógicos
    // AND (&&): Verifica si ambas condiciones son verdaderas
    // OR (||): Verifica si al menos una condición es verdadera
    // NOT (!): Niega el valor de una condición

    float temp = 25;
    bool sunny = false;
    bool dragon = true;

    if ((temp >= 0 || temp <= 30) && sunny == true && !dragon) {
        printf("No te congelaras\n");
    } else {
        printf("Está mal la temperatura\n");
    }

    // Llamada a funciones
    char name[] = "Aike";
    int age = 18;

    milanesa(name, age);  // Argumentos para la función
    double x = square(33233);

    // Imprime el resultado de la función square
    printf("El cuadrado de 33233 es: %lf\n", x);
    printf("El cuadrado de %lf es: %lf\n", x, square(x));

    // Operador ternario
    // Atajo de if/else para asignar valores basados en una condición
    int max = findMax(3, 4);
    printf("El máximo entre 3 y 4 es: %d\n", max);

    // Uso de prototipo de función
    char name1[] = "Aike1";
    int age1 = 183;
    hello(name1, age1);

    // Manipulación de cadenas
    // Necesario #include <string.h>
    char string1[] = "aikE";
    char string2[] = "milanEsa";

    strlwr(string1);                             // Pasa a minúsculas
    printf("Minúsculas: %s\n", string1);

    strupr(string1);                             // Pasa a mayúsculas
    printf("Mayúsculas: %s\n", string1);

    strcat(string1, string2);                    // Concatena strings
    printf("Concatenado: %s\n", string1);

    strncpy(string1, string2, 4);                // Copia n caracteres
    printf("Copiados 4 caracteres: %s\n", string1);

    strset(string1, '?');                        // Cambia todos los caracteres a '?'
    printf("Set de caracteres: %s\n", string1);

    strnset(string1, 'x', 1);                    // Cambia el primer carácter a 'x'
    printf("Set de un carácter: %s\n", string1);

    strrev(string1);                             // Invierte el string
    printf("Invertido: %s\n", string1);

    int result = strlen(string1);                // Longitud del string
    printf("Longitud: %d\n", result);

    int result1 = strcmp(string1, string2);      // Compara strings
    printf("Comparación: %d\n", result1);

    int result2 = strncmp(string1, string2, 1);  // Compara n caracteres
    printf("Comparación de n caracteres: %d\n", result2);

    int result3 = strcmpi(string1, string1);     // Compara strings ignorando mayúsculas y minúsculas
    printf("Comparación ignorando mayúsculas: %d\n", result3);

    int result4 = strnicmp(string1, string1, 1); // Compara n caracteres ignorando mayúsculas y minúsculas
    printf("Comparación de n caracteres ignorando mayúsculas: %d\n", result4);


    // Para acceder, por ejemplo, a elementos pares en una lista A, hago:
   void imprimirElementosPares(int arr[], int longitud) {
    printf("Elementos en posiciones pares:\n");
    for (int i = 0; i < longitud; i++) {
        if (i % 2 == 0) {
            printf("%d ", arr[i]); // Imprime el elemento en posición par
        }
    }
    printf("\n");
    }

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int longitud = sizeof(arr) / sizeof(arr[0]); // Calcula el tamaño de la lista

    imprimirElementosPares(arr, longitud);

    return 0;
    }
    // FOR LOOPS
    // hasta que se llegue a una condicion
    for (int i = 1; i<=10; i++ ) //alternativamente i
    {
        printf("%d\n", i);
    }

    // WHILE LOOPS
    // Hasta que una condicion se de verdadera o falsa
    
    char name3[25];

    printf("\n como t llama");
    fgets(name, 25, stdin);
    name[strlen(name) -1] = '\0';

    while (strlen(name) == 2) 
    {
        printf("pone el nombre uwu");
        printf("\n como t llama");
        fgets(name, 25, stdin);
        name[strlen(name) -1] = '\0';
    }

    printf ("hello %s", name);

    // do while loops -> ejecuta una vez un bloque de codigo, checkea una condicion
    // y luego hara la condicion dada caso negativo, sigue de largo.

    int number3 = 0;
    int sum = 0;

    
    do{
        printf ("\nescriba un numero");
        scanf("%d", &number3); //almacena el dato en la var 3.
        if (number3 > 0) 
        {
            sum += number3;
        }
    } while (number3 > 0);

    printf("sum: %d", sum);

    //nested loops -> loop en un loop (raiz de loop)

    int rows;
    int columns;
    char symbol;

    printf("\n\n escriba numero de lineas: ");
    scanf("%d", &rows);
    
    printf("\n escriba numero de columnas: ");
    scanf("%d", &columns);
    scanf("%c");

    printf("ingrese un simbolo:");
    scanf("%c", &symbol);

    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= columns; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }


    // continue & breaks on loops

    for (int i = 1; i <= 20; i++) 
    {
        if (i == 13)
        {
            continue;               //SKIPEA EL NUMERO 13
            // break;  SI Y SI SOLO SI QUEREMOS QUE SE CORTE EN EL NUMERO 13
        }
        printf("%d\n", i);
    }
    return 0;

    
}

void hello(char name1[], int age1) {
    printf("\n soy una milanesa %s", name1);
    printf("\n soy una milanesa DE CARNE y tiene %d", age1);
}


