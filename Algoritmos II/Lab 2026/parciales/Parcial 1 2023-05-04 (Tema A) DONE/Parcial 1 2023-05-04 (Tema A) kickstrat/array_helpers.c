/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

static const int EXPECTED_DIM_VALUE = 2;

static const char* CITY_NAMES[CITIES] = {
    "Cordoba", "Rosario", "Posadas", "Tilcara", "Bariloche"};
static const char* SEASON_NAMES[SEASONS] = {"low", "high"};

void array_dump(BakeryProductTable a)
{
    for (unsigned int city = 0u; city < CITIES; ++city)
    {
        for (unsigned int season = 0u; season < SEASONS; ++season)
        {
            fprintf(stdout, "%s in %s season: flour (%u,%u) Yeast (%u,%u) Butter (%u,%u) Sales value %u",
                    CITY_NAMES[city], SEASON_NAMES[season], a[city][season].flour_cant,
                    a[city][season].flour_price, a[city][season].yeast_cant,
                    a[city][season].yeast_price, a[city][season].butter_cant,
                    a[city][season].butter_price, a[city][season].sale_value);
            fprintf(stdout, "\n");
        }
    }
}


int multiplyProduct(int amount, int price) {
    return amount * price;
}

unsigned int best_profit(BakeryProductTable a) {
    unsigned int max_profit = 0u;
    unsigned int max_temp_profit = 0u;
    unsigned int i = 0;
    unsigned int j = 0;
    while(i < CITIES) {
        while(j < SEASONS) {
            int productionAmount = multiplyProduct(a[i][j].flour_cant, a[i][j].flour_price) 
            + multiplyProduct(a[i][j].butter_cant, a[i][j].butter_price) 
            + multiplyProduct(a[i][j].yeast_cant, a[i][j].yeast_price);
            max_temp_profit = a[i][j].sale_value - productionAmount;
            if (max_temp_profit >= max_profit) {
                max_profit = max_temp_profit;
            }
            j++;
        }
        i++;
    }
    return max_profit;

}

void array_from_file(BakeryProductTable array, const char* filepath)
{
    FILE* file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (!feof(file))
    {
        unsigned int city;
        unsigned int season;

        int res = fscanf(file, "##%u??%u ", &city, &season);
        printf("city %d, season: %d \n", city, season);

        if (res != EXPECTED_DIM_VALUE) {
            fprintf(stderr, "Invalid file.\n");
            exit(EXIT_FAILURE);
        }

            BakeryProduct bake = bakery_product_from_file(file);
            array[city][season] = bake;

        ++i;
    }

       /* Aseguro antes de finalizar la funcion que la cantidad de lineas leidas del archivo sea 
   exactamente igual a la cantidad total de ciudades, cada una con sus temporadas. */

            if (i!=CITIES*SEASONS){
       fprintf(stderr, "File is incomplete or overloaded.\n");
       exit(EXIT_FAILURE);
    }

    fclose(file);
}

/*

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c bakery_product.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o bakery_product.o main.o -o ptable

./ptable input/example_92.in
*/
