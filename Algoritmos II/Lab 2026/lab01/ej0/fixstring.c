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

    if (strS1 != strS2) {
        isEq = false;
    };

    if ((strS1 == 0) && (strS2 == 0)) {
        isEq = true;
    }
    return isEq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    // s1[i] <= s2[i] === true
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }

   return s1[i] <= s2[i];
}