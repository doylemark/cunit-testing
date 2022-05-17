#include <stdio.h>

#include "CUnit.h"
#include "Basic.h"

#include "src/avg_and_max.h"


void test_max()
{
    // base case
    CU_ASSERT(max((double[]){3, 2, 1}, 3) == 3);
    // one negative
    CU_ASSERT(max((double[]){-1, 0, 2}, 3) == 2);
    // all negative (fails)
    CU_ASSERT(max((double[]){-1, -10, -15}, 3) == -1);
    // all same value
    CU_ASSERT(max((double[]){1, 1}, 2) == 1);
    // all zero
    CU_ASSERT(max((double[]){0, 0, 0}, 3) == 0);

}

int main() 
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("test_max", 0, 0);

    CU_add_test(suite, "test_max", test_max);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    printf("%lf", max((double[]){0, 0, 0}, 3));
    return 0;
}