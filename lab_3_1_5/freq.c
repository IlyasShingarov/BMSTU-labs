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

void array_out(const int *array, int len)
{    
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void transform(int **a, int *buffer, int n, int m)
{
    for (int i = 0; i < n; i++)
        a[i] = buffer + m * i;  
}

int mat_in(int **a, int *n, int *m)
{
    int error = 0;

    printf("Input rows, columns and matrix values: \n");
    if (scanf("%d%d", n, m)  != 2 || *n < 1 || *n > MAX_ROWS || *m < 1 || *m > MAX_COLS)
        error = 1;

    for (int i = 0; i < *n && !error; i++)
        for (int j = 0; j < *m && !error; j++)
            if (scanf("%d", *(a + i) + j) != 1)
                error = 1;

    return error;
}

void mat_out(int **matrix, int rows, int cols)
{
    printf("Matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

int find_max(int *array, int n)
{
    int max = 0;

    for (int *p = array; p < array + n; p++)
    {
        if (*p > max)
            max = *p;
    }

    return max;
}