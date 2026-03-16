/*
  @file ranking.c
  @brief Implements store structure and methods
*/
#include <stdlib.h>
#include "ranking.h"
#include <string.h>

static const int NUMBER_OF_RANKING_VARS = 6;

Ranking ranking_from_file(FILE *file) {

    Ranking ranking;
    int a,b,c;
    char d[20], e[20];
    float f;
    // Para la lectura de strings usando fscanf() existe el comodín %s que puede
    // utilizar. Tener en cuenta que el parámetro asociado si es un arreglo va sin el '&'
    // (pueden consultar al docente para dudas sobre esto).
    int res = fscanf(file,EXPECTED_RANKING_FILE_FORMAT,&a,&b,&c,d,e,&f);

    if (res != NUMBER_OF_RANKING_VARS) {
      fprintf(stderr, "invalid ranking type");
      exit(EXIT_FAILURE);
    }

    strcpy(ranking.name,d);
    strcpy(ranking.team,e);

    ranking.pos = a;
    ranking.pos_prev = b;
    ranking.diff = c;
    ranking.points = f;
    return ranking;
}

// cambiado el tipo por que se tratan de floats los puntos, no de ints
float total_track_points_per_team(RankingTable a, char *team_name) {
    unsigned int points = 0.0;
    type_t type;
    int j = 0;
    while ((type = 1) && (j < NO_PLAYERS)) {
        for (unsigned int i = 0; i < NO_PLAYERS; i++) {
            //  usar strcmp(string1, string2) == 
            if ((strcmp(team_name, a[i][j].team) == 0) && (j == 1)) {
                // printf("se coincidio el nombre del equipo con el buscado");
                points = points + a[i][j].points;
            }
        }
        j++;
        // printf("se terminó el primer bucle while \n");
    }
    // printf("se termino el bucle while en busca de el equipo \n");
    return points;
}