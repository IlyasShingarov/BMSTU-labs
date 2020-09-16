#ifndef WRAP_H
#define WRAP_H

#include "films.h"

void shift(film_t *arr, int n, int ind);
int sorted_insert(film_t film, film_t *arr, int *n, int (*comp_func)(film_t f_1, film_t f_2));

int title_mode(const char *dir);
int read_title(FILE *file, film_t *arr, int *count);

int name_mode(const char *dir);
int year_mode(const char *dir);



#endif