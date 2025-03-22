#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }

    return (s1[i] == s2[i]); 
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    // fstring_less_eq() indica si la cadena guardada en s1 es menor o igual que la guardada en s2 en el sentido del orden alfabético.
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] <= s2[i]) {
        i++;
    }

    return (s1[i] <= s2[i]);
}

