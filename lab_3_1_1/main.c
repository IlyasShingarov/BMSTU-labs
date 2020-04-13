/*
По  матрице  получить  одномерный  массив,
присвоив  его  k-тому  элементу  значение  1,
если выполняется указанное ниже условие, и значение 0
Условие: k-ая строка матрицы симметрична;
*/


#define MAX_ROWS 10
#define MAX_COLS 10


#include <stdio.h>


//Работа с одномерными массивами
int array_in(int *arr, int len);
int array_out(const int *array, int len);

//Работа с двумерным массивом
int mat_size_in(int *rows, int *columns);
int mat_in(int (*mat)[MAX_COLS], int rows, int columns);
int mat_out(int (*matrix)[MAX_COLS], int rows, int cols);

//Для конкретной лаб. работы
int mat_process(int (*mat)[MAX_COLS], int rows, int columns, int *outarr);
int is_symmetrical(int *row, int len);

int main(void)
{
    int error = 0;
    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };
    int outarr[MAX_ROWS];
    
    int rows, columns = 0;

    error = mat_size_in(&rows, &columns);

    if (!error)
        error = mat_in(matrix, rows, columns);
    
    if (!error)
        error = mat_process(matrix, rows, columns, outarr);

    if (!error)
        error = array_out(outarr, columns);

    if (error)
        printf("Error!\n");

    return error;
}

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
    if (scanf("%d%d", rows, columns) != 2 || *rows <= 0 || *rows > MAX_ROWS || *columns <= 0 || *columns > MAX_COLS)
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

int mat_process(int (*mat)[MAX_COLS], int rows, int columns, int *outarr)
{
    int error = 0;

    for (int i = 0; i < rows && !error; i++)
    {
        int state = is_symmetrical(mat[i], columns);
        outarr[i] = state;
    }

    return error;
}

int is_symmetrical(int *row, int len)
{
    int state = 1;

    int *pend = row + len;

    for (int *pstart = row; pstart < pend - 1; pstart++, pend--)
        if (*pstart != *pend)
            state = 0;
    
    return state;
}