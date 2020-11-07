#include <stdlib.h>

#include "../inc/errors.h"

int find_last_min(int **matrix, int rows, int columns, int *min_row, int *min_col)
{
    int min = **matrix;
    
    *min_row = 0; 
    *min_col = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (matrix[i][j] <= min)
            {
                min = matrix[i][j];
                *min_row = i;
                *min_col = j;
            }
    
    return min;
}

void swap(int **a, int **b)
{
    int *t = *a;
    *a = *b;
    *b = t;
}

void shift_row_to_end(int **matrix, int rows, int index)
{
    for (int i = index; i < rows - 1; i++)
        swap(matrix + i, matrix + i + 1);
}

int delete_row_by_index(int ***matrix, int *rows, int min_row)
{
    int error = OK;

    shift_row_to_end(*matrix, *rows, min_row);

    *rows = *rows - 1;
    free((*matrix)[*rows]);

    *matrix = realloc(*matrix, *rows * sizeof(int*));

    if (!matrix)
        error = MALLOC_ERR;
    

    return error;
}

int squarify_matrix(int ***matrix, int *rows, int *columns)
{
    int error = OK;
    
    while (!error && *rows != *columns)
    {
        int min_row, min_column;

        find_last_min(*matrix, *rows, *columns, &min_row, &min_column);

        if (*rows > *columns)
        {
            error = delete_row_by_index(matrix, rows, min_row);
        }
        /*
        else
        {
            error = find_column_by_index();
        }*/       
    }

    return error;
}