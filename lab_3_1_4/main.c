#include <stdio.h>
#include "freq.h"

void swap_rows(int (*mat)[MAX_COLS], int rows, int columnns);

int main(void)
{
    int error = 0;

    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };
    int rows, columns = 0;

    error = mat_size_in(&rows, &columns);

    if (rows != columns)
        error = 1;

    if (!error)
        error = mat_in(matrix, rows, columns);

    if (!error)
        swap_rows(matrix, rows, columns);
    
    if (!error)
        mat_out(matrix, rows, columns);

    if (error)
        printf("Error!");

    return error;
}

void swap_rows(int (*mat)[MAX_COLS], int rows, int columnns)
{
    int counter = 0;
    for (int i = 0; i < rows / 2; i++)
    {
        for (int j = counter; j < columnns - counter; j++)
        {
            swap(&mat[i][j], &mat[rows - i - 1][j]);
        }
        counter++;
    }   
}