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
  float res;
  unsigned int i,j,alive_char;
  res = 0;
  alive_char = 0;
  i = 0;
  while (i < CHARACTER_TYPES) {
    j = 0;
    while (j < CHARACTER_ALIGNMENTS) {
      if (array[i][j].alive) {
        alive_char++;
        res += array[i][j].life;
      }
      j++;
    }
    i++;
  }
  return res == 0 ? 0 : res/alive_char;
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
  while (!(feof(file))) {
    charttype_t charttype;
    alignment_t alignment;

    char s_charttype, s_alignment;
    int res = fscanf(file, " [%c %c] " , &s_charttype, &s_alignment);
    if (res != 2) {
      fprintf(stderr, "Error reading type and alignment.\n");
      exit(EXIT_FAILURE);
    }

    if (!(s_charttype == 'a' || s_charttype == 'p' || s_charttype == 't' || s_charttype == 'm')) {
      fprintf(stderr, "Invalid character type value.\n");
      exit(EXIT_FAILURE);
    }

    if (!(s_alignment == 'g' || s_alignment == 'e')) {
      fprintf(stderr, "Invalid alignment value.\n");
      exit(EXIT_FAILURE);
    }

    /* convertir la letra de `s_charttype` en un valor `charttype_t` y asignarlo
     * a la variable  `charttype`:
     *
     * 'a' --> agile
     * 'p' --> physical
     * 't' --> tank
     * 'm' --> mage
     *
     */
    
    charttype = s_charttype == 'a' ? agile : s_charttype == 'p' ? physical : s_charttype == 't' ? tank : magic;

    /* convertir la letra de `s_alignment` en un valor `aligment_t` y asignarlo
     * a la variable  `alignment`:
     *
     * 'g' --> good
     * 'e' --> evil
     *
     */

    // Reads the name and obtains an name_t value

    alignment = s_alignment == 'g' ? good : evil;

    name_t name = read_character_name(file);

    Character character = character_from_file_line(file,name,alignment);

    /* COMPLETAR: Almacenar en la tabla*/
    array[charttype][alignment] = character;
    ++readed;
  }
  if (readed != 8) {
    fprintf(stderr, "Error player ammount\n");
    exit(EXIT_FAILURE);
  }

  // close the file
  fclose(file);

  return readed;
}
