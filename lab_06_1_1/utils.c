#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "errors.h"
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

int bin_name_search(film_t *arr, int n, const char *key)
{
    int error = ERR_OK;

    film_t result;

    int l = 0, r = n, found = 0;
    while (l <= r && !found)
    {
        int m = (l + r) / 2;
        if (!strncmp(key, arr[m].name, MAX_STR_LEN))
        {
            result = arr[m];
            found = 1;
        }
        if (!found)
        {
            if (strncmp(key, arr[m].title, MAX_STR_LEN) > 0)
                r = m - 1;
            else
                l = m + 1;
        }
    }
    if (!found)
        printf("Not found\n");
    else
        print_film(result);

    return error;
}

int bin_title_search(film_t *arr, int n, const char *key)
{
    int error = ERR_OK;

    film_t result;

    int l = 0, r = n, found = 0;
    while (l <= r && !found)
    {
        int m = (l + r) / 2;
        if (!strncmp(arr[m].title, key, MAX_STR_LEN))
        {
            result = arr[m];
            found = 1;
        }
        if (!found)
        {
            if (strncmp(arr[m].title, key, MAX_STR_LEN) > 0)
                r = m - 1;
            else
                l = m + 1;
        }
    }
    if (!found)
        printf("Not found\n");
    else
        print_film(result);

    return error;
}

int bin_search(film_t *arr, int n, int key)
{
    int error = ERR_OK;

    film_t result;

    int l = 0, r = n, found = 0;
    while (l <= r && !found)
    {
        int m = (l + r) / 2;
        if (key == arr[m].year)
        {
            result = arr[m];
            found = 1;
        }
        if (!found)
        {
            if (key < arr[m].year)
                r = m - 1;
            else
                l = m + 1;
        }
    }
    if (!found)
        printf("Not found\n");
    else
        print_film(result);
    
    return error;
}