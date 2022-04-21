#include "lib.h"
#include <check.h>

START_TEST(get_count) {
  int data_a[] = {5, 4, 4, 3, 3, 2};
  int data_b = 6;
  int expected = 3;
  int actual = get_count(data_a, data_b);
  ck_assert_int_eq(actual, expected);
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("Lab-09");

  tcase_add_test(tc_core, get_count);
  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}