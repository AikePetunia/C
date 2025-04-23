#include "weather_utils.h"

int temp_min(WeatherTable a) {
    unsigned int year = 0u;
    int t_min = a[year][0][0]._min_temp;
    while (year < YEARS) {
        unsigned int month = 0u;
        while (month < MONTHS) {
            unsigned int day = 0u;
            while (day < DAYS) {
                if (a[year][month][day]._min_temp < t_min) {
                    t_min = a[year][month][day]._min_temp;
                }
                day++;
            }
            month++;
        }
        year++;
    }
    return t_min;
}

void temp_max_anual(WeatherTable a, int output[YEARS]) {
    unsigned int year = 0u;
    while (year < YEARS) {
        int t_max_anual = a[year][0][0]._min_temp;
        unsigned int month = 0u;
        while (month < MONTHS) {
            unsigned int day = 0u;
            while (day < DAYS) {
                if (a[year][month][day]._max_temp > t_max_anual) {
                    t_max_anual = a[year][month][day]._max_temp;
                }
                day++;
            }
            month++;
        }
        output[year] = t_max_anual;
        year++;
    }
}

void mes_precip_max_anual(WeatherTable a, int output[YEARS]) {
    unsigned int year = 0u;
    while (year < YEARS) {
        unsigned int month = 0u;
        unsigned int mes_maxprecip_anual = month;
        unsigned int sum_precip_mensual = 0;
        unsigned int sum_precip_max = 0;
        while (month < MONTHS) {
            unsigned int day = 0u;
            sum_precip_mensual = 0;

            while (day < DAYS) {
                sum_precip_mensual += a[year][month][day]._rainfall;
                day++;
            }

            if (sum_precip_max < sum_precip_mensual) {
                mes_maxprecip_anual = month+1;
                sum_precip_max = sum_precip_mensual;
            }

            month++;
        }
        output[year] = mes_maxprecip_anual;
        year++;
    }
}

