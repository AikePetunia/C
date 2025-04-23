/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_helpers.h"

company_t get_company_enum(char *c){
  company_t res;
  if (strcmp(c,"META") == 0) res = META;
  if (strcmp(c,"TSLA") == 0) res = TSLA;
  if (strcmp(c,"MSFT") == 0) res = MSFT;
  if (strcmp(c,"MELI") == 0) res = MELI;
  return res;
}

char* get_company_string(company_t c){
  char *res;
  if (c == META) res = "META";
  if (c == TSLA) res = "TSLA";
  if (c == MSFT) res = "MSFT";
  if (c == MELI) res = "MELI";
  return res;
}


void array_dump(StockTable t){
  for (company_t c = META; c <= MELI; ++c) {
    for (unsigned int j = 0u; j < NR_STOCKS; ++j) {
      Stock s = t[c][j];
      fprintf(stdout, "symbol:%s date:%u-%u-%u open:%.2f high:%.2f low:%.2f close:%.2f adj:%.2f vol:%u\n",
              get_company_string(c),s.year,s.month,s.day, s.open, s.high, s.low, s.close, s.adj, s.vol);
    }
  }
  fprintf(stdout,"\n"); 
}
price avg_close_price(company_t c, StockTable t){
  float sum = 0.0;
  for(int i = 0; i < NR_STOCKS; i++) {
    sum += t[c][i].close;
  }
  return sum / NR_STOCKS;  
}

volume max_volume(company_t c, StockTable t){
  unsigned int max_vol = 0;
  for(int i = 0; i < NR_STOCKS; i++) {
    if(t[c][i].vol > max_vol) {
      max_vol = t[c][i].vol;
    }
  }
  return max_vol;
}

void array_from_file(StockTable table, const char *filepath) {
  FILE *file = NULL;
  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }
  

  unsigned int readlines=0u;
  while (!(feof(file))) {
    char symbol[4];
    unsigned round;
    company_t c;

    int res = fscanf(file, " %s %u ", symbol, &round);

    if (res != 2) {
      fprintf(stderr, "Invalid stock data.\n");
      exit(EXIT_FAILURE);
    }

    if(round > 10) {
      fprintf(stderr, "number of stocks is not valid");
      exit(EXIT_FAILURE);
    }


    // pasamos a la funcion ya definida, el simbolo  (ademas vemos que recibe company_t c)
    c = get_company_enum(symbol);
    // pasamos el resto de parametros a stock_from_file(); para manejo
    Stock stock = stock_from_file(file);

    table[c][round - 1] = stock;
    readlines++;
    round++;
  }
  /*
   * COMPLETAR
   *
   */

  fclose(file);
}
