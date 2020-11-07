#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/io.h"
#include "../inc/errors.h"
#include "../inc/matrix_mutation.h"

int main(void)
{
    int **a = NULL;// **b = NULL;
    int a_rows, a_columns;// b_rows, b_columns;

    int error = read_matrix(&a, &a_rows, &a_columns);
    
    if (!error)
        squarify_matrix(&a, &a_rows, &a_columns);
    /*
    if (!error)
        error = read_matrix(&b, &b_rows, &b_columns);
    */

    if (!error)
    {
        mat_out(a, a_rows, a_columns);
        free_matrix(a, a_rows);
        //mat_out(b, b_rows, b_columns);
    }

    return error;
}
