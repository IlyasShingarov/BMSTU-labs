#ifndef WRAP_H
#define WRAP_H

#include "films.h"

int title_mode(const char *dir, const char *key);
int read_title(FILE *file, film_t *arr, int *count);

int name_mode(const char *dir, const char *key);
int read_name(FILE *file, film_t *arr, int *count);

int year_mode(const char *dir, const char *key);
int read_year(FILE *file, film_t *arr, int *count);

#endif