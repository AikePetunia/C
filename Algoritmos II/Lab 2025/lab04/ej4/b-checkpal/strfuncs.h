#ifndef STRFUNCS_H
#define STRFUNCS_H

#include <stdio.h>
#include <stdbool.h>
size_t string_length(const char *str);

char *string_filter(const char *str, char c);

bool string_is_symmetric(const char *str);

#endif 
