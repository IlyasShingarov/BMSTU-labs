#include "stdio.h"
#include "freq.h"

int find_max(int *array, int n);
int mat_preprocess(int (*mat)[MAX_COLS], int rows, int cols);
int mat_process(int (*mat)[MAX_COLS], int rows, int cols);
int row_shift(int (*mat)[MAX_COLS], int columns, int index);

int main(void)
{
    int error = 0;

    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };
    int rows, columns = 0;

    error = mat_size_in(&rows, &columns);

    if (!error)
        error = mat_in(matrix, rows, columns);
    
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

int mat_preprocess(int (*mat)[MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        mat[i][cols] = find_max(mat[i], cols);
    }

    return 0;
}

int mat_process(int (*mat)[MAX_COLS], int rows, int cols)
{
    int state = 0;
    while (!state)
    {
        state = 1;
        for(int i = 0; i < rows - 1; i++)
            if (mat[i][cols] < mat[i + 1][cols])
            {
                row_shift(mat, cols, i);
                state = 0;
            }
    }
        
    return 0;
}

int row_shift(int (*mat)[MAX_COLS], int columns, int index)
{
    for (int i = 0; i < columns + 1; i++)
        swap(&mat[index][i], &mat[index + 1][i]);
    
    return ++index;
}