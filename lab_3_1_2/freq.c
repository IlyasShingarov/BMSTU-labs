#include <stdio.h>

#include "freq.h"

int array_in(int *arr, int len)
{
    int error = 0;

    printf("Input elements: ");
    for (int i = 0; i < len && !error; i++)
    {
        error = scanf("%d", &arr[i]) != 1;
    }
    
    return error;
}

int array_out(const int *array, int len)
{    
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}

int mat_size_in(int *rows, int *columns)
{
    int error = 0;

    printf("Input rows, columns: ");
    if(scanf("%d%d", rows, columns) != 2 || *rows <= 0 || *rows > MAX_ROWS || *columns <= 0 || *columns > MAX_COLS)
        error = 1;

    return error;
}

int mat_in(int (*mat)[MAX_COLS], int rows, int columns)
{
    int error = 0;

    for (int i = 0; i < rows && !error; i++)
    {
        error = array_in(mat[i], columns);
    }

    return error;
}

int mat_out(int (*matrix)[MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        array_out(matrix[i], cols);
    }
    
    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
