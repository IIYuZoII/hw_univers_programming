#include "../src/lib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_get_matrix_transponent) {

  float **matrix = NULL;
  float **matrix_transparent = NULL;

  unsigned i, j, rows = 2, columns = 3;

  int temp = 0;

  matrix = (float **)malloc(rows * sizeof(float *));
  for (i = 0; i < rows; i++) {
    *(matrix + i) = (float *)malloc(columns * sizeof(float));
    for (j = 0; j < columns; j++) {
      *(*(matrix + i) + j) = (float)temp;
      temp++;
    }
  }

  matrix_transparent = (float **)malloc(columns * sizeof(float *));
  for (i = 0; i < columns; i++) {
    *(matrix_transparent + i) = (float *)malloc(rows * sizeof(float));
  }

  temp = 0;
  int expected[] = {0, 3, 1, 4, 2, 5};
  float actual = 0;

  get_matrix_transponent(matrix, matrix_transparent, rows, columns);

  for (i = 0; i < columns; i++) {
    for (j = 0; j < rows; j++) {
      actual = *(*(matrix_transparent + i) + j);
      ck_assert_int_eq(actual, expected[temp]);
      temp++;
    }
  }
}
END_TEST

START_TEST(test_randomizer) {

  float max = 1000, min = -1000;
  int actual = 0;
  int expected[] = {0, 0};
  for (int i = 0; i < 2; i++) {
    if (randomizer(max, min, i) < 0 && i == 0) {
      actual = 1;
    } else if (randomizer(max, min, i) > 0 && i == 1) {
      actual = 1;
    }
    ck_assert_int_eq(actual, expected[i]);
  }
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("Lab-11");

  tcase_add_test(tc_core, test_get_matrix_transponent);
  tcase_add_test(tc_core, test_randomizer);
  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
