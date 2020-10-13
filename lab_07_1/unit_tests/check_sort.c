#include <stdlib.h>
#include <check.h>
#include "../inc/errors.h"
#include "../inc/sort.h"

START_TEST(test_sort_sorted_arr)
{
    int array_sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    mysort(array, 9, sizeof(int), int_cmp);
    for (int i = 0; i < 9; i++)
        ck_assert_int_eq(array[i], array_sorted[i]);
}
END_TEST

START_TEST(test_sort_reverse_arr)
{
    int array_sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    mysort(array, 9, sizeof(int), int_cmp);
    for (int i = 0; i < 9; i++)
        ck_assert_int_eq(array[i], array_sorted[i]);
}
END_TEST

START_TEST(test_sort_single_element_arr)
{
    int array_sorted[] = {1};

    int array[] = {1};
    mysort(array, 1, sizeof(int), int_cmp);
    for (int i = 0; i < 1; i++)
        ck_assert_int_eq(array[i], array_sorted[i]);
}
END_TEST

START_TEST(test_sort_random_arr)
{
    int array_sorted[] = {1, 3, 3, 6, 8};

    int array[] = {6, 3, 8, 3, 1};
    mysort(array, 5, sizeof(int), int_cmp);
    for (int i = 0; i < 5; i++)
        ck_assert_int_eq(array[i], array_sorted[i]);
}
END_TEST

START_TEST(test_sort_empty_arr)
{
    int *array_sorted = NULL;

    int *array = NULL;
    mysort(array, 0, sizeof(int), int_cmp);
    for (int i = 0; i < 0; i++)
        ck_assert_int_eq(array[i], array_sorted[i]);
}
END_TEST

START_TEST(test_sort_negative_elements_arr)
{
    int array_sorted[] = {-7, -2, -1, 1, 2, 3, 4, 5, 8};

    int array[] = {-1, 8, -7, -2, 5, 4, 3, 2, 1};
    mysort(array, 9, sizeof(int), int_cmp);
    for (int i = 0; i < 9; i++)
        ck_assert_int_eq(array[i], array_sorted[i]);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("key");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_sorted_arr);
    tcase_add_test(tc_pos, test_sort_reverse_arr);
    tcase_add_test(tc_pos, test_sort_single_element_arr);
    tcase_add_test(tc_pos, test_sort_random_arr);
    tcase_add_test(tc_pos, test_sort_negative_elements_arr);
    tcase_add_test(tc_pos, test_sort_empty_arr); 

    suite_add_tcase(s, tc_pos);

    return s;
}

/*
int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = mysort_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
*/