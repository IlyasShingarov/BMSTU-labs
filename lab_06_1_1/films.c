#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "errors.h"
#include "films.h"

int make_film(FILE *file, film_t *film)
{
    char tmp_str[MAX_STR_LEN] = { 0 };
    char *t_p = 0;
    int tmp_num;

    int error = ERR_OK;

    if (feof(file))
        error = ERR_EOF;

    if (!error)
    {
        if (fgets(film->title, MAX_STR_LEN, file) == NULL)
            error = ERR_NULL_PTR;
        else
        {
            t_p = strchr(film->title, '\n');
            if (t_p != NULL)
                *t_p = '\0';
        }
        
        if (error || fgets(film->name, MAX_STR_LEN, file) == NULL)
            error = ERR_NULL_PTR;
        else
        {
            t_p = strchr(film->name, '\n');
            if (t_p != NULL)
                *t_p = '\0';
        }
    }

    if (!error)
        error = !fscanf(file, "%s\n", tmp_str);

    if (!error)
    {
        tmp_num = atoi(tmp_str);
        if (tmp_num)
            film->year = tmp_num;
        else
            error = ERR_ATOI;
    }

    if (error == ERR_EOF)
        error = ERR_OK;

    return error;
}

void film_init(film_t *arr)
{
    film_t zero_film = { .title = "\0", .name = "\0", .year = 0 };
    for (int i = 0; i < MAX_FILM_COUNT; i++)
    {
        arr[i] = zero_film;
    }
}

void print_films(film_t *film_arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        print_film(film_arr[i]);
        if (i == count - 1)
            printf("\n");
    }
}

void print_film(film_t film)
{
    printf("%s\n", film.title);
    printf("%s\n", film.name);
    printf("%d\n", film.year);
}

int title_cmp(film_t f_1, film_t f_2)
{
    return strncmp(f_1.title, f_2.title, MAX_STR_LEN);
}

int name_cmp(film_t f_1, film_t f_2)
{
    return strncmp(f_1.name, f_2.name, MAX_STR_LEN);
}

int year_cmp(film_t f_1, film_t f_2)
{
    return f_1.year - f_2.year;
}