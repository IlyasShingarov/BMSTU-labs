#include <stdlib.h>
#include <check.h>

#include "../inc/io.h"
#include "../inc/errors.h"
#include "../inc/matrix_arithmetic.h"

START_TEST(test_multiply)
{
    int size = 2;

    int **a = allocate_matrix(size, size);
    a[0][0] = 1, a[0][1] = 2; 
    a[1][0] = 3, a[1][1] = 4; 

    int **b = allocate_matrix(size, size);
    b[0][0] = 4, b[0][1] = 3;
    b[1][0] = 2, b[1][1] = 1;

    int **c_res = allocate_matrix(size, size);
    c_res[0][0] = 8, c_res[0][1] = 5;
    c_res[1][0] = 20, c_res[1][1] = 13;

    int **res = muliply_matirices(a, b, size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ck_assert_int_eq(res[i][j], c_res[i][j]);

    free_matrix(a, size);
    free_matrix(b, size);
    free_matrix(res, size);
    free_matrix(c_res, size);
}
END_TEST

START_TEST(test_raise_to_3)
{
    int size = 2;

    int **a = allocate_matrix(size, size);
    a[0][0] = 1, a[0][1] = 2; 
    a[1][0] = 3, a[1][1] = 4; 

    int **res = allocate_matrix(size, size);
    res[0][0] = 37, res[0][1] = 54;
    res[1][0] = 81, res[1][1] = 118;

    raise_matrix_to_power(a, size, 3);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ck_assert_int_eq(a[i][j], res[i][j]);

    free_matrix(a, size);
    free_matrix(res, size);
}
END_TEST

START_TEST(test_raise_to_0)
{
    int size = 2;

    int **a = allocate_matrix(size, size);
    a[0][0] = 1, a[0][1] = 2; 
    a[1][0] = 3, a[1][1] = 4; 

    int **res = allocate_matrix(size, size);
    res[0][0] = 1, res[0][1] = 0;
    res[1][0] = 0, res[1][1] = 1;

    raise_matrix_to_power(a, size, 0);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
                ck_assert_int_eq(a[i][j], res[i][j]);

    free_matrix(a, size);
    free_matrix(res, size);
}
END_TEST

Suite* arithmetics_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("key");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multiply);
    tcase_add_test(tc_pos, test_raise_to_3);
    tcase_add_test(tc_pos, test_raise_to_0);

    suite_add_tcase(s, tc_pos);

    return s;
}