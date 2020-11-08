#include <stdlib.h>
#include <math.h>

#include "../inc/equalize_matrix.h"
#include "../inc/errors.h"


void fill_last_row(int **matrix, int rows, int columns)
{
    for (int j = 0; j < columns; j++)
    {
        double res = 1;
        for (int i = 0; i < rows - 1; i++)
        {
            res *= matrix[i][j]; 
        }
        res = pow(res, 1.0 / (double)(rows - 1));
        matrix[rows - 1][j] = (int)(res / 1);
    }
}

int add_row(int ***matrix, int *rows, int columns)
{
    int error = OK;

    *rows = *rows + 1;

    *matrix = realloc(*matrix, *rows * sizeof(int*));

    if (matrix)
        (*matrix)[*rows - 1] = malloc(columns * sizeof(int));
    else
        error = MALLOC_ERR;

    if ((*matrix)[*rows - 1])
            fill_last_row(*matrix, *rows, columns);
    else
        error = MALLOC_ERR;
    
    return error;
}

int add_column(int ***matrix, int rows, int *columns)
{
    int error = OK;

    *columns = *columns + 1;

    for (int i = 0; i < rows && !error; i++)
    {
        (*matrix)[i] = realloc((*matrix)[i], *columns * sizeof(int));
        if ((*matrix)[i])
        {
            int min = (*matrix)[i][0];
            for (int j = 1; j < *columns - 1; j++)
                if ((*matrix)[i][j] < min)
                    min = (*matrix)[i][j];
            
            (*matrix)[i][*columns - 1] = min;
        }
        else
            error = MALLOC_ERR;
    }

    return error;
}

int max(int a, int b)
{   
    return a > b ? a : b;
}

int equalize_matrices(int ***matrix_a, int ***matrix_b, int *rows_a, int *rows_b, int *cols_a, int *cols_b)
{
    int error = OK;

    // Assuming matrices are square (rows == columns == size)
    int size_a = *rows_a, size_b = *rows_b;

    int target_size = max(size_a, size_b);

    while (!error && size_a < target_size)
    {
        error = add_row(matrix_a, rows_a, *cols_a);
        if (!error)
            add_column(matrix_a, *rows_a, cols_a);
        
        size_a++;
    }

    while (!error && size_b < target_size)
    {
        add_row(matrix_b, rows_b, *cols_b);
        if (!error)
            add_column(matrix_b, *rows_b, cols_b);
        
        size_b++;
    }
    
    return error;
}