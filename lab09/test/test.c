#include "lib.h"
#include <check.h> 


START_TEST(test_sum) { 
	int data_a = 5; 
	int data_b = 9; 
	int expected = 13; /* don't use 4+9 */ 
	int actual = sum(data_a, data_b); ck_assert_int_eq(actual, expected); } 
END_TEST 
// test.c (continuation) 
int main(void) 
{ 
	Suite *s = suite_create("Programing"); 
	TCase *tc_core = tcase_create("Lab-09"); 
	
	tcase_add_test(tc_core, test_sum); /* test_sum - method we created */ 
	suite_add_tcase(s, tc_core); 
	
	SRunner *sr = srunner_create(s); 
	srunner_run_all(sr, CK_VERBOSE); 
	int number_failed = srunner_ntests_failed(sr); 
	srunner_free(sr); 
	
	return (number_failed == 0) ? 0 : 1; 
}
