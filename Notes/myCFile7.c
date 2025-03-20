#include <stdio.h>

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

    printf ( "size of age: %d bytes\n", sizeof(age));
    printf ( "size of pAge: %d bytes\n\n", sizeof(pAge));
    
    printf("Value of age: %d \n", age);
    printf("Value  at stored adress: %p \n ", *pAge);  //deferencing

    //podemos guardar en una variable el lugar de  memory Adress ( */* )

    //se puede pasar un puntero como un argumento a una funcion

    printAge(pAge);

    
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