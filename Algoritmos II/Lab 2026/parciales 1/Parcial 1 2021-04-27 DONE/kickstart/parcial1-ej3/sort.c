/*
  @file sort.c
  @brief sort functions implementation
*/
#include <stdbool.h>
#include "helpers.h"
#include "sort.h"
#include "song.h"
#include <stdio.h>
bool is_odd(int number) {
    return (number % 2 == 1);
}

bool goes_before(song_t s1, song_t s2) {
    return s1.seconds <= s2.seconds;
}

bool array_is_sorted(song_t playlist[], unsigned int length) {
    unsigned int i = 0u;
    bool sorted = true;
    while (i + 1 < length && sorted) {
        sorted = goes_before(playlist[i], playlist[i + 1]);
        i = i + 1;
    }
    return sorted;
}

bool array_is_odd_sorted(song_t playlist[], unsigned int length) {
    bool isOddSorted = true;
    unsigned int i = 0;
    unsigned int j = 0;

    while (i < length) {
        if (is_odd(i)) {
            while(j < length) {
                if (is_odd(j) && (!goes_before(playlist[i], playlist[j]))) {
                    // printf("entre al if \n");
                    isOddSorted = false;
                } 
                j++;
            }
        }
        i++;
    }

   // printf("is oddSorted?: %d \n", isOddSorted);
    return isOddSorted;
}

