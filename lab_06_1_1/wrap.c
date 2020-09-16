#include <string.h>
#include <stdio.h>
#include "errors.h"
#include "wrap.h"
#include "films.h"

void shift(film_t *arr, int n, int ind)
{
    for (int i = n; i > ind; i--)
    {
        arr[i] = arr[i - 1];
    }
}

int sorted_insert(film_t film, film_t *arr, int *n, int (*comp_func)(film_t f_1, film_t f_2))
{
    int error = ERR_OK, inserted = 0;

    if (*n >= MAX_FILM_COUNT)
        error = ERR_ARR_MAX;
    
    if (!error)
    {
        for (int i = 0; i <= (*n) && !inserted; i++)
        {
            if (comp_func(film, arr[i]) <= 0)
            {
                shift(arr, *n, i);
                arr[i] = film;
                (*n)++;
                inserted = 1;
            }        
        }

        if (inserted == 0)
        {
            arr[(*n)] = film;
            (*n)++;
        }
    }
    return error;
}

int read_title(FILE *file, film_t *arr, int *count)
{
    int error = ERR_OK;
    while (!error && (*count) <= MAX_FILM_COUNT && !feof(file))
    {
        film_t temp_film;
        error = make_film(file, &temp_film);
        if (!error)
        {
            error = sorted_insert(temp_film, arr, count, title_cmp);
        }
    }

    return error;
}

int title_mode(const char *dir)
{
    int error = ERR_OK;
    FILE *file = fopen(dir, "r");

    if (!file)
        error = ERR_NULL_PTR;
    
    int film_count = 0;
    film_t films[MAX_FILM_COUNT];
    film_init(films);
    
    if (!error)
    {   
        error = read_title(file, films, &film_count);
        if (!error)
            print_films(films, film_count);
    }

    return error;
}














/*





int name_mode(const char *dir)
{
    int error = ERR_OK;
    FILE *file = fopen(dir, "r");

    if (!file)
        error = ERR_NULL_PTR;

    if (!error)
    {

    }

    return error;
}

int year_mode(const char *dir)
{
    int error = ERR_OK;
    FILE *file = fopen(dir, "r");

    if (!file)
        error = ERR_NULL_PTR;

    if (!error)
    {
        
    }

    return error;
}



int read_name()
{

}

int read_year()
{

}



*/