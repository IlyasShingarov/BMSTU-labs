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

Suite* normalization_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("key");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_delete_columns);

    suite_add_tcase(s, tc_pos);

    return s;
}
