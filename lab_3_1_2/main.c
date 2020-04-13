#include "freq.h"
#include <stdio.h>

int main(void)
{
    int error = 0;

    return error;
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

int column_shift(int(*mat)[MAX_COLS], int rows, int columns, int *index)
{
    for (int i = 0; i < rows; i++)
    {
        swap(mat[i][*index], mat[i][*index + 1]);
        index++;
    }
    
    return 0;
}

int delete_column(int (*mat)[MAX_COLS], int rows, int columns, int index)
{

}

int shift_row(int(*mat)[MAX_COLS], int rows, int columns, int *index)
{
    for (int i = 0; i < rows; i++)
    {
        swap(mat[*index], mat[*index + 1]);
        index++;
    }
}

int delete_row()
{

}

int find_min_digit_sum()
{

}

int mat_process()
{
    
}