#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
   int i = 0;
   int countLength = 0;
   while (s[i] != '\0') {
    i++;
    countLength++;
   }
    printf("lenght de string %d", countLength);
   return countLength;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    int strS1 = fstring_length(s1);
    int strS2 = fstring_length(s2);
    bool isEq = false;

    int i = 0;

    if (s1[i] != s2[i]) {
        isEq = false;
    } else {
        while ((strS1 == strS2) && ((s1[i] != '\0') || (s2[i] != '\0'))) {
            if(s1[i] == s2[i]) {
                isEq = true;
            } else {
                isEq = false;
            }
            i++;
        }
    }

    if ((strS1 == 0) && (strS2 == 0)) {
        isEq = true;
    }

    printf("los strings son iguales? %d \n", isEq);
    return isEq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    // s1[i] <= s2[i] === true
    int i = 0;
            printf("asd lesseq");


    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }

   return s1[i] <= s2[i];
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    printf("\n swapped: %s %s \n", s1, s2);

    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1); // aux = s1
    fstring_set(s1, s2); // s1 = s2
    fstring_set(s2, aux); // s2 = aux
    printf("terminado de swappear s1, s2");
    /*
    same as:
    tmp = a[i];
    a[i] = a[j];
    a[i] = tmp;
    */
}



/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c fixstring.c main.c sort.c sort_helpers.c 
gcc -Wall -Wextra -std=c99 array_helpers.o fixstring.o main.o sort.o sort_helpers.o -o word_sorter
./word_sorter input/example-easywords.in
*/