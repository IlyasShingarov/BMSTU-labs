#include <stdlib.h>
#include <check.h>
#include "../inc/errors.h"
#include "../inc/filter.h"

START_TEST(test_key_sorted_arr)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *beg = NULL, *end = NULL;
    int error = key(array, array + strlen(array), &beg, &end);

    ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_key_single_element_array)
{
    int array[] = {1};
    int *beg = NULL, *end = NULL;
    int error = key(array, array + strlen(array), &beg, &end);

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

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_sorted_arr);

    suite_add_tcase(s, tc_pos);

    return s;
}

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