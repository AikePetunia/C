#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t string_length(const char *str) {
    int length = 0; 
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char *string_filter(const char *str, char c) {
    char *result;
    result = malloc(string_length(str) + 1); // según tamaño del arreglom, se aloja el tamaño del resultado.  
    int i = 0;
    int j = 0;
    if (string_length(str) == 0) { // caso base
        result[0] = '\0';
        return result; 
    }
    while(str[i] != '\0') { // no finaliza
        if (str[i] != c) { // si es distinto, no se copia el char al arreglo
            result[j++] = str[i];
        }
        i++;
    }
    result[j] = '\0';
    return result; 
}

bool string_is_symmetric(const char *str) {
    //"aba", "abcba", "a", ""
    int tail = string_length(str) -1;
    int head = 0;
    bool isSymmetric = false;
    if (string_length(str) == 0 || string_length(str) == 1) {
        isSymmetric = true;
        return isSymmetric;
    }

    while (str[head] == str[tail]) {
        isSymmetric = true;
        head++;
        tail--;
    }
    return isSymmetric;
}

/* 
gcc -Wall -Werror -Wextra -pedantic -std=c99 main.c strfuncs.c 
a.out
*/