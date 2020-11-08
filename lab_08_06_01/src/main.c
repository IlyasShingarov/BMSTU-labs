#include <stdlib.h>
#include <string.h>

#include "../inc/io.h"
#include "../inc/errors.h"
#include "../inc/matrix_normalization.h"
#include "../inc/matrix_arithmetic.h"

int main(void)
{
    int **a = NULL, **b = NULL;
    int a_rows, a_columns, b_rows, b_columns;

    int error = read_matrix(&a, &a_rows, &a_columns);
    if (!error)
        error = read_matrix(&b, &b_rows, &b_columns);
     
    if (!error)
    {
        error = squarify_matrix(&a, &a_rows, &a_columns);
        error = squarify_matrix(&b, &b_rows, &b_columns);
    }
        
    if (!error)
        error = equalize_matrices(&a, &b, &a_rows, &b_rows, &a_columns, &b_columns);

    // Assuming that sizes are rqual at that point
    int size = a_rows, ro, gamma;
    if (!error && !read_powers(&ro, &gamma))
    {
        raise_matrix_to_power(a, size, ro);
        raise_matrix_to_power(b, size, gamma);

        print_matrix(a, size, size);
        print_matrix(b, size, size);

        int **result = muliply_matirices(a, b, size);

        print_matrix(result, size, size);

        free_matrix(result, size);
    }

    if (a)
        free_matrix(a, a_rows);
    if (b)
        free_matrix(b, b_rows);

    return error;
}
