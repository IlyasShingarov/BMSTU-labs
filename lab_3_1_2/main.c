#include "freq.h"
#include "stdio.h"
#include "stdlib.h"

//Работа со столбцами матрицы
int column_shift(int **mat, int rows, int index);
int delete_column(int **mat, int rows, int columns, int index);

//Работа со строками матрицы
int row_shift(int **mat, int rows, int index);
int delete_row(int **mat, int rows, int columns, int index);
 
// Поиск элемента
void find_min_digit_sum(int **mat, int rows, int columns, int *min_i, int *min_j);


int main(void)
{
    setbuf(stdout, NULL);
    int error = 0;
    int rows, columns;
    int *matrix[MAX_ROWS];
    int buffer[MAX_ROWS][MAX_COLS];
    
    transform(matrix, *buffer, MAX_ROWS, MAX_COLS);

    int min_i, min_j = 0;

    error = mat_in(matrix, &rows, &columns);

    if (rows == 1 || columns == 1)
        error = 1;

    if (!error)
    {   
        find_min_digit_sum(matrix, rows, columns, &min_i, &min_j);
        columns = delete_column(matrix, rows, columns, min_j);
        rows = delete_row(matrix, rows, columns, min_i);
        mat_out(matrix, rows, columns);
    }
    
    if (error)
        printf("Error!");

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

int column_shift(int **mat, int rows, int index)
{   
    for (int i = 0; i < rows ; i++)
        swap(&mat[i][index], &mat[i][index + 1]);
    
    return ++index;
}

int delete_column(int **mat, int rows, int columns, int index)
{
    while (index != columns)
        index = column_shift(mat, rows, index);

    return --columns;
}

int row_shift(int **mat, int columns, int index)
{
    for (int i = 0; i < columns; i++)
        swap(&mat[index][i], &mat[index + 1][i]);
    
    return ++index;
}

int delete_row(int **mat, int rows, int columns, int index)
{
    while (index != rows)
        index = row_shift(mat, columns, index);
    
    return --rows;
}


void find_min_digit_sum(int **mat, int rows, int columns, int *min_i, int *min_j)
{   
    int min_sum = digit_sum(mat[0][0]);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            int sum = digit_sum(abs(mat[i][j]));
            if (sum <= min_sum)
            {
                min_sum = sum;
                *min_j = j;
                *min_i = i;
            }
        }
}
