#include "../src/lib.h"
#include <check.h>

START_TEST(test_find_count_words_in_line) {
  // int a[] = {0, 1, 2, 3, 4, 5};
  // int *data_a = &a[0];
  // int data_b = 6;
  char data_a[] = "PFkfeew wepfkw oewofjewf wefwiepfn 113r1 pwinfw pwiefn   "
                  ",,,, qwdq ...  wpefj 1 2 !# *";
  int expected = 8;
  int actual = find_count_words_in_line(data_a);
  ck_assert_int_eq(actual, expected);
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("Lab-09");

  tcase_add_test(tc_core, test_find_count_words_in_line);
  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
