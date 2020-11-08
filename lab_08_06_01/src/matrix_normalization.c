#include <stdlib.h>
#include <math.h>

#include "../inc/errors.h"
#include "../inc/matrix_normalization.h"

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

void swap_rows(int **a, int **b)
{
    int *t = *a;
    *a = *b;
    *b = t;
}

void shift_row_to_end(int **matrix, int rows, int index)
{
    for (int i = index; i < rows - 1; i++)
        swap_rows(matrix + i, matrix + i + 1);
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shift_elem_to_end(int *arr, int n, int index)
{
    for (int i = index; i < n - 1; i++)
        swap(arr + i, arr + i + 1);
}

void shift_column_to_end(int **matrix, int rows, int columns, int min_col)
{
    for (int i = 0; i < rows; i++)
        shift_elem_to_end(matrix[i], columns, min_col);
}

int delete_column_by_index(int ***matrix, int *rows, int *columns, int min_column)
{
    int error = OK;

    shift_column_to_end(*matrix, *rows, *columns, min_column);

    *columns = *columns - 1;
    for (int i = 0; i < *rows && !error; i++)
    {
        (*matrix)[i] = realloc((*matrix)[i], *columns * sizeof(int));
        if (!matrix[i])
            error = MALLOC_ERR;
    }

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
        else
        {
            error = delete_column_by_index(matrix, rows, columns, min_column);
        }    
    }

    return error;
}

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