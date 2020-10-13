#include <stdlib.h>
#include <check.h>
#include "../inc/errors.h"
#include "../inc/filter.h"

START_TEST(test_key_sorted_arr)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int res[] = {2, 3, 4, 5, 6, 7, 8};
    int *beg = NULL, *end = NULL;
    int error = key(array, array + 9, &beg, &end);

    ck_assert_int_eq(end - beg, 7);
    for (int i = 0; i < 7; i++)
        ck_assert_int_eq(*(beg + i), res[i]);
    ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_key_reverse_sorted_arr)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int res[] = {8, 7, 6, 5, 4, 3, 2};

    int *beg = NULL, *end = NULL;
    int error = key(array, array + 9, &beg, &end);
    
    ck_assert_int_eq(end - beg, 7);
    for (int i = 0; i < 7; i++)
        ck_assert_int_eq(*(beg + i), res[i]);
    ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_key_multiple_max_min_elems)
{
    int array[] = {4, 5, 1, 1, 3, 5, 7, 9, 9};
    int res[] = {1, 3, 5, 7};

    int *beg = NULL, *end = NULL;
    int error = key(array, array + 9, &beg, &end);
    
    ck_assert_int_eq(end - beg, 4);
    for (int i = 0; i < 4; i++)
        ck_assert_int_eq(*(beg + i), res[i]);
    ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_key_single_element_array)
{
    int array[] = {1};
    int *beg = NULL, *end = NULL;
    int error = key(array, array + 1, &beg, &end);

    ck_assert_int_eq(error, ELEM_COUNT_ERR);
}
END_TEST

START_TEST(test_key_two_element_array)
{
    int array[] = {1, 2};
    int *beg = NULL, *end = NULL;
    int error = key(array, array + 2, &beg, &end);

    ck_assert_int_eq(error, ELEM_COUNT_ERR);
}
END_TEST

START_TEST(test_key_same_element_array)
{
    int array[] = {1, 1, 1, 1, 1, 1, 1};
    int *beg = NULL, *end = NULL;
    int error = key(array, array + 7, &beg, &end);

    ck_assert_int_eq(error, ELEM_COUNT_ERR);
}
END_TEST

START_TEST(test_key_no_elements_between_max_and_min)
{
    int array[] = {4, 5, 6, 1, 9, 7, 4, 3, 2};
    int *beg = NULL, *end = NULL;
    int error = key(array, array + 9, &beg, &end);

    ck_assert_int_eq(error, ELEM_COUNT_ERR);
}
END_TEST

Suite* key_filter_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;
    
    s = suite_create("key");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_key_single_element_array);
    tcase_add_test(tc_neg, test_key_two_element_array);
    tcase_add_test(tc_neg, test_key_same_element_array);
    tcase_add_test(tc_neg, test_key_no_elements_between_max_and_min);
    
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_sorted_arr);
    tcase_add_test(tc_pos, test_key_reverse_sorted_arr);
    tcase_add_test(tc_pos, test_key_multiple_max_min_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}

/*
int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = key_filter_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
*/