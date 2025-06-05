#include <stdio.h>
#include <stdlib.h> // <- For malloc()
void printAge(int *pAge) // por que paso pAge
{
    printf("Age: %d \n", *pAge); //deference
}

int main () {

    // PUNTEROS = Guardan la dirección de memoria de una variable, lista, etc.

    // Son más eficientes en ciertos casos porque permiten el acceso directo a la memoria. 
    // Ahorra tiempo, trabaja con la variable original, se puede crear estructura de datos, retorna mas de un valor de otras funciones, 
    //busca y filtra informacion grande muy facil, locacion de memoria dinamica
    // * = operador de indirección (accede al valor en la dirección de memoria)

    int age = 21;
    int *pAge = NULL;   //deben ser el mismo tiempo de var. BUena practica usar NULL declarando puntero
    pAge = &age;

    printf("Adress age: %p \n ", &age); // */*
    printf("Value  pAge: %p \n\n ", &pAge); 

    printf ("size of age: %d bytes\n", sizeof(age));
    printf ("size of pAge: %d bytes\n\n", sizeof(pAge));
    
    printf("Value of age: %d \n", age);
    printf("Value  at stored adress: %p \n ", *pAge);  //deferencing

    //podemos guardar en una variable el lugar de  memory Adress ( */* )

    //se puede pasar un puntero como un argumento a una funcion
    // el sizeof() de una estrucutra es >= a la suma del sizeof() de sus miembros
    printAge(pAge);

    /* 
        Sobre padding: https://www.youtube.com/watch?v=of2kZkUDApw&list=PLLfC2vEod54J7vzFIeX23iyaSAjFhevQV&index=8&t=240s 
        typedef struct {
            char name[30];   // 30 bytes
            int age;         // 4 bytes (requiere alineación de 4)
            int height;      // 4 bytes
        } data_t;
    name: empieza en offset 0 → ocupa del 0 al 29 (30 bytes).

    age: empieza en offset 30 → pero ¡30 no es múltiplo de 4!

        Solución: el compilador mete 2 bytes de padding después de name → ahora age empieza en 32.

    age: ocupa 4 bytes (32 a 35)

    height: empieza en 36, ocupa hasta 39.

        */

    // Malloc() = memory allocation 
    /* 
        #include <stdlib.h> <- For malloc()
        Una funcion en c que aloja dinamicamente un numero de bits en memoria
    */
    int number = 0;
    printf("Introduce un numero para el largo del arreglo");
    scanf("%d", &number);
    // si falla el malloc, retornará null y dara Segmention Fault
    
    char *grades = malloc(number * sizeof(char)); // numero de bytes reservado por el puntero en la memoria
    
    if (grades == NULL) {
        printf("Malloc failed \n" );
        return 1;
    } 

    for (int i = 0; i < number; i++) {
        printf("enter grade #%d", i+1);
        scanf(" %c", &grades[i]);
    }

    for (int i = 0; i < number; i++) {
        printf(" %c", grades[i]);
    }

    free(grades); // liberemas el espacio ocupado por Grades
    grades = NULL; // reseteamos el valor de grades. Prevee "Dangling pointers"

    // cuando la memoria se reserva, se le conoce como "Heap" <-- Rentamos espacio de acá
    // Cuando usamos memoria, viene de "Stack"
    //Escribiendo archivos.

    /*
    FILE *pFA = fopen("text.txt", "w"); //para rutas, tenes absolutos y relativos.

    //creo archivo y lo abro, la extension cambia. Primer argumento, nombre, segundo, tipo:
    // w, escribir, a, append y r, read 

    fprintf(pFA, "\nholahola"); //si cambio el texto se sobre escribira, si hago append solo pasara el renglon (\n)

    fclose(pFA); //es mejor tener archivos cerrados para no causar problemas

    */
    
    /*

        //eliminar archivos

        if(remove("text.txt") == 0) 
        {
            printf("Eleminado.");
        } else {
            printf("no eliminado");
        }

    */

   // leer archivos

    FILE *pF = fopen("text.txt", "r"); //para rutas, tenes absolutos y relativos.
    char buffer[255];
    fgets(buffer, 255, pF); // buffer = donde se inserta la linea del text, 255 = bytes, pF = puntero

    printf("%s", buffer); //lee la primera linea de texto, para que lea todo, debe:

    if (pF == NULL) //vemos si el archivo existe
    {
        printf("no existe tal archivo");
    }   else {
        while (fgets(buffer, 255, pF) != NULL) 
    {
        printf("%s", buffer);    
    }
    }

    

    fprintf(pF, "\nholahola"); //si cambio el texto se sobre escribira, si hago append solo pasara el renglon (\n)

    fclose(pF); //es mejor tener archivos cerrados para no causar problemas


    return 0;
}