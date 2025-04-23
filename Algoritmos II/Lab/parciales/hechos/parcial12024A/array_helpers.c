/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "character.h"

void array_dump(CharacterList array) {
  for (alignment_t alignment=good; alignment<CHARACTER_ALIGNMENTS; ++alignment) {
    for (charttype_t charttype=physical; charttype < CHARACTER_TYPES; ++charttype) {
      Character character = array[charttype][alignment];

      char *str_alignment = (character.alignment == good) ? "Good" : "Evil";
      char *str_alive = (character.alive) ? "Yes" : "Nope";

      fprintf(stdout,
              "Character '%s': Life=%u/100, Strength=%u/10, Agility=%u/10, "
              "alignment='%s', Alive='%s'\n",
              NAMES[character.name], character.life, character.strength,
              character.agility, str_alignment, str_alive);
    }
  }
}
float array_alive_mean_life(CharacterList array) {
  /*
    *  Calcula la suma de las vidas de todos los personajes vivos, divide la suma 
    * entre el número de personajes vivos y devuelve el resultado. Si no hay
    * personajes vivos, devuelve 0.
  */
  float total_life = 0;
  unsigned int count_alive = 0;
  // characterList arrays of = CharacterList[CHARACTER_TYPES][CHARACTER_ALIGNMENTS]
  for(int i = 0; i < CHARACTER_TYPES; i++) {
    for(int j = 0; j < CHARACTER_ALIGNMENTS; j++) {
      if (array[i][j].alive) {
        count_alive++;
        total_life += array[i][j].life;
      }
    }
  }

  printf("cantidad de personas vivas: %d \n", count_alive);
  printf("cantidad de vida del equipo (promedio): %f \n", total_life);

  return (total_life != 0 ? (total_life / count_alive) : 0);

}
unsigned int array_from_file(CharacterList array, const char *filepath) {
  FILE *file = NULL;

  // check if file exists
  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  // read the file
  unsigned int readed = 0;
  while (!feof(file)) {
    charttype_t charttype; // convierte el caracter de [a e] a strings
    alignment_t alignment;

    char s_charttype, s_alignment;

    int res=fscanf(file, " [%c %c] " , &s_charttype, &s_alignment);
    if (res != 2) {
        fprintf(stderr, "Error reading type and alignment.\n");
        exit(EXIT_FAILURE);
    }
    
    /* error handling, "robusto" */
    if (s_charttype != 'a' && s_charttype != 'p' && s_charttype != 'm' && s_charttype != 't') {
      fprintf(stderr, "not a valid charttype.\n");
      exit(EXIT_FAILURE);
    }

    if (s_alignment != 'g' && s_alignment != 'e') {
      fprintf(stderr, "not a valid aligment.\n");
      exit(EXIT_FAILURE);
    }

    charttype = (s_charttype == 'a' ? agile : (s_charttype == 'p' ? physical : (s_charttype == 't' ? physical : (s_charttype == 'm' ? magic : ' '))));
    alignment = (s_alignment == 'g' ? good : evil);
    /* convertir la letra de `s_charttype` en un valor `charttype_t` y asignarlo
     * a la variable  `charttype`:
     *
     * 'a' --> agile
     * 'p' --> physical
     * 't' --> tank
     * 'm' --> mage
     *
     */
    
     /* error handling, "robusto" */
    /* convertir la letra de `s_alignment` en un valor `aligment_t` y asignarlo
     * a la variable  `alignment`:
     *
     * 'g' --> good
     * 'e' --> evil
     *
     */

    name_t name = read_character_name(file);

    Character character = character_from_file_line(file, name, alignment);

    // se cargan este tipo de datos
    array[charttype][alignment] = character;
    ++readed;
  }
  /* COMPLETAR SI ES NECESARIO CON ALGUNA VERIFICACIÓN FINAL */

  // close the file
  fclose(file);

  return readed;
}
