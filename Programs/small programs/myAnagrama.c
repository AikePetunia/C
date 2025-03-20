#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
 * Escribe una función que reciba dos palabras (String) y retorne
 * verdadero o falso (Bool) según sean o no anagramas.
 * - Un Anagrama consiste en formar una palabra reordenando TODAS
 *   las letras de otra palabra inicial.
 * - NO hace falta comprobar que ambas palabras existan.
 * - Dos palabras exactamente iguales no son anagrama.
 */

bool checkearAnagrama(char *palabra1, char *palabra2); 

int main () {

    char palabra1[] = "oso"; //se debe checkear cada letra
    char palabra2[] = "oso";

    if(checkearAnagrama(palabra1, palabra2)) {
        printf("Anagrama\n");
    }
    else {
        printf("no agram\n");
    }
    return 0;
}

bool checkearAnagrama (char *palabra1, char *palabra2) 
{
    if (strcmp(palabra1, palabra2) == 0) {
    return false;
    }
    //si no tienen la misma cantidad de letras, no son anagramas de entrada
    if (strlen(palabra1) != strlen(palabra2)) {
        return false;
    }
    int len1 = strlen(palabra1);        
    int len2 = strlen(palabra2);

    // se debe checkear, que contiene las mismas letras

    int contadorPalabra1[26] = {0}; //26 letras en el abcdario
    int contadorPalabra2[26] = {0};

    //cuenta el numero de letras de a-z en palabra1
    for (int i = 0; i < len1; i++)
    {
        // Por arte ascii
        int lower = tolower(palabra1[i]);
        contadorPalabra1 [ lower - 'a']++; //recorre TODAS las letras
    }

    for (int i = 0; i < len2; i++)
    {
        // Por arte ascii
        int lower = tolower(palabra2[i]);
        contadorPalabra2 [ lower - 'a']++;
    }

     for (int i = 0; i < 26; i++) 
    {
        if (contadorPalabra1[i] != contadorPalabra2[i])return false;
    }

    return true;
}; 