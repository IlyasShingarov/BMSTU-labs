#include <stdlib.h>
#include <string.h>

#include "../inc/io.h"
#include "../inc/errors.h"
#include "../inc/matrix_normalization.h"
#include "../inc/matrix_arithmetic.h"

int main(void)
{
    int **a = NULL;// **b = NULL;
    int a_rows, a_columns; //b_rows, b_columns;

    int error = read_matrix(&a, &a_rows, &a_columns);
    //if (!error)
    //    error = read_matrix(&b, &b_rows, &b_columns);
     
    if (!error)
    {
        error = squarify_matrix(&a, &a_rows, &a_columns);
    //    error = squarify_matrix(&b, &b_rows, &b_columns);
    }
        
    //if (!error)
    //    error = equalize_matrices(&a, &b, &a_rows, &b_rows, &a_columns, &b_columns);

    if (!error)
    {
        raise_matrix_to_power(a, a_rows, 4);
        mat_out(a, a_rows, a_columns);
        //mat_out(b, b_rows, b_columns);

        free_matrix(a, a_rows);
        //free_matrix(b, b_rows);
    }

    return error;
}
