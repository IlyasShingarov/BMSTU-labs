#include <stdlib.h>

#include "../inc/io.h"
#include "../inc/errors.h"

// Complementary function assuming matrix is square
void copy_matrix(int **src, int **dst, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            dst[i][j] = src[i][j];
}

// Assuming sizes are equal and matrices are square according to the task
void multiplication(int **a, int **b, int **r, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            r[i][j] = 0;
            for (int k = 0; k < size; k++)
                r[i][j] += a[i][k] * b[k][j];
        }
}

// Assuming sizes are equal and matrices are square according to the task
int **muliply_matirices(int **a, int **b, int size)
{
    int **result = allocate_matrix(size, size);
    if (result)
        multiplication(a, b, result, size);
    else
        result = NULL;

    return result;
}

void raise(int **a, int **a_, int **a__, int size)
{
    copy_matrix(a, a__, size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            a[i][j] = 0;
            for (int k = 0; k < size; k++)
                a[i][j] += a__[i][k] * a_[k][j];
        }
}

void raise_to_zeroth(int **a, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
            
}

// Assuming matrix is square
void raise_matrix_to_power(int **a, int size, int power)
{   
    if (power == 0)
        raise_to_zeroth(a, size);

    int **a_ = allocate_matrix(size, size);
    int **a__ = allocate_matrix(size, size);
    copy_matrix(a, a_, size);

    for (int i = 1; i < power; i++)
        raise(a, a_, a__, size);

    free_matrix(a_, size);
    free_matrix(a__, size);
}