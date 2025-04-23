/*
  @file stock.c
  @brief Implements store structure and methods
*/
#include <stdlib.h>
#include "stock.h"

static const int NUMBER_OF_STOCK_VARS = 9;


Stock stock_from_file(FILE* file) {
  Stock stock;
  unsigned int year, month, day;
  float open, high, low, close, adj, vol;

  int res = fscanf(file, EXPECTED_ROW_FORMAT, &year, &month, &day, &open, &high, &low, &close, &adj, &vol);
  
  stock.year = year;
  stock.month = month;
  stock.day = day;
  stock.open = open;
  stock.high = high;
  stock.low = low;
  stock.close = close;
  stock.adj = adj;
  stock.vol = vol;

  if (res != NUMBER_OF_STOCK_VARS) {
    fprintf(stderr, "Invalid number of stock vars");
    exit(EXIT_FAILURE);
  }

  if (!((year > 2012) || (year < 1986)) && (month > 12) && (day > 31)) {
    fprintf(stderr, "Invalide date");
    exit(EXIT_FAILURE);
  }

  return stock;
}
