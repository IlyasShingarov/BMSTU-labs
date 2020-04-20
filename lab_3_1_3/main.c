#include "stdio.h"
#include "freq.h"

int find_max(int *array, int n);
void mat_preprocess(int **mat, int rows, int cols);
void mat_process(int **mat, int rows, int cols);
int row_shift(int **mat, int columns, int index);

int main(void)
{
    int error = 0;

    int rows, columns;
    int *matrix[MAX_ROWS];
    int buffer[MAX_ROWS][MAX_COLS];

    transform(matrix, *buffer, MAX_ROWS, MAX_COLS);

    error = mat_in(matrix, &rows, &columns);
    
    if (!error)
    {
        mat_preprocess(matrix, rows, columns);
        mat_process(matrix, rows, columns);
    }

    if (!error)
        mat_out(matrix, rows, columns);
    
    if (error)
        printf("Error");

    return error;
}

void mat_preprocess(int **mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        mat[i][cols] = find_max(mat[i], cols);
}

void mat_process(int **mat, int rows, int cols)
{
    int state = 0;
    while (!state)
    {
        state = 1;
        for (int i = 0; i < rows - 1; i++)
            if (mat[i][cols] < mat[i + 1][cols])
            {
                row_shift(mat, cols, i);
                state = 0;
            }
    }
}

int row_shift(int **mat, int columns, int index)
{
    for (int i = 0; i < columns + 1; i++)
        swap(&mat[index][i], &mat[index + 1][i]);
    
    return ++index;
}