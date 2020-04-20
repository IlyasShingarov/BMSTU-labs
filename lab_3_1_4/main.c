#include <stdio.h>
#include "freq.h"

void swap_rows(int **mat, int rows, int columnns);

int main(void)
{
    int error = 0;

    int rows, columns;
    int *matrix[MAX_ROWS];
    int buffer[MAX_ROWS][MAX_COLS];

    transform(matrix, *buffer, MAX_ROWS, MAX_COLS);

    error = mat_in(matrix, &rows, &columns);

    if (!error)
        swap_rows(matrix, rows, columns);
    
    if (!error)
        mat_out(matrix, rows, columns);

    if (error)
        printf("Error!");

    return error;
}

void swap_rows(int **mat, int rows, int columnns)
{
    int counter = 0;
    for (int i = 0; i < rows / 2; i++)
    {
        for (int j = counter; j < columnns - counter; j++)
        {
            swap(*(mat + i) + j, *(mat + rows - i - 1) + j);
        }
        counter++;
    }   
}