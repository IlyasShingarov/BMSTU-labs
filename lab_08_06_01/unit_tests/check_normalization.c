#include <stdlib.h>
#include <check.h>

#include "../inc/io.h"
#include "../inc/errors.h"
#include "../inc/matrix_normalization.h"

START_TEST(test_delete_columns)
{
    int rows = 2, columns = 4;
    int **matrix = allocate_matrix(rows, columns);
    matrix[0][0] = 1, matrix[0][1] = 2, matrix[0][2] = 3, matrix[0][3] = 4;
    matrix[1][0] = 5, matrix[1][1] = 6, matrix[1][2] = 7, matrix[1][3] = 8;

    int **matrix_res = allocate_matrix(rows, rows);
    matrix_res[0][0] = 3, matrix_res[0][1] = 4;
    matrix_res[1][0] = 7, matrix_res[1][1] = 8;

    squarify_matrix(&matrix, &rows, &columns);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            ck_assert_int_eq(matrix[i][j], matrix_res[i][j]);

    free_matrix(matrix_res, rows);
    free_matrix(matrix, rows);
}
END_TEST

START_TEST(test_delete_rows)
{
    int rows = 4, columns = 2;
    int **matrix = allocate_matrix(rows, columns);
    matrix[0][0] = 1, matrix[0][1] = 2; 
    matrix[1][0] = 3, matrix[1][1] = 4; 
    matrix[2][0] = 5, matrix[2][1] = 6;
    matrix[3][0] = 7, matrix[3][1] = 8;

    int matrix_res[2][2] = { {5, 6}, {7, 8} };

    squarify_matrix(&matrix, &rows, &columns);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            ck_assert_int_eq(matrix[i][j], matrix_res[i][j]);

    free_matrix(matrix, rows);
}
END_TEST

START_TEST(test_equalize)
{
    int rows_a, cols_a, size_a, rows_b, cols_b, size_b;
    cols_a = rows_a = size_a = 3;
    cols_b = rows_b = size_b = 2;
    int **a = allocate_matrix(size_a, size_a);
    a[0][0] = 1, a[0][1] = 2, a[0][2] = 3; 
    a[1][0] = 4, a[1][1] = 5, a[1][2] = 6; 
    a[2][0] = 7, a[2][1] = 8, a[2][2] = 9;

    int **b = allocate_matrix(size_b, size_b);
    b[0][0] = 1, b[0][1] = 2;
    b[1][0] = 3, b[1][1] = 4;

    equalize_matrices(&a, &b, &rows_a, &rows_b, &cols_a, &cols_b);

    ck_assert_int_eq(rows_a, rows_b);
    ck_assert_int_eq(cols_a, cols_b);

    free_matrix(a, rows_a);
    free_matrix(b, rows_b);
}
END_TEST

Suite* normalization_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("normalization");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_delete_columns);
    tcase_add_test(tc_pos, test_delete_rows);
    tcase_add_test(tc_pos, test_equalize);

    suite_add_tcase(s, tc_pos);

    return s;
}
