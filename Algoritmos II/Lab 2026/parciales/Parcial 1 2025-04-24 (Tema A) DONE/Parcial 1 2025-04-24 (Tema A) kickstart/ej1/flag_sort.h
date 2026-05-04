#ifndef _FLAG_SORT_H
#define _FLAG_SORT_H

typedef enum {red, white, blue} color_t;

/**
 * @brief Ordenar un arreglo de tres colores RED, WHITE y BLUE.
 *
 * Dado un arreglo cuyos elementos son tres colores posibles RED, WHITE y BLUE,
 * ordenarlos de manera que queden todos los RED primero, después todos los 
 * WHITE y al final todos los BLUE, formando la bandera de Córdoba.
 * 
 * @param a Arreglo de colores.
 * @param length Largo del arreglo.
 */
void flag_sort(color_t a[], int length);

#endif // _FLAG_SORT_H
