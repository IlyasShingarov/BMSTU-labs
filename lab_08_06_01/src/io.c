#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/io.h"
#include "../inc/errors.h"

int read_matrix_size(int *rows, int *columns)
{
    int error = OK;
    
    //printf("Введите кол-во строк и столбцов через пробел\n");

    if (scanf("%d%d", rows, columns) == 2)
    {
        if (*rows < 1)
            error = ROW_COUNT_ERR;
        else if (*columns < 1)
            error = COLUMN_COUNT_ERR;
    }
    else
        error = READ_ERR;

    return error;
}

void free_matrix(int **data, int n)
{
    for (int i = 0; i < n; i++)
        free(data[i]);

    free(data);
}

int **allocate_matrix(int n, int m)
{
    int error = OK;

    int **matrix = calloc(n, sizeof(int*));
    if (!matrix)
        error = MALLOC_ERR;
    else
        for (int i = 0; i < n; i++)
        {
            matrix[i] = malloc(m * sizeof(int));
            if (!matrix[i])
            {
                free_matrix(matrix, n);
                error = MALLOC_ERR;
            }
        }
    return !error ? matrix : NULL;
}

int input_elements(int **matrix, int rows, int columns)
{
    int error = OK;
    for (int i = 0; i < rows && !error; i++)
        for (int j = 0; j < columns && !error; j++)
            if (scanf("%d", matrix[i] + j) != 1)
                error = READ_ERR;
    
    return error;
}

int read_matrix(int ***matrix, int *rows, int *columns)
{
    int error = OK;

    if (!read_matrix_size(rows, columns))
    {
        *matrix = allocate_matrix(*rows, *columns);
        if (matrix)
            error = input_elements(*matrix, *rows, *columns);
        else
            error = MALLOC_ERR;
    }
    else
        error = READ_ERR;

    return error;
}

void print_matrix(int **matrix, int rows, int cols)
{
    //printf("Matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int read_powers(int *ro, int *gamma)
{
    int error = OK;

    //printf("Введите ro и gamma\n");
    if (scanf("%d", ro) != 1 && *ro < 0)
        error = READ_ERR;
    
    if (scanf("%d", gamma) != 1 && *gamma < 0)
        error = READ_ERR;

    return error;
}