#include <stdio.h>
#include <stdlib.h>

#include "io.h"

#define OK 0
#define NULL_PTR_ERR -1
#define READ_ERR -2


int count_elements(char *directory)
{
    int error = OK;

    FILE *file = fopen(directory, "r");
    if (!file)
        error = NULL_PTR_ERR;

    int counter = 0, temp_num;
    if (!error)
        while (fscanf(file, "%d", &temp_num) != EOF)
            counter++;

    if (!feof(file) || counter <= 0)
        error = READ_ERR;
    
    if (file)
        fclose(file);

    return !error ? counter : error;
}

int read_array(char *directory, int *p_beg, int *p_end)
{
    int error = OK;

    FILE *file = fopen(directory, "r");
    
    if (!file)
        error = NULL_PTR_ERR;
    
    if (!error)
    {
        for (int *p_temp = p_beg; p_temp != p_end && !error; p_temp++)
            if (fscanf(file, "%d", p_temp) != 1)
                error = READ_ERR;
    }

    if (file)
        fclose(file);

    return error;
}

int write_array(char *directory, int *p_beg, int *p_end)
{   
    int error = OK;
    FILE *file = fopen(directory, "w");
    if (!file)
        error = NULL_PTR_ERR;

    if (!error)
        for (int *p_temp = p_beg; p_temp != p_end; p_temp++)
            fprintf(file, "%d", *p_temp);

    if (file)
        fclose(file);
    
    return error;
}
