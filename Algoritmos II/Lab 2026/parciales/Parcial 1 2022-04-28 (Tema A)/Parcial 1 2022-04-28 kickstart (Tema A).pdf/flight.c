/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdlib.h>
#include "flight.h"
#include <stdio.h>

static const int AMOUNT_OF_FLIGHT_VARS = 3 ;

Flight flight_from_file(FILE* file, char code)
{
    Flight flight;
    flight.code = code;

    unsigned int type;
    unsigned int hour;
    unsigned int passenger_amount;

    int res = fscanf(file, "%u %u %u\n",  &type, &hour, &passenger_amount);
    // printf("res: %d \n", res);
    if (res != AMOUNT_OF_FLIGHT_VARS) {
      fprintf(stderr, "invalid file\n");
      exit(EXIT_FAILURE);
    }

    flight.type = type;
    flight.hour = hour;
    flight.passengers_amount = passenger_amount;
     // printf("FLIGHT TYPE: %d \n", flight.type);
     // printf("FLIGHT hour: %d \n", flight.hour);
     // printf("FLIGHT passengers_amount: %d \n", flight.passengers_amount);

      return flight;
}
