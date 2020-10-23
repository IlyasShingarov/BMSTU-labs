#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"

int check_column_count(int columns)
{
    return columns < 1 || columns > MAX_COLUMNS;
}

int check_row_count(int rows)
{
    return rows < 1 || rows > MAX_ROWS;
}

int read_matrix_size(int *rows, int *columns)
{
    int error = OK;

    if (scanf("%d%d", rows, columns) == 2)
    {
        if (check_row_count(*rows))
            error = ROW_COUNT_ERR;
        else if (check_column_count(*coulumns))
            error = COLUMN_COUNT_ERR;
    }
    else
        error = READ_ERR;

    return error;
}

int allocate_rows(int **matrix, int rows)
{
    int error = OK;
    matrix = malloc(rows * sizeof(*matrix));
    if (!matrix)
        error = MALLOC_ERR;
    
    return error;
}

int allocate_columns(int **matrix, int rows, int columns)
{
    int error = OK;

    for (int i = 0; i < rows && !error ; i++)
    {
        matrix[i] = malloc(columns * sizeof(**matrix));
        if (!matrix[i])
            error = MALLOC_ERR;
    }

    return error;
}

int read_matrix(int **matrix, int *rows, int *columns)
{
    int error = OK;

    error = read_matrix_size(rows, columns);
    
    if (!error)
        error = allocate_rows(matrix, rows);
    if (!error)
        error = allocate_columns(matrix, rows, columns);

    return error;
}
