/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
/**
* @brief returns true when reach last entry in flight table
* @return True when is the last entre of the flight table, False otherwise
*/
static bool is_last_line(unsigned int hour, unsigned int type) {
  return  hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(DeliveryTable a) {
  for (unsigned int type = 0u; type < TYPE; ++type) {
    for (unsigned int hour = 0u; hour < HOURS; ++hour) {
      Flight f = a[type][hour];
      fprintf(stdout, "\n %c: flight with %u %s arrived at %u:00", f.code, f.items_amount, f.type == 0 ? "boxes" : "letters", f.hour - 1);
      if (!is_last_line(hour, type))
      {
        fprintf(stdout, "\n");
      }
    }
  }
}

unsigned int extra_space_fee_cost (DeliveryTable a) {

  int hour = 0;
  int boxes_cost = 0;
  int boxes_total = 0;
  int letter_cost = 0;
  int letter_total = 0;
  while (hour < FEE_CLOSE_HOUR)  {
    printf("a[0][hour].items_amount %d \n", a[0][hour].items_amount);
    boxes_total += a[0][hour].items_amount;
    if (boxes_total  > MAX_ALLOWED_BOXES){
      printf("supero limit \n");
      boxes_cost += BOX_PENALTY;
    }

    letter_total += a[1][hour].items_amount;
    if (letter_total > MAX_ALLOWED_LETTERS) {
      printf("supero limit \n");
      letter_cost += LETTER_PENALTY;
      }
      hour++;
    }

  printf("box cost %d \n", boxes_cost);
  printf("letter cost %d \n", letter_cost);
    return boxes_cost + letter_cost;
}

void array_from_file(DeliveryTable array, const char *filepath) {
  FILE *file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  int i = 0;
  while (!(feof(file))) {
    int res = fscanf(file, "_%c_", &code);
    if (res != 1)
    {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }
    
    printf("hour %d & ", i);
      if (i > HOURS) {
      break;
    } 
    printf("code: %c \n", code);

    Flight flight_boxes = flight_from_file(file, code, 0);
    // printf("flight_boxes.code: %c \n", code);
    // printf("flight_boxes.type: %c \n", flight_boxes.type);
    array[flight_boxes.type][flight_boxes.hour -1] = flight_boxes;

    Flight flight_letters = flight_from_file(file, code, 1);
    //printf("flight_letters.code: %c \n", code);
    //printf("flight_letters.type: %c \n", flight_letters.type);
    array[flight_letters.type][flight_letters.hour -1] = flight_letters;


      i++;

  }
  // if (i ...) {}
}


/*
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c flight.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o flight.o main.o -o delivery
./delivery ./inputs/example1230.in 
*/