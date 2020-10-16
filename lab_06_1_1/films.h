#ifndef FILMS_H
#define FILMS_H

#define MAX_STR_LEN 26
#define MAX_FILM_COUNT 15

#include <stdio.h>

typedef struct film_t
{
    char title[MAX_STR_LEN];
    char name[MAX_STR_LEN];
    int year;
} film_t;

int make_film(FILE *file, film_t *film);
void print_film(film_t film);
void print_films(film_t *film_arr, int count);

void film_init(film_t *arr);

int title_cmp(film_t f_1, film_t f_2);
int name_cmp(film_t f_1, film_t f_2);
int year_cmp(film_t f_1, film_t f_2);

#endif