#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "wrap.h"
#include "films.h"
#include "utils.h"

int title_mode(const char *dir, const char *key)
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
        if (!error && key == NULL)
            print_films(films, film_count);
        else if (!error)
            error = bin_title_search(films, film_count, key);
    }

    if (file)
        fclose(file);

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

int name_mode(const char *dir, const char *key)
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
        error = read_name(file, films, &film_count);
        if (!error && key == NULL)
            print_films(films, film_count);
        else if (!error)
            error = bin_name_search(films, film_count, key);
    }

    if (file)
        fclose(file);

    return error;
}

int read_name(FILE *file, film_t *arr, int *count)
{
    int error = ERR_OK;
    while (!error && (*count) <= MAX_FILM_COUNT && !feof(file))
    {
        film_t temp_film;
        error = make_film(file, &temp_film);
        if (!error)
        {
            error = sorted_insert(temp_film, arr, count, name_cmp);
        }
    }

    return error;
}

int year_mode(const char *dir, const char *key)
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
        error = read_year(file, films, &film_count);
        if (!error && key == NULL)
            print_films(films, film_count);
        else if (!error)
        {
            int t_key = atoi(key);
            if (!t_key)
                error = ERR_ATOI;
            if (!error)
                error = bin_search(films, film_count, t_key);
        }
    }

    if (file)
        fclose(file);
    
    return error;
}

int read_year(FILE *file, film_t *arr, int *count)
{
    int error = ERR_OK;
    while (!error && (*count) <= MAX_FILM_COUNT && !feof(file))
    {
        film_t temp_film;
        error = make_film(file, &temp_film);
        if (!error)
        {
            error = sorted_insert(temp_film, arr, count, year_cmp);
        }
    }

    return error;
}