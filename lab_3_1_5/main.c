#include <stdio.h>
#include <stdlib.h>
#include "freq.h"

#define SHIFT_COUNT 3
#define MAX_ARRAY_LENGTH 100

void shift_left(int *array, int len, int times);
int form_array(int (*mat)[MAX_COLS], int rows, int columns, int *array);
int digit_sum(int x);
void return_elements(int (*mat)[MAX_COLS], int rows, int columns, int *array);


int main(void)
{
    int error = 0;
    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };
    int array[MAX_ARRAY_LENGTH] = { 0 };
    int rows = 0, columns = 0, n = 0;

    error = mat_size_in(&rows, &columns);
    if (!error)
        error = mat_in(matrix, rows, columns);
    
    if (!error)
        n = form_array(matrix, rows, columns, array);

    if (!n)
        error = 1;

    if (!error)
    {
        shift_left(array, n, SHIFT_COUNT);
        return_elements(matrix, rows, columns, array);
    }

    if (error)
        printf("Error!");

    if (!error)
        mat_out(matrix, rows, columns);

    return error;
}

void shift_left(int *array, int len, int times)
{
    for (int j = 0; j < times; j++)
    {
        int temp = array[0];
        for (int i = 0; i < len - 1; i++)
            array[i] = array[i + 1];
        array[len - 1] = temp;
    }
}

int form_array(int (*mat)[MAX_COLS], int rows, int columns, int *array)
{
    int n = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (digit_sum(abs(mat[i][j])) > 10)
            {
                array[n] = mat[i][j];
                n++;
            }

    return n;
}

int digit_sum(int x)
{
    int sum = 0;

    while (x != 0)
    {
        sum += x % 10;
        x = x / 10;
    }

    return sum;
}

void return_elements(int (*mat)[MAX_COLS], int rows, int columns, int *array)
{
    int counter = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (digit_sum(abs(mat[i][j])) > 10)
            {
                mat[i][j] = array[counter];
                counter++;
            }
}