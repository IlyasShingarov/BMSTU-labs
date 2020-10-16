#ifndef _UTILS_H
#define _UTILS_H

#include "films.h"

void shift(film_t *arr, int n, int ind);
int sorted_insert(film_t film, film_t *arr, int *n, int (*comp_func)(film_t f_1, film_t f_2));

int bin_search(film_t *arr, int n, int key);
int bin_title_search(film_t *arr, int n, const char *key);
int bin_name_search(film_t *arr, int n, const char *key);

#endif
