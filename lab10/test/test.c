#include "../src/lib.h"
#include <check.h> 
#include <stdlib.h>

START_TEST(test_get_count) { 
    int *a = NULL;
    int *r = NULL;

    int actual = 0;
    int expected[] = {2, 5, 3, 4};

    unsigned v_f_c, i, size = 9;

    a = (int *)malloc(size * sizeof(int));
    r = (int *)malloc(128);

    for (i = 0; i < size; i++){
        if (i % 2 == 0){
            *(a + i) = 2;
        } else {
            *(a + i) = 3;
        }
    }

    get_count(a, size, r, &v_f_c);

    

    for (i = 0; i < v_f_c; i++){
        actual = *(r + i);
        ck_assert_int_eq(actual, expected[i]);
    }

    } 
END_TEST 

int main(void) 
{ 
	Suite *s = suite_create("Programing"); 
	TCase *tc_core = tcase_create("Lab-010"); 
	
	tcase_add_test(tc_core, test_get_count);
	suite_add_tcase(s, tc_core); 
	
	SRunner *sr = srunner_create(s); 
	srunner_run_all(sr, CK_VERBOSE); 
	int number_failed = srunner_ntests_failed(sr); 
	srunner_free(sr); 
	
	return (number_failed == 0) ? 0 : 1; 
}
