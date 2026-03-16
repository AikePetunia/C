/*
  @file cell.c
  @brief Implements cell information structure and methods
*/
#include <stdlib.h>
#include <assert.h>
#include "cell.h"
#include "ansicolors.h"
#include "array_helpers.h"

static const int AMOUNT_OF_ITEMS = 3 ;

#define ANSI_SHOT ANSI_RED_BG
#define ANSI_NORMAL ANSI_WHITE

cell_t cell_from_file(FILE* file)
{
    printf("se accedio a la funcion de cell_from_file(); \n");
    cell_t cell;
    char symbol;
    int k_status;
    unsigned int round;
    int res = fscanf(file, EXPECTED_CELLDATA_FORMAT, &symbol, &k_status, &round);

    // dependiendo de cuantos items recibimos
    printf("verificando la cantidad de items recibidos... \n");
    if (res != AMOUNT_OF_ITEMS) {
        fprintf(stderr, "Invalid amount of items received (all) \n");
        exit(EXIT_FAILURE);
    }

    // los estados son 1 o 0
    printf("verificando k_status... \n");
    if (k_status != 1 && k_status != 0) {
        fprintf(stderr, "Invalid status (k_status) \n");
        exit(EXIT_FAILURE);
    }

    // los simbolos son 'w' o 's'
    printf("checkeando los simbolos... \n");
    if (symbol == 'w') {
        cell.content = water;
    } else if (symbol=='s') {
        cell.content = ship;
    } else {
        fprintf(stderr, "Invalid content received (cell.content) \n");
        exit(EXIT_FAILURE);
    }

    printf("checkeando los estados... \n");
    if (k_status != untouched && k_status != hit) {
        fprintf(stderr, "Invalid content received (k_status) \n");
        exit(EXIT_FAILURE);
    } else {
        cell.status = k_status;
    }

    printf("checkeando el numero de ronda... \n");
    if (round > MAX_ROUNDS) {
        fprintf(stderr, "Error round value.\n");
        exit(EXIT_FAILURE);
    }  else {
        cell.round = round;
    }
    return cell;
}

void cell_dump(cell_t cell) {
    printf("%-5s [%-9s] (round %2d)", cell.content==water? "water":
                                      cell.content==ship ? "ship":
                                                           "?????", 
                                      cell.status==untouched ? "untouched":
                                      cell.status==hit       ? "hit!":
                                                               "?????????", 
                                      cell.round);
    printf(" | raw content: (%d,%d,%u) ", cell.content, cell.status, cell.round);
}

void cell_draw(cell_t cell, unsigned int round) {
    assert((cell.content==water || cell.content==ship) &&
           (cell.status==untouched || cell.status==hit));
    if (cell.status==untouched || cell.round > round) {
        printf(ANSI_NORMAL "%c", cell.content==water?' ':'#');
    } else {
        printf(ANSI_SHOT "%c", cell.content==water?' ':'#');
    }
}

