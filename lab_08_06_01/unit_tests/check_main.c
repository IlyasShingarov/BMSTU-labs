#include <stdlib.h>
#include <check.h>

#include "../inc/check_arithmetics.h"
#include "../inc/check_normalization.h"


int main(void)
{
    int no_failed = 0;
   
    Suite *s_1 = normalization_suite();
    SRunner *runner_1 = srunner_create(s_1);
    srunner_run_all(runner_1, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner_1);
    srunner_free(runner_1);

    Suite *s_2 = arithmetics_suite();
    SRunner *runner_2 = srunner_create(s_2);
    srunner_run_all(runner_2, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner_2);
    srunner_free(runner_2);


    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
