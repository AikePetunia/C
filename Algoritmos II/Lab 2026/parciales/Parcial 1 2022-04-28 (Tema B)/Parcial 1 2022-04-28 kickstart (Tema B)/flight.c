/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdlib.h>
#include "flight.h"

static const int AMOUNT_OF_FLIGHT_VARS = 2;

Flight flight_from_file(FILE* file, char code, item_t type)
{
    Flight flight;
    flight.code = code;
    flight.type = type;

    printf("\n type: %d", type);
    printf("\n flight.type: %d", flight.type);
    
    unsigned int hour = 0u;
    unsigned int items_amount = 0u;
    int res = fscanf(file, EXPECTED_FLIGHT_FILE_FORMAT, &hour, &items_amount);
    if (res != AMOUNT_OF_FLIGHT_VARS) {
      printf("no hay suficientes coso\n");
      exit(EXIT_FAILURE);
    }
    flight.hour = hour;
    flight.items_amount = items_amount;
    
        printf("hour: %d & ", hour);
        printf("items_amout: %d \n", items_amount);
    return flight;
}
