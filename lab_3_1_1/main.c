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
void array_out(const int *array, int len);

//Работа с двумерным массивом
void transform(int **a, int *buffer, int n, int m);
int mat_in(int **a, int *n, int *m);
//Для конкретной лаб. работы
void mat_process(int **mat, int rows, int columns, int *outarr);
int is_symmetrical(int *row, int len);

int main(void)
{
    int error = 0;

    int rows, columns;
    int *matrix[MAX_ROWS];
    int buffer[MAX_ROWS][MAX_COLS];
    
    int outarr[MAX_ROWS] = { 0 };

    transform(matrix, *buffer, MAX_ROWS, MAX_COLS);

    error = mat_in(matrix, &rows, &columns);
    
    if (!error)
    {
        mat_process(matrix, rows, columns, outarr);
        array_out(outarr, rows);
    }

    if (error)
        printf("Error!\n");

    return error;
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
    if (scanf("%d%d", n, m) != 2 || *n < 1 || *n > MAX_ROWS || *m < 1 || *m > MAX_COLS)
        error = 1;

    for (int i = 0; i < *n && !error; i++)
        for (int j = 0; j < *m && !error; j++)
            if (scanf("%d", *(a + i) + j) != 1)
                error = 1;

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

void mat_process(int **mat, int rows, int columns, int *outarr)
{
    for (int i = 0; i < rows; i++)
    {
        int state = is_symmetrical(mat[i], columns);
        outarr[i] = state;
    }
}

int is_symmetrical(int *row, int len)
{
    int state = 1;

    int *pend = row + len - 1;

    for (int *pstart = row; pstart < pend; pstart++, pend--)
        if (*pstart != *pend)
            state = 0;
    
    return state;
}

