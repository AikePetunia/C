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
* @return True when is the last entry of the flight table, False otherwise
*/
static bool is_last_line(unsigned int hour, unsigned int type) {
  return  hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(LayoverTable a) {
  for (unsigned int hour = 0u; hour < HOURS; ++hour) {
    for (unsigned int type = 0u; type < TYPE; ++type) {
      Flight f = a[hour][type];
      // si el vuelo es arrive, es cualquier cosa
       fprintf(stdout, "%c: %s at %u:00 with %u passengers", f.code, f.type == 0 ? "arrives" : "departs", f.hour - 1, f.passengers_amount);
      if (!is_last_line(hour, type)) {
        fprintf(stdout, "\n");
      }
    }
  }
}

unsigned int passengers_amount_in_airport (LayoverTable a, unsigned int h) {
  int count = 0;
  unsigned int initialHour = h == 1 ? 1 : 0;
  // typedef Flight LayoverTable [HOURS][TYPE];
  while(initialHour != h+1) {
    printf("\n debug hour: %d \n", initialHour);
    int arrivedPassanger = a[initialHour][0].passengers_amount; // pasajeros dejados en aeropuerto
    int gonePassanger = a[initialHour][1].passengers_amount; // pasajeros que ya se fueron
    printf("arrived passanger %d \n", arrivedPassanger);
    printf("gonePassanger %d \n", gonePassanger);
    count += arrivedPassanger - gonePassanger;
    printf("counted passanger: %d \n", count );
    initialHour++;
  }

  return count;
}

void array_from_file(LayoverTable array, const char *filepath) {
  FILE *file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  /* 
   se lee el archivo:
   feof(file) == 1,si termino de haber datos en el archivo
   feof(file) == 0, sigue leyendo el archivo
  */
 while (!(feof(file))) {
  // se lee explicitamente, o sea literal. si uno pone %c solo, no lo leera, por que leera el '_'
    int res = fscanf(file, "_%c_", &code);
    if (res != 1) {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }

    /* COMPLETAR: Generar y guardar ambos Flight en el array multidimensional */
    // printf("code: %c", code);
    Flight flight_arrival = flight_from_file(file, code);
    Flight flight_departure = flight_from_file(file, code);

    /* 
    si tipo 0:
    el dato de interes es arrival.
    si tipo 1:
    el dato de interes es departure.
    */
    if (flight_departure.type == 1) {
      // i se lee en el archivo una hora h debe interpretarse como la hora h - 1 (ej: <7> ==> 6am).
      array[flight_departure.hour -1][flight_departure.type] = flight_departure;
      
      passengers_amount_in_airport(array, flight_departure.hour);
    }
      // i se lee en el archivo una hora h debe interpretarse como la hora h - 1 (ej: <7> ==> 6am).
      array[flight_arrival.hour -1][flight_arrival.type] = flight_arrival;

 }
  fclose(file);
}

/*
gcc -Wall  -Wextra -pedantic -std=c99 -c array_helpers.c flight.c main.c
gcc -Wall  -Wextra -pedantic -std=c99 array_helpers.o flight.o main.o -o layover
./layover ./inputs/example11.in
*/