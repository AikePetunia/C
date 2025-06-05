#include <stdio.h>
#include <string.h>

struct Player 
{
    char name[12];
    int score;

};

typedef struct  
{
    char name[25];
    char password[12];
    int id;
} User ; // el nombre en un struct de Typedef va al final

struct student
{
    char sName[12];
    float gpa;
};

enum Day {
    SUNDAY,     //manten el mouse en cualquier variable
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};


int main () {
    // struct = "collecion de algunas variables" con diferente tipos de datos en un solo bloque de memoria
    // agrupar diferentes variables (de tipos posiblemente diferentes) bajo un mismo nombre
    // similar a "CLASSES" de otros lenguajes, pero no metodos
    // en C, las estructuras no pueden tener métodos, solo datos.
    
    struct Player player1;
    struct Player player2;

    strcpy(player1.name, "Vicky");       //el . es member access operator
    player1.score = 4;

    strcpy(player2.name, "Aike");       //el . es member access operator
    player2.score = 6;

    printf("%d ", player1.score);
    printf("%s\n", player1.name);

    printf("%d ", player2.score);
    printf("%s\n", player2.name);

    //typedef = Basicamente lo que hace es asignar una variable con cierta cantidad de bytes para cuando necesite de nuevo la variable, sea llamada.
    // en vez de escribir varias veces char user1[25] = "X"; puedo hacer un typedef char user[25]; y despues para cada user hacer "user user1 = "x"
    // typedef + Struct = good

    User user1 = {"Ana", "passwor3d123", 1231421};
    User user2 = {"Vick", "1password123", 12314111};

    printf ("%s \n", user1.name);
    printf ("PASS:%s\n", user1.password);
    printf ("ID: %d \n", user1.id);
    printf ("\n");

    printf ("%s \n", user2.name);
    printf ("PASS: %s \n", user2.password);
    printf ("ID: %d \n", user2.id);
    printf ("\n");

    // lista de structs

    struct student Estudiante1 = {"Manuel", 3.0};
    struct student Estudiante2 = {"Aja", 5.0};
    struct student Estudiante3 = {"Ajo", 2.0};

    struct student students[] = {Estudiante1, Estudiante2, Estudiante3}; // la lista de structs

    for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++)
    {
        printf("%-12s\n", students[i].sName);
        printf("%.2f\n", students[i].gpa);

    }

    // enum = , se pueden declarar adentro o afuera de main() lo hace mas legible. "Enumerados en orden".
    // Un enum (abreviatura de "enumeración") es un tipo de datos en C que permite definir un conjunto de constantes con nombre
    // Valores Enteros: Internamente, los identificadores en un enum se representan como valores enteros.
    //Valores Explícitos: Puedes asignar valores explícitos a algunos o todos los identificadores.
    // se "interpretan como ints"

    enum Day today = FRIDAY;

    printf ("%d", today);

    if (today == SUNDAY || today == SATURDAY) // en vez de ponerlos por int, onda today == 7 pones today == SATURDAY y es como neuronal activation
    {
        printf("\nfindesemana");
    } else {
        printf("\nnoesfindesemana");
    }

    /*
    Un arreglo o vector (en inglés, array) es una estructura de datos que permite almacenar una colección de elementos del mismo tipo.
    En general, un arreglo se declara de la siguiente manera:
    
    tipo nombreArreglo[tamaño];
    
    donde 'tipo' indica el tipo de los elementos del arreglo y 'tamaño' es la cantidad de elementos que el arreglo puede contener.
    Por ejemplo:
    
    int numeros[4];  // declara un arreglo de 4 elementos de tipo entero.
    bool flags[2];   // declara un arreglo de 2 elementos de tipo booleano.
    
    La cantidad de elementos de un arreglo es igual al valor especificado en 'tamaño'. 
    Es posible declarar arreglos vacíos, aunque no es común en C.
    
    No es necesario que el primer índice del arreglo sea 0, pero en C, los arreglos siempre comienzan en el índice 0.
    Un elemento de un arreglo se referencia por su índice, por ejemplo:
    
    numeros[0] = 10; // asigna el valor 10 al primer elemento del arreglo 'numeros'.
    
    Diremos que un valor 'v' está en el arreglo si algún elemento del arreglo es igual a 'v'.
    
    Es posible usar variables cuantificadas en relación a arreglos.
    Por ejemplo, si tenemos un arreglo de enteros 'a' de tamaño 'n', podemos encontrar el máximo elemento del arreglo con:
    
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    */

    return 0;
}