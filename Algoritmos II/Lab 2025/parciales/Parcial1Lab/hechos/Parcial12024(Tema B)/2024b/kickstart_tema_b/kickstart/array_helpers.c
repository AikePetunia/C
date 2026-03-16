/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

void array_dump(RankingTable a) {
    for (unsigned int ranking = 0u; ranking < NO_PLAYERS; ranking++) {
        for (unsigned int type = road; type <= track; type++) {
            Ranking aux = a[ranking][type];
            fprintf(stdout, " %u %s %i %i %s %s %f\n",
                    ranking+1, (type==0?"road":"track"), aux.pos_prev, aux.diff, aux.name, aux.team, aux.points
            );
        }
    }
}

void array_from_file(RankingTable array, const char *filepath) {
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    type_t type;

    int i = 0;
    printf("Cargando posiciones de los datos... \n");
    // si cada jugador juega en cada cat, entonces hay el doble de jugadores, pero con mismo nombre
    while (i < NO_PLAYERS * TYPES && (!(feof(file)))) {
        int res = fscanf(file," @%u ", &type);

        if ((type != 0 || type != 1) && res != 1) {
            fprintf(stderr, "invalid ranking type");
            exit(EXIT_FAILURE);
        }
        // pasamos los datos a la funcion ranking_from_file(); definida en ranking.c
        Ranking ranking_row = ranking_from_file(file);

        // si ranking_row = RankingTable[NO_PLAYERS][TYPES]
        // NO_players que sería ? numero de jugador? si es asi, sería a[i] y listo
        
        array[ranking_row.pos-1][type] = ranking_row;
        i++;
    }
    fclose(file);
}

