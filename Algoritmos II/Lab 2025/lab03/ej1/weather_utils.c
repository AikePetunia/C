#include "weather_utils.h" // mis funciones :3
#define MIN_TEMP -5000    
#define MAX_TEMP 500000     

// funcion que printe la temperatura minima historica
// temperatura mínima histórica registrada en la ciudad de 
// Córdoba según los datos del arreglo (práctico 2.1, ejercicio 2.a).

int min_history(WeatherTable a) {
  int min_temp = MAX_TEMP;
  for (unsigned int year = 0u; year < YEARS; year++) {
      for(unsigned int month = 0u; month < MONTHS; month++) {
          for(unsigned int day = 0u; day < DAYS; day++) {
              if ((a[year][month][day]._min_temp) < min_temp) {
                  min_temp = a[year][month][day]._min_temp;
              }
          }
      }
  }
  return min_temp;
}

// funcion que printea la temperatura maxima de cada año
void max_year_temperature(WeatherTable a, int output[YEARS]) {
  for (unsigned int year = 0; year < YEARS; year++) {
      int max_temp_year = MIN_TEMP;  // Reset for each year
      for(unsigned int month = 0; month < MONTHS; month++) {
          for(unsigned int day = 0; day < DAYS; day++) {
            if ((a[year][month][day]._max_temp) > max_temp_year) {
                  max_temp_year = a[year][month][day]._max_temp;
                } 
          }
      }
      printf("la máxima temperatura en el año %d es: %d \n", year, max_temp_year);
      output[year] = max_temp_year; 
  }
}

void max_rainfall(WeatherTable a, int output[YEARS]) {
  // se compara el total de presipitaciones de un mes con el resto.
  unsigned int max_rainfall = 0;
  int rainfall_total = 0;
  int history_rainfall = 0;
  for (unsigned int year = 0; year < YEARS; year++) {
      for(unsigned int month = 0; month < MONTHS; month++) {
          for(unsigned int day = 0; day < DAYS; day++) {
            if ((a[year][month][day]._rainfall) > max_rainfall) {
                  max_rainfall = a[year][month][day]._rainfall;
                } 
            // sumatoria total de rainfall por día en el mes.
            rainfall_total = rainfall_total + a[year][month][day]._rainfall;
          }
          // una vez sumado los días, verificamos si la suma es mayor a la anterior. si lo es, nos quedamos con el numero.
          if (rainfall_total > history_rainfall) {
            history_rainfall = rainfall_total;
            output[year] = history_rainfall;
          }
      }		
  }
}